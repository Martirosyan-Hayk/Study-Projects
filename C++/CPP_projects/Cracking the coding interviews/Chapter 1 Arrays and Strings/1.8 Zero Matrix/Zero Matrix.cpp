#include <iostream>
#include <string>

void cin_matrix(int&, int&, int**&);
void cout_matrix(int&, int&, int**&);
void delete_matrix(int&, int&, int**&);
void null_row(int&, int&, int**&);
void null_colum(int&, int&, int**&);
void zero_matrix(int&, int&, int**&);


int main()
{
    int r, c;
    std::cout << "Enter matrix size " << std::endl;
    std::cout << "Enter rows size ";
    std::cin >> r;
    std::cout << "Enter colums size ";
    std::cin >> c;
    int** matrix;
    std::cout << "Enter matrix numbers ";
    cin_matrix(r, c, matrix);
    cout_matrix(r, c, matrix);
    zero_matrix(r, c, matrix);
    cout_matrix(r, c, matrix);

    delete_matrix(r, c, matrix);
	return 0;
}

void cin_matrix(int& row, int& colum, int**& matrix)
{
    matrix = new int* [row];
    for (int i = 0; i < row; ++i)
    {
        matrix[i] = new int[colum];
        for (int j = 0; j < colum; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}
void cout_matrix(int& row, int& colum, int**& matrix)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < colum; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void delete_matrix(int& row, int& colum, int**& matrix)
{
    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}
void null_row(int& row, int& colum, int**& matrix)
{
    if (row == -1)
        return;
    for (int j = 0; j < colum; ++j) {
        matrix[row][j] = 0;
    }
}
void null_colum(int& row, int& colum, int**& matrix)
{
    if (colum == -1)
        return;
    for (int i = 0; i < row; ++i) {
        matrix[i][colum] = 0;
    }
}
void zero_matrix(int& row, int& colum, int**& matrix)
{
    int r = -1;
    int c = -1;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < colum; ++j)
        {
            if (matrix[i][j] == 0)
            {
                r = i;
                c = j;
                break;
            }
        }
    }
    null_row(r, colum, matrix);
    null_colum(row, c, matrix);

}