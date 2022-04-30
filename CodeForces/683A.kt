import java.util.Scanner
fun main() {
	val scanner = Scanner(System.`in`)
	val a : Int = scanner.nextInt()
	val x : Int = scanner.nextInt()
	val y : Int = scanner.nextInt()
	if((0 <= x && x <= a && (y == 0 || y == a)) ||
	   (0 <= y && y <= a && (x == 0 || x == a)))
		println("1")
	else if(0 < x && x < a && 0 < y && y < a)
		println("0")
	else
		println("2")
}