template<size_t Rows, size_t Cols, typename T = int>
class Matrix
{
private:
	T matrix[Rows][Cols]; // Awesome thing about using templates: The compiler handles deducing this. This can impact runtime preformance VERY positively.
public:
	/* No default constructor - We need to use arrays of values
	 * 	I'll be honest: I'm not a big fan of this method 100: It basically guarantees we need to create an array
	 * 	just to create a matrix and we then copy those values. As long as we're utilizing the stack, however,
	 * 	this lessens the impact on processing (also prevent memory leaks).
	 */
	Matrix(const T (&arr)[Rows][Cols])
	{
		// Unlike using double pointers, 2d arrays are GUARANTEED to be stored contiguously
		// I also think this would make an excellent candidate for a ptr_unique for a runtime solution!
		memcpy(&matrix, &arr, sizeof(T) * Rows * Cols);
	}

	~Matrix()
	{
	}
	
	/* This gets the value at matrix[row][col] */
	int at(unsigned row, unsigned col) const
	{
		assert(row >= 0 && row < Rows); // 'row' has to be within the range of rows
		assert(col >= 0 && col < Cols); // 'col' has to be within the range of columns
		return matrix[row][col];
	}
	
	/* Print out the matrix in row>col format */
	void print()
	{
		std::cout << "[" << std::endl;
		for (unsigned row = 0; row < Rows; row++)
		{
			std::cout << "\t[ ";
			for (unsigned col = 0; col < Cols-1; col++)
				std::cout << matrix[row][col] << ", ";
			std::cout << matrix[row][Cols-1] << " ]" << std::endl;
		}
		std::cout << "]" << std::endl;
	}
	
	/* A<N1,M1>(this) * B<N2,M2>(matrix2) = C<N1,M2> : Returns value of matrix C */
	template<size_t Rows2, size_t Cols2>
	Matrix<Rows,Cols2, T> dot_product(Matrix<Rows2,Cols2,T> matrix2)
	{
		assert(Rows == Cols2); // For the dot product, # Matrix 1 rows MUST equal # Matrix 2 cols

		T dotProduct[Rows][Cols2];
		for (unsigned row = 0; row < Rows; row++) // For every row of the lhs Matrix
		{
			for (unsigned col = 0; col < Cols2; col++) // For every column of the rhs Matrix
			{
				T product = 0;
				for (unsigned i = 0; i < Cols; i++) // And finally, for every column of the current row...
					product += at(row, i) * matrix2.at(i, col);
				dotProduct[row][col] = product;
			}
		}

		Matrix<Rows,Cols2,T> m(dotProduct);
		return m;
	}
};
