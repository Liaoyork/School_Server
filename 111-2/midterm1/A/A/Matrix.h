// Matrix.h
#include <iostream>
using namespace std;
class Matrix {
   private:
    double** data;
    int row;
    int col;

   public:
    // Level 1
    // Constructors and destructor
    Matrix();                                  // Set row and col to 0, data to nullptr
    Matrix(int row, int col);                  // Create a zero matrix
    Matrix(int row, int col, double** arr2D);  // Copy from array
    Matrix(const Matrix& matrix);              // Copy from another matrix
    ~Matrix();                                 // Delete data

    // Setters and Getters
    // Set the value of the given row and col
    void setValue(int rowIdx, int colIdx, double value);
    // Get the value of the given row and col
    double getValue(int rowIdx, int colIdx) const;

    // Transpose
    Matrix transpose() const;  // Return a new transposed matrix

    // Operator Overload
    // Overload =, +=, -=, +, -, +m, -m, ==, !=, ostream<<
    void operator=(const Matrix &) ;   // Copy to a new matrix
    void operator+=(const Matrix &) ;  // Matrix addition, ex: a += b;
    void operator-=(const Matrix &) ;  // Matrix subtraction, ex: a -= b;
    Matrix operator+(const Matrix &) ;   // Matrix addition, ex: c = a + b;
    Matrix operator-(const Matrix &) ;   // Matrix subtraction, ex: c = a - b;
    Matrix operator+() const;   // Positive Matrix, ex: Matrix b = +a;
    Matrix operator-() const;   // Negative Matrix, ex: Matrix b = -a;
    bool operator==(const Matrix &) ;  // Return true if the two matrix is equal
    bool operator!=(const Matrix &) ;  // Return false if the two matrix is equal
    friend ostream &operator<<(ostream &,const Matrix &) ;  // Output the matrix, ex: cout << a;

    // Level 2
    // Overload *=, *
    void operator*=(const Matrix &) const; // Matrix and Matrix multiplication
    void operator*=(double) const; // Matrix and double multiplication
    Matrix operator*(const Matrix &) const; // Matrix and Matrix multiplication
    Matrix operator*(double) const; // Matrix and double multiplication
    friend Matrix operator*(double,const Matrix &); // double and Matrix multiplication

    // Level 3
    double determinant() const;  // The determinant of the matrix
    double det(double**, int) const;
};

ostream &operator<<(ostream &,const Matrix &);  // Output the matrix, ex: cout << a;
