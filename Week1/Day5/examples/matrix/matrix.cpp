/* Multiply Two Matrices (DOT PRODUCT) */
// Matrix elements are to be int type
// C = A x B
// 	Where A is a matrix, B is a matrix, C is the dot product which is a matrix.
// A =	[1 2 3] 
//	[4 5 6]
//
// B =	[07 08]
// 	[09 10]
// 	[11 12]
//
// We MULTIPLY A's Rows and B's Columns:
// 	FIRST by A's 1st Row and B's first Column
// 	[(1*7 + 2*9 + 3*11) = (7 + 18 + 33) = (58)]
//
// 	THEN by A's 1st Row and B's second Column
// 	[(1*8 + 2*10 + 3 *12) = (8 + 20 + 36) = (64)]
//
// 	THEN SHIFT DOWN A ROW.
//
// 	THEN by A's 2nd Row and B's first Column
// 	[(4*7 + 5*9 + 6*11) = (28 + 45 + 66) = (139)]
//
// 	THEN by A's 2nd Row and B's second Column
// 	[(4*8 + 5*10 + 6*12) = (32 + 50 + 72) = (154)]
//
// C =	[058 064]
// 	[139 154]
//
// NOTES
// Matrix Dimensions
// 	Multiplying a 3x2 and 2x3 yields a 2x2
// 	Multiplying a 3x3 and 3x3 yields a 3x3
// 	Multiplying a 2x3 and 3x2 yields a 3x3
// 		X Dimension Depth = # of B columns
//		Y Dimension Depth = # of A rows
//	cMatrix[B.cols][A.rows]

#include <iostream>
#include <cstring>
#include <cassert>
#include "matrix.hpp"

int main(void)
{
	// Let's create some templates for our matrices using int arrays! //
	int arr1[3][2] = // 3x2
	{
		{1, 2},
		{3, 4},
		{5, 6}
	};
	int arr2[2][3] = // 2x3
	{
		{5, 6, 7}, 
		{7, 8, 9}
	};
	int arr3[1][4] = // 1x4
	{
		{1, 2, 3, 4}
	};
	int arr4[4][1] = // 4x1
	{ 
		{1,}, 
		{5,}, 
		{9,},
		{13,},
	};

	/* Multiplication */
	std::cout << "Matrix A:" << std::endl;
	Matrix a(arr1); // We instantiate a matrix using arrays!
	a.print();
	std::cout << "Matrix B:" << std::endl;
	Matrix b(arr2);
	b.print();
	
	std::cout << "Matrix A x B:" << std::endl;
	Matrix c = a.dot_product(b);
	c.print();

	// This should error because we can only multiply two matrices of similar height and width.
	//Matrix m1(arr3);
	//Matrix err = a.dot_product(m1); // Assert fails, matrix a's rows not equal to matrix m1's cols.
	
	std::cout << "\n\n\n\n\n\n"; // Just flushing the buffer a bit...

	// Let's make Matrix D using the values in arr3.
	std::cout << "Matrix D:" << std::endl;
	Matrix d(arr3);
	d.print();
	// Matrix e using the values in arr4...
	std::cout << "Matrix E:" << std::endl;
	Matrix e(arr4);
	e.print();
	std::cout << "Matrix D x E:" << std::endl;
	Matrix dot_de = d.dot_product(e);

	dot_de.print();
	
	// Final example:
	// 	Let's square a matrix (Full disclosure: I have no idea what squaring a matrix actually is or if it's a real concept)
	int arrA[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int arrB[3][3];
	memcpy(&arrB, &arrA, sizeof(int) * 3 * 3);
	Matrix matA(arrA);
	Matrix matB(arrB);
	std::cout << "Matrix to Square:" << std::endl;
	matA.print();
	
	std::cout << "Matrix Squared:" << std::endl;
	Matrix dotAB = matA.dot_product(matB);
	dotAB.print();

	return 0;
}
