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
    Matrix(Matrix &m);

    // Destructor
    ~Matrix();

    // Accessors
    int getrows();
    int getcols();
    int getelem(int r, int c);

    // Mutators
    void setelem(int r, int c, int v);

    // Member functions
    void add(Matrix &m);
    void subtract(Matrix &m);
    bool equals(Matrix &m);

 private:
    int *mat;

    int num_rows;
    int num_cols;
};
#endif
