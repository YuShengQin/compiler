/*
 * Example with Functions
 */

object FOR {
  var a = 5
  var kk = 1
  var h : float = 2.6
  var d : float = 1.1
  // function declaration
 /* def add (a: int, b: int) : int
  {
    return a+b
  }*/
  def add (a: float, b: float) : float
  {
    if(true)
    	return a
    else 
	return b
  }
  // main statements
  def main ()
  {
    var c : int
    var b : float = 1.5

   // h = h - b
   // c = add(a, 10)
    b = add(d, 1.5)
  /*  for(a <- 2 to 8){
	println a
	a = a + 1
    }*/
   
    println b
    println ("Hello World")
  }
}
