package test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import main.MainClass;

class TestClass {

	@Test
	public void main() {
		MainClass test = new MainClass();
		assertEquals("EQUILATERAL",test.triangle(12, 12, 12));
		assertEquals("ISOSCELENES",test.triangle(12, 12, 11));
		assertEquals("SCELENE",test.triangle(10, 12, 15));
		assertEquals("invalid input",test.triangle(0, 0, 0));
		//assertEquals("EQUILATERAL", test.triangle(3, 3, 3));
	}
	/*void test() {
		fail("Not yet implemented");
	}*/
	

}
