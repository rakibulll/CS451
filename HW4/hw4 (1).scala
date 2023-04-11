import scala.annotation.tailrec

@main def m() =
  // checking for member
  // [[HW1: (10 pts) complete the member function
  def member(a: Int, b: List[Int]): Boolean = {
    
   
  
  }

  val l4 = List(1, 2, 3, 4)
  println("#1")
  println(member(2, l4))
  println(member(5, l4))
  // HW1]]

  // [[HW2: (10 pts) complete the list equality function
  // Assume that list of chars are passed as parameters
  val l1 = List('A', 'B', 'C', 'D')
  val l2 = List('A', 'C', 'D')
  val l3 = List('A', 'C', 'D')

  def equalsimp(a: List[Char], b: List[Char]): Boolean = {
    
   
  
 
  }
  println("#2")
  println(equalsimp(l1, l2))
  println(equalsimp(l3, l2))
  println(equalsimp(l3, List('D', 'A'. 'C')))
  println(equalsimp(l1, List('D', 'A'. 'C', 'B')))
  println

  // HW2]]

  // [[HW3: (10 pts) Complete the append function
  def append[A](l1: List[A], l2: List[A]): List[A] = {



  }
  println("#3")
  println(append(l1, l2))
  println(append(l3, l1))

  val l4 = List(1, 2, 3, 4)
  val l5 = List(10, 11)
  println(append(l4, l7))
  // HW3]]

  // [[HW4: (10 pts) Complete the quadratic_roots function
  // hint: for square root, you can call math.sqrt() function
  def quadratic_roots(a: Int, b: Int, c: Int) = {
    val root_part = 
    val minus_b = 

    List(minus_b + root_part, minus_b - root_part)
  }

  println("#4")
  println(quadratic_roots(1, -2, -3))
  // HW4]]

  // [[HW5: (10 pts) Complete the factorial functin using recursion
  def factorial(n: Int): BigInt =
    
   

  println("#5")
  println(factorial(10))
  println(factorial(10000)) // Stack Overflow
  // HW5]]

  // [[HW6: (10 pts) Complete the factorial function with tail recursion
  def factHelper(n: Int, factPartial: BigInt): BigInt =
    
   

  def tailFactorial(n: Int): BigInt =
    

  println("#6")
  println(tailFactorial(10000)) // much faster and no stack overflow
  // HW6]]


  // Function composition
  def h[A, B, C](f: B => C, g: A => B): A => C =
    x => f(g(x))

  val add2 = (x: Int) => x + 2
  val times3 = (x: Int) => x * 3
  println("#7")
  println(h(add2, times3)(4))

  // [[HW8: (10 pts) Complete the third_list function
  def third_list[A](ls: List[A]): A = 
    
  
  val l1 = List(1, 2, 3, 4)
  println("#8")
  println(third_list(l1))
  println(third_list(List(1,2,(3,4,5), 6, 7)))
  // HW8]]

  // [[HW9: (20 pts) Complete the nth_list function
  // this function returns the nth element in the list
  def nth_list[A](n: Int, ls: List[A]): A = {



  }
  println("#9")
  println(nth_list(2, l1))
  println(nth_list(2, List(1,2,(3,4,5), 6, 7)))
  // HW9]]
