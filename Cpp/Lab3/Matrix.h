/*
 * A matrix manipulation class
 *
 * Author: Ashwin Ramachandran
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cmath>
#include <cassert>

class Matrix {
 public:
    // Constructors
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix &m);

    // Destructor
    ~Matrix();

    // Accessors
    int getrows() const;
    int getcols() const;
    int getelem(int r, int c) const;

    // Mutators
    void setelem(int r, int c, int v);

    // Operator overloads
    Matrix& operator=(const Matrix &m);

    Matrix& operator+=(const Matrix &m);
    Matrix& operator-=(const Matrix &m);
    Matrix& operator*=(const Matrix &m);

    const Matrix operator+(const Matrix &m) const;
    const Matrix operator-(const Matrix &m) const;
    const Matrix operator*(const Matrix &m) const;

    bool operator==(const Matrix &m) const;
    bool operator!=(const Matrix &m) const;


 private:
    int *mat;

    int num_rows;
    int num_cols;

    void copy(const Matrix &m);
    void cleanup();
};
#endif
