#include <iostream>

void cin_matrix(int&, int&, int**&);
void cout_matrix(int&, int&, int**&);
void delete_matrix(int&, int&, int**&);
void rotate_matrix(int&, int&, int**&);

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
    rotate_matrix(r, c, matrix);

    delete_matrix(r, c, matrix);
    return 0;
}

void cin_matrix(int& row, int& colum, int**& matrix)
{
    matrix = new int*[row]; 
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

void rotate_matrix(int& row, int& colum, int**& matrix)
{
    for (int i = 0; i < colum ; ++i)
    {
        for (int j = row - 1; j >= 0; --j)
        {
            std::cout << matrix[j][i] << " ";
        }
        std::cout << std::endl;
    }
}