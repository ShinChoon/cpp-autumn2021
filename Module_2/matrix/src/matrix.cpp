#include <iostream>
#include <sstream>
#include <vector>
#include "matrix.hpp"

// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

// Function reads input from user to n x n matrix,
// one number at a time.
Matrix ReadMatrix(int n){
    Matrix intermediate;
    std::vector<int> example;
    int value = 0;

    for (int count = 0; count < n * n; count++)
    {
        value = 0;
        std::cin >> value;
        example.push_back(value);
    }
    int ind = 0;
    std::vector<int> v1;
    for (int c = 0; c < n; c++)
    {
        v1.clear();
        for (int l = 0; l < n; l++)
        {
            v1.push_back(example[ind]);
            ind++;
        }
        intermediate.push_back(v1);
    }

    return intermediate;
}

// Function rotates n x n matrix 90 degrees clockwise
// and stores it to a new matrix that it returns
Matrix Rotate90Deg(const Matrix& example){
    Matrix it = example;
    Matrix::size_type j = 0;
    Matrix::size_type i = 0;
    int size_n = it.size();
    for ( i = 0; i < it.size()/2; i++)
    {
        std::vector<int> numbers = it[i];
        for (j = i; j < it[i].size()-i-1; j++)
        {
            int temp = it[i][j];
            it[i][j] = it[size_n - 1 - j][i];
            it[size_n - 1 - j][i] = it[size_n - 1 - i][size_n - 1 - j];
            it[size_n - 1 - i][size_n - 1 - j] = it[j][size_n - 1 - i];
            it[j][size_n - 1 - i] = temp;
        }

    }
    return it;
}

/* Function prints n x n matrix to standard output:
 * e.g. when n = 3 and the matrix' rows are all 1,2,3:
Printing out a 3 x 3 matrix:\n
1 2 3 \n
1 2 3 \n
1 2 3 \n
 */
void Print(const Matrix& example){
    Matrix::const_iterator it = example.begin();
    std::cout << "Printing out a " << example.size() << " x " << example.size() << " matrix:" << std::endl;
    for (Matrix::size_type i = 0; i < example.size(); i++)
    {
        for (Matrix::size_type j = 0; j < example.size(); j++)
        {
            std::cout << (*it)[j] << " ";
        }
        it++;
        std::cout << std::endl;
    }
}