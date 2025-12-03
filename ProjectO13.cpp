#include <iostream>
#include <Windows.h>
using namespace std;

template <class T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:

    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int r, int c, T value = 0) : rows(r), cols(c) {
        data = new T * [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = value;
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new T * [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;

        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;

        rows = other.rows;
        cols = other.cols;

        data = new T * [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        }
        return *this;
    }

    T& operator()(int r, int c) { return data[r][c]; }
    const T& operator()(int r, int c) const { return data[r][c]; }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw runtime_error("Помилка: різні розміри матриць!");

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result(i, j) = data[i][j] + other.data[i][j];

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw runtime_error("Помилка: несумісні розміри!");

        Matrix<T> result(rows, other.cols, 0);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result(i, j) += data[i][k] * other.data[k][j];

        return result;
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

template <typename T>
void printElement(const Matrix<T>& M, int r, int c) {
    cout << "Елемент [" << r << "][" << c << "] = " << M(r, c) << endl;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);

    A(0, 0) = 1; A(0, 1) = 2;
    A(1, 0) = 3; A(1, 1) = 4;

    B(0, 0) = 5; B(0, 1) = 6;
    B(1, 0) = 7; B(1, 1) = 8;

    cout << "A:\n"; A.print();
    cout << "B:\n"; B.print();

    Matrix<int> C = A + B;
    cout << "\nA + B:\n";
    C.print();

    Matrix<int> D = A * B;
    cout << "\nA * B:\n";
    D.print();

    cout << "\nПеревірка шаблонної функції:\n";
    printElement(A, 1, 1); 

    return 0;
}
