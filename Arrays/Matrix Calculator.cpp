#include <iostream>
#include <stdexcept>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

void fillMatrix(int matrix[][MAX_COLS], int rows, int cols);
void printMatrix(int matrix[][MAX_COLS], int rows, int cols);
void transposeMatrix(int matrix[][MAX_COLS], int rows, int cols, int result[][MAX_ROWS]);
void multiplyMatrices(int matrix1[][MAX_COLS], int rows1, int cols1, int matrix2[][MAX_COLS], int rows2, int cols2, int result[][MAX_COLS]);
void addMatrices(int matrix1[][MAX_COLS], int rows1, int cols1, int matrix2[][MAX_COLS], int rows2, int cols2, int result[][MAX_COLS]);

int main() {

    int matrix1[MAX_ROWS][MAX_COLS];
    int matrix2[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];
    int rows, cols;

    //Get the matrix size
    cout << "Enter the number of rows: ";
    while (!(cin >> rows) || rows <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer for the number of rows: ";
    }
    cout << "Enter the number of columns: ";
    while (!(cin >> cols) || cols <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer for the number of cols: ";
    }

    //The main loop
    while (true) {

        int choice;

        cout << "-------------------------" << endl;
        cout << "        MAIN MENU        " << endl;
        cout << "-------------------------" << endl;

        cout << "1. Fill matrix" << endl;
        cout << "2. Operate on matrices" << endl;
        cout << "3. Exit program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {//Fill matrix

            int matrix_choice;

            cout << "Enter the matrix number (1 or 2): ";
            cin >> matrix_choice;

            if (matrix_choice == 1) {
                cout << "Fill matrix 1:" << endl;
                fillMatrix(matrix1, rows, cols);
            }
            else if (matrix_choice == 2) {
                cout << "Fill matrix 2:" << endl;
                fillMatrix(matrix2, rows, cols);
            }
            else {
                cout << "Invalid matrix number" << endl;
            }
        }
        else if (choice == 2) {//Operations menu

            int operation_choice;

            cout << "-------------------------" << endl;
            cout << "     MATRIX OPERATIONS    " << endl;
            cout << "-------------------------" << endl;

            cout << "1. Transpose" << endl;
            cout << "2. Print matrix" << endl;
            cout << "3. Matrix multiplication" << endl;
            cout << "4. Matrix addition" << endl;
            cout << "Enter your choice: ";
            cin >> operation_choice;

            if (operation_choice == 1) {//Transpose

                int matrix_choice;

                cout << "Enter the matrix number (1 or 2): ";
                cin >> matrix_choice;

                if (matrix_choice == 1) {
                    transposeMatrix(matrix1, rows, cols, result);
                }
                else if (matrix_choice == 2) {
                    transposeMatrix(matrix2, rows, cols, result);
                }
                else {
                    cout << "Invalid matrix number" << endl;
                    break;
                }

                cout << "Transpose of matrix " << matrix_choice << ":" << endl;
                printMatrix(result, cols, rows);
            }
            else if(operation_choice == 2) {//Print matrix

                int matrix_choice;

                cout << "Enter the matrix number (1 or 2): ";
                cin >> matrix_choice;

                if (matrix_choice == 1) {
                    printMatrix(matrix1, rows, cols);
                }
                else if (matrix_choice == 2) {
                    printMatrix(matrix2, rows, cols);
                }
                else {
                    cout << "Invalid matrix number" << endl;
                }
            }
            else if (operation_choice == 3) {//Multiplication

                if (cols != rows) {
                    cout << "Error: matrices must have the same dimensions" << endl;
                    break;
                }

                multiplyMatrices(matrix1, rows, cols, matrix2, rows, cols, result);
                cout << "Result of matrix multiplication:" << endl;
                printMatrix(result, rows, cols);
            }
            else if (operation_choice == 4) {//Addition

                if (rows != rows || cols != cols) {
                    cout << "Error: matrices must have the same dimensions" << endl;
                    break;
                }

                addMatrices(matrix1, rows, cols, matrix2, rows, cols, result);
                cout << "Result of matrix addition:" << endl;
                printMatrix(result, rows, cols);
            }
            else {
                cout << "Invalid operation choice" << endl;
            }
        }
        else if (choice == 3) {//Exit
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

//Functions
void fillMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter value for row " << i + 1 << " column " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[][MAX_COLS], int rows, int cols, int result[][MAX_ROWS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[][MAX_COLS], int rows1, int cols1, int matrix2[][MAX_COLS], int rows2, int cols2, int result[][MAX_COLS]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void addMatrices(int matrix1[][MAX_COLS], int rows1, int cols1, int matrix2[][MAX_COLS], int rows2, int cols2, int result[][MAX_COLS]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
