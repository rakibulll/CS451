// **********************************************
// Program1: Temperature calculation
// Course: CS451
// Student Name: Rakibul Hassan
// Instructor: Dr. Il-Hyung Cho
// Date of submission: 02/06/2023
// Program Description: This is a program written in C that analyzes temperature data for multiple years and multiple months. 
// It reads data from a file specified by the user and calculates the average temperature of each year and month, as well as 
// the coldest and hottest months for each year. Finally, it outputs the results, including the year, average temperature,
// coldest and hottest months, and average temperature for each month. The program uses a 2D array to store the temperature data.
// **********************************************

#include <stdio.h>
#include <string.h>

#define MONTHS 12 // number of months in a year
#define MAX_NAME_LEN 20 // maximum length of a month name
#define MAX_FILE_NAME_LEN 30 // maximum length of the file name


int main() {
    // array of month names, used to display the month names in the output
    char month_names[MONTHS][MAX_NAME_LEN] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int years, year, i, j;
    // 2D array to store the temperatures for each year and month
    float temperatures[MAX_FILE_NAME_LEN][MONTHS];
    float year_average, year_total; // variables to store the average temperature of a year and the total temperature of a year
    float month_average[MONTHS], month_total[MONTHS]; // arrays to store the average temperature of each month and the total temperature of each month for all years
    int coldest_month, hottest_month; // variables to store the index of the coldest and hottest months of a year
    char file_name[MAX_FILE_NAME_LEN]; // variable to store the name of the file containing the temperatures
    FILE *file; // file pointer to open the file containing the temperatures

    // initialize the arrays storing the total temperatures to 0
    memset(month_average, 0, sizeof(month_average));
    memset(month_total, 0, sizeof(month_total));

    printf("Enter temperature file name: ");
    scanf("%s", file_name); // read the name of the file from the user

    file = fopen(file_name, "r"); // open the file in read mode
    if (file == NULL) {
        printf("Error opening file\n"); // print an error message if the file could not be opened
        return 1;
    }
    
    // print year, average, coldest month and hotest month heading
    printf("\n");
    printf(" %s    %s    %s   %s \n", "Year", "Average", "Coldest Month", "Hotest Month");
    printf(" %s    %s    %s   %s \n", "====", "=======", "=============", "============");

    fscanf(file, "%d", &years); // read the number of years from the file
    for (i = 0; i < years; i++) {
        year_total = 0; // reset the total temperature for the year to 0
        fscanf(file, "%d", &year); // read the year from the file
        for (j = 0; j < MONTHS; j++) {
            fscanf(file, "%f", &temperatures[i][j]); // read the temperature for the month from the file
            year_total += temperatures[i][j]; // add the temperature to the total temperature for the year
            month_total[j] += temperatures[i][j]; // add the temperature to the total temperature for the month for all years
        }
        year_average = year_total / MONTHS; // calculate the average temperature of the year

        // initialize the coldest and hottest months to the first month
        coldest_month = 0;
        hottest_month = 0;
        // loop through the remaining months
        for (j = 1; j < MONTHS; j++) {
            // if the temperature of the current month is lower than the temperature of the coldest month so far, update the coldest
            if (temperatures[i][j] < temperatures[i][coldest_month]) {
                coldest_month = j;
            }
            // if the temperature of the current month is higher than the temperature of the hottest month so far, update the hottest month
            if (temperatures[i][j] > temperatures[i][hottest_month]) {
                hottest_month = j;
            }
        }
        // print the year, average temperature, coldest month and its temperature, and hottest month and its temperature
        printf(" %d    %.1f\t    %s(% .1f)\t    %s (% .1f)\n", year, year_average, month_names[coldest_month], temperatures[i][coldest_month], month_names[hottest_month], temperatures[i][hottest_month]);
    }
    // print the header for the average temperature of each month
    printf("\nAverage temperature\n");
    // calculate the average temperature of each month for all years
    for (i = 0; i < MONTHS; i++) {
        month_average[i] = month_total[i] / years;
        // print the average temperature of the month
        printf("%s\t", month_names[i]);
    }
    printf("\n");
    for (i = 0; i < MONTHS; i++) {
        printf("%.1f\t", month_average[i]);
    }
    printf("\n");

    fclose(file); // close the file
    return 0;
}
