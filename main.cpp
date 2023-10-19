#include <iostream>
#include <fstream>
#include <iomanip>

const int max = 100;

void readMatrix(int matrix[max][max],int matrix2[max][max], int& size, const std::string& filename){//creates the first matrix
    std::fstream file;
    file.open("matrix_input.txt");
    if (file.is_open()){
        file >> size;
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                file >> matrix[i][j];
            }
        }
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                file >> matrix2[i][j];
            }
        }
        file.close();
    }
    else
    {
        std::cerr<<"Error opening file. "<< std::endl;
        exit(1);
    }
}

void printMatrix(const int matrix[max][max], int size, const std::string& name){
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            std::cout<< std::setw(4) << matrix[i][j]<< "";
        }
        std::cout << std::endl;
    }
}
void addMatrices(const int matrix1[max][max], const int matrix2[max][max], int resultMatrix[max][max], int size){
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];       
        }
    }
}

void multiplyMatrices(const int matrix1[max][max], const int matrix2[max][max], int resultMatrix[max][max], int size){
    for (int i=0; i<size; i++){
        for (int j = 0; j < size; j++){
            resultMatrix[i][j] = 0;
            for(int k = 0; k < size; ++k) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrix1[max][max], const int matrix2[max][max], int resultMatrix[max][max], int size){
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];       
        }
    }
}


int main() {
    int size;
    int matrix1[max][max];
    int matrix2[max][max];
    int resultMatrix[max][max];

    readMatrix(matrix1, matrix2, size, "matrix_input.txt");
    std::cout << "Colin Treanor\nLab #6:\nMatrix manipulation" << std::endl;
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrix1, size, "A");

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrix2, size, "B");

    std::cout << "Matrix Sum(A+B):" << std::endl;
    addMatrices(matrix1, matrix2, resultMatrix, size);
    printMatrix(resultMatrix, size, "Sum");

    std::cout << "Matrix Product:" << std::endl;
    multiplyMatrices(matrix1, matrix2, resultMatrix, size);
    printMatrix(resultMatrix, size, "Product");

    std::cout << "Matrix Difference:" << std::endl;
    subtractMatrices(matrix1, matrix2, resultMatrix, size);
    printMatrix(resultMatrix, size, "Difference");

    return 0;
}