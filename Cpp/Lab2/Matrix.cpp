#include "Matrix.h"

// Constructors

Matrix::Matrix() {
    num_rows = 0;
    num_cols = 0;

    mat = new int[0];
}

Matrix::Matrix(int r, int c) {
    assert (r > 0 && c > 0);
    
    num_rows = r;
    num_cols = c;

    mat = new int[num_rows * num_cols];
}

Matrix::Matrix(Matrix &m) {
    num_rows = m.getrows();
    num_cols = m.getcols();

    mat = new int[num_rows * num_cols];

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mat[(i * num_cols) + j] = m.getelem(i, j);
        }
    }
}

// Destructor
Matrix::~Matrix() {
    delete[] mat;
}

// Accessors
int Matrix::getrows() {
    return num_rows;
}

int Matrix::getcols() {
    return num_cols;
}

int Matrix::getelem(int r, int c) {
    assert ((r >= 0) && (r < num_rows));
    assert ((c >= 0) && (c < num_cols));
    
    return mat[(r * num_cols) + c];
}

// Mutators
void Matrix::setelem(int r, int c, int v) {
    assert ((r >= 0) && (r < num_rows));
    assert ((c >= 0) && (c < num_cols));
    
    mat[(r * num_cols) + c] = v;
}

// Member functions
void Matrix::add(Matrix &m) {
    if ((num_rows != m.getrows()) || (num_cols != m.getcols()))
        return;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mat[(i * num_cols) + j] += m.getelem(i, j);
        }
    }
}

void Matrix::subtract(Matrix &m) {
    if ((num_rows != m.getrows()) || (num_cols != m.getcols()))
        return;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mat[(i * num_cols) + j] -= m.getelem(i, j);
        }
    }
}

bool Matrix::equals(Matrix &m) {
    if ((num_rows != m.getrows()) || (num_cols != m.getcols()))
        return false;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (mat[(i * num_cols) + j] != m.getelem(i, j))
                return false;
        }
    }

    return true;
}
