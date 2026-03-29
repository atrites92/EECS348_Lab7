#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
    int data[SIZE][SIZE]; // 2D array for matrix data

public:
    // Constructor: initialize all values to 0
    Matrix() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                data[i][j] = 0;
            }
        }
    }

    // 1. Read values from stdin into a matrix
    void readFromStdin() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cin >> data[i][j];
            }
        }
    }

    // Helper: load matrix from a 1D array starting at some offset
    void loadFromArray(const int arr[], int startIndex) {
        int index = startIndex;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                data[i][j] = arr[index++];
            }
        }
    }

    // 2. Display a matrix
    void display() const {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // 3. Add two matrices
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // 4. Multiply two matrices
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const {
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += data[i][i];
        }
        return sum;
    }

    // 6. Swap matrix rows
    void swapRows(int row1, int row2) {
        if (row1 < 0 || row1 >= SIZE || row2 < 0 || row2 >= SIZE) {
            cout << "Invalid row index." << endl;
            return;
        }

        for (int j = 0; j < SIZE; j++) {
            int temp = data[row1][j];
            data[row1][j] = data[row2][j];
            data[row2][j] = temp;
        }
    }
};

int main() {
    // get the filepath
    string filePath = "matrix-data.txt";

    // Open the file using ifstream
    ifstream file(filePath);

    // confirm file opening
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return 1;
    }

    // Read 32 values total: 16 for mat1, 16 for mat2
    int arr[32];
    for (int i = 0; i < 32; ++i) {
        if (!(file >> arr[i])) {
            cerr << "Error: file does not contain enough integers." << endl;
            file.close();
            return 1;
        }
    }
    file.close();

    Matrix mat1;
    Matrix mat2;

    // Load matrices from file data
    mat1.loadFromArray(arr, 0);    // first 16 values
    mat2.loadFromArray(arr, 16);   // next 16 values

    cout << "Matrix 1:" << endl;
    mat1.display();

    cout << "\nMatrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "\nSum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "\nProduct of matrices:" << endl;
    product.display();

    cout << "\nSum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    mat1.swapRows(0, 2);
    cout << "\nMatrix 1 after swapping rows 0 and 2:" << endl;
    mat1.display();

    return 0;
} 