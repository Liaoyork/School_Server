#include "Matrix.h"

#include <iostream>
using namespace std;

// Level 1
// Constructors and destructor
Matrix::Matrix() {
    row = 0;
    col = 0;
    data = NULL;
}
Matrix::Matrix(int r, int c) {
    row = r;
    col = c;
    data = new double *[row];
    for (int i = 0; i < row; i++) {
        data[i] = new double[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            data[i][j] = 0;
        }
    }
}
Matrix::Matrix(int row, int col, double **arr2D) {
    this->row = row;
    this->col = col;
    data = new double *[this->row];
    for (int i = 0; i < this->row; i++) {
        data[i] = new double[this->col];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            data[i][j] = arr2D[i][j];
        }
    }
}
Matrix::Matrix(const Matrix &matrix) {
    this->row = matrix.row;
    this->col = matrix.col;
    data = new double *[matrix.row];
    for (int i = 0; i < matrix.row; i++) {
        data[i] = new double[matrix.col];
    }
    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            data[i][j] = matrix.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < row; i++) {
        delete[] data[i];
    }
    delete[] data;
}

// Setters and Getters
// Set the value of the given row and col
void Matrix::setValue(int rowIdx, int colIdx, double value) {
    data[rowIdx][colIdx] = value;
}
// Get the value of the given row and col
double Matrix::getValue(int rowIdx, int colIdx) const {
    return data[rowIdx][colIdx];
}

// Transpose
Matrix Matrix::transpose() const {
    Matrix temp(this->col, this->row);
    for (int i = 0; i < temp.row; i++) {
        for (int j = 0; j < temp.col; j++) {
            temp.data[i][j] = this->data[j][i];
        }
    }
    return temp;
}

// Operator Overload
// Overload =, +=, -=, +, -, +m, -m, ==, !=, ostream<<
void Matrix::operator=(const Matrix &o1) { 
    for (int i = 0; i < row; i++) {
        delete[] data[i];
    }
    delete[] data;

    this->row = o1.row;
    this->col = o1.col;
    data = new double *[o1.row];
    for (int i = 0; i < o1.row; i++) {
        data[i] = new double[o1.col];
    }
    for (int i = 0; i < o1.row; i++) {
        for (int j = 0; j < o1.col; j++) {
            this->data[i][j] = o1.data[i][j];
        }
    }
}
void Matrix::operator+=(const Matrix &o1) {
    if (this->data == NULL) {
        this->row = o1.row;
        this->col = o1.col;
        data = new double *[this->row];
        for (int i = 0; i < this->row; i++) {
            this->data[i] = new double[this->col];
        }
    }
    for (int i = 0; i < o1.row; i++) {
        for (int j = 0; j < o1.col; j++) {
            this->data[i][j] = this->data[i][j] + o1.data[i][j];
        }
    }
}
void Matrix::operator-=(const Matrix &o1) {
    if (this->data == NULL) {
        this->row = o1.row;
        this->col = o1.col;
        data = new double *[this->row];
        for (int i = 0; i < this->row; i++) {
            this->data[i] = new double[this->col];
        }
    }
    for (int i = 0; i < o1.row; i++) {
        for (int j = 0; j < o1.col; j++) {
            this->data[i][j] = this->data[i][j] - o1.data[i][j];
        }
    }
}
Matrix Matrix::operator+(const Matrix &o1) {
    Matrix temp(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp.data[i][j] = data[i][j] + o1.data[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator-(const Matrix &o1) {
    Matrix temp(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp.data[i][j] = data[i][j] - o1.data[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator+() const {
    Matrix temp(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp.data[i][j] = data[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator-() const {
    Matrix temp(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp.data[i][j] = -data[i][j];
        }
    }
    return temp;
}
bool Matrix::operator==(const Matrix &o1) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (data[i][j] != o1.data[i][j]) return false;
        }
    }
    return true;
}
bool Matrix::operator!=(const Matrix &o1) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (data[i][j] != o1.data[i][j]) return true;
        }
    }
    return false;
}
ostream &operator<<(ostream &out, const Matrix &o1) {
    for (int i = 0; i < o1.row; i++) {
        for (int j = 0; j < o1.col; j++) {
            cout << o1.data[i][j] << " ";
        }
        cout << endl;
    }
    return out;
}

// Level 2
// Overload *=, *
void Matrix::operator*=(const Matrix &o1) const {
    double temp = 0;
    Matrix temp1(this->row, o1.col);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < o1.col; j++) {
            for (int k = 0; k < this->col; k++) {
                temp += this->data[i][k] * o1.data[k][j];
            }
            temp1.data[i][j] = temp;
            temp = 0;
        }
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < o1.col; j++) {
            this->data[i][j] = temp1.data[i][j];
        }
    }
}

void Matrix::operator*=(const double c) const {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            this->data[i][j] = this->data[i][j] * c;
        }
    }
}
Matrix Matrix::operator*(const Matrix &o1) const {
    Matrix temp(this->row, o1.col);
    double tempD = 0;
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < o1.col; j++) {
            for (int k = 0; k < this->col; k++) {
                tempD += this->data[i][k] * o1.data[k][j];
            }
            temp.data[i][j] = tempD;
            tempD = 0;
        }
    }
    return temp;
}
Matrix Matrix::operator*(const double c) const {
    Matrix temp(this->row, this->col);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            temp.data[i][j] = this->data[i][j] * c;
        }
    }
    return temp;
}

Matrix operator*(const double c, const Matrix &o1) {
    Matrix temp(o1.row, o1.col);
    for (int i = 0; i < o1.row; i++) {
        for (int j = 0; j < o1.col; j++) {
            temp.data[i][j] = o1.data[i][j] * c;
        }
    }
    return temp;
}

// Level 3
double Matrix::determinant() const {
    return det(data, row);
}

double Matrix::det(double **da, int rank) const {
    double ans = 0;
    if (rank == 1) return da[0][0];
    if (rank == 2) return da[0][0] * da[1][1] - da[1][0] * da[0][1];
    for (int i = 0; i < rank; i++) {
        double **ptr = new double *[rank - 1];
        for (int j = 0; j < rank - 1; j++) {
            ptr[j] = new double[rank - 1];
        }
        int currJ = 0;
        for (int j = 0; j < rank; j++) {
            if (j == i) continue;
            for (int k = 1; k < rank; k++) {
                ptr[k - 1][currJ] = da[k][j];
            }
            currJ++;
        }

        if (i % 2 == 0) {
            ans += da[0][i] * det(ptr, rank - 1);
        } else {
            ans -= da[0][i] * det(ptr, rank - 1);
        }

        for (int i = 0 ; i < rank - 1; i++){
            delete [] ptr [i];
        }
        delete [] ptr;

    }  // The determinant of the matrix
    return ans;
}
