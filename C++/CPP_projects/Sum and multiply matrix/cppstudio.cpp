#include <iostream>

int main()
{
	

	char ent = 's';
	std::cout << "Do you want to sum or to multiply ? (s/m) ";
	std::cin >> ent;

	if (ent == 's')
	{
		int row;
		int col;
		std::cout << "enter size of matrixs " << std::endl;
		std::cout << "row = ";
		std::cin >> row;
		std::cout << "col = ";
		std::cin >> col;

		std::cout << "enter numbers of first matrix " << std::endl;
		int** matrix = new int* [row];
		for (int i = 0; i < row; ++i)
		{
			matrix[i] = new int[col];
			for (int j = 0; j < col; ++j)
			{
				std::cin >> matrix[i][j];
			}
		}

		std::cout << "enter numbers of second matrix " << std::endl;
		int** matrix1 = new int* [row];
		for (int i = 0; i < row; ++i)
		{
			matrix1[i] = new int[col];
			for (int j = 0; j < col; ++j)
			{
				std::cin >> matrix1[i][j];
			}
		}

		for (int i = 0; i < row; ++i)
		{
			std::cout << '\t';
			for (int j = 0; j < col; ++j)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
		std::cout << '\t' << "+" << std::endl;	
		std::cout << std::endl;

		for (int i = 0; i < row; ++i)
		{
			std::cout << '\t';
			for (int j = 0; j < col; ++j)
			{
				std::cout << matrix1[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << "this is sum of this matrix " << std::endl;
		for (int i = 0; i < row; ++i)
		{
			std::cout << '\t';
			for (int j = 0; j < col; ++j)
			{
				std::cout << matrix[i][j] + matrix1[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else if (ent == 'm')
	{
		int row;
		int col;
		std::cout << "enter size of matrixs " << std::endl;
		std::cout << "row = ";
		std::cin >> row;
		std::cout << "col = ";
		std::cin >> col;

		std::cout << "enter numbers of first matrix " << std::endl;
		int** matrix = new int* [row];
		for (int i = 0; i < row; ++i)
		{
			matrix[i] = new int[col];
			for (int j = 0; j < col; ++j)
			{
				std::cin >> matrix[i][j];
			}
		}

		std::cout << "enter numbers of second matrix " << std::endl;
		int** matrix1 = new int* [col];
		for (int i = 0; i < col; ++i)
		{
			matrix1[i] = new int[row];
			for (int j = 0; j < row; ++j)
			{
				std::cin >> matrix1[i][j];
			}
		}

		for (int i = 0; i < row; ++i)
		{
			std::cout << '\t';
			for (int j = 0; j < col; ++j)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
		std::cout << '\t' << "*" << std::endl;
		std::cout << std::endl;

		for (int i = 0; i < col; ++i)
		{
			std::cout << '\t';
			for (int j = 0; j < row; ++j)
			{
				std::cout << matrix1[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		int mul = 0;
		std::cout << "this is multipy of this matrix " << std::endl;
		for (int k = 0; k < row; ++k)
		{
			std::cout << '\t';
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					mul = mul + (matrix[k][j] * matrix1[j][i]);

				}
				std::cout << mul << " ";
				mul = 0;
			}
			std::cout << std::endl;
		}
	
	
	}
	else
	{
	  std::cout << "You entered an incorrect letter " << std::endl;
    }
	

}