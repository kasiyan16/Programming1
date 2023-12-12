#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Функція для зчитування матриці з файлу
vector<vector<int>> readMatrixFromFile(const string& filename, int n) {
    ifstream file(filename);
    vector<vector<int>> matrix;

    if (file.is_open()) {
        int num;
        for (int i = 0; i < n; ++i) {
            vector<int> row;
            for (int j = 0; j < n; ++j) {
                file >> num;
                row.push_back(num);
            }
            matrix.push_back(row);
        }
        file.close();
    }
    else {
        cerr << "Unable to open file " << filename << endl;
    }

    return matrix;
}

// Функція для запису матриці у файл
void writeMatrixToFile(const string& filename, const vector<vector<int>>& matrix) {
    ofstream file(filename);

    if (file.is_open()) {
        for (const auto& row : matrix) {
            for (int num : row) {
                file << num << " ";
            }
            file << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

// Функція для обчислення матриці C = (AВ - A^2B)^3
vector<vector<int>> calculateMatrixC(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    // Обчислення AВ
    vector<vector<int>> A_times_B(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                A_times_B[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Обчислення A^2B
    vector<vector<int>> A_squared_times_B(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                A_squared_times_B[i][j] += A[i][k] * A[k][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A_squared_times_B[i][j] *= B[i][j];
        }
    }

    // Обчислення C = (AВ - A^2B)^3
    for (int p = 0; p < 2; ++p) {
        vector<vector<int>> temp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    temp[i][j] += (A_times_B[i][k] - A_squared_times_B[i][k]) * (A_times_B[k][j] - A_squared_times_B[k][j]);
                }
            }
        }
        A_times_B = temp;
    }

    return A_times_B;
}

int main() {
    int i = 9; // Ваш варіант
    int n = i + 4;

    // Зчитування матриць з файлів
    vector<vector<int>> A = readMatrixFromFile("a.txt", n);
    vector<vector<int>> B = readMatrixFromFile("b.txt", n);

    // Обчислення матриці C
    vector<vector<int>> matrixC = calculateMatrixC(A, B);

    // Запис результату у файл
    writeMatrixToFile("c.txt", matrixC);

    return 0;
}
