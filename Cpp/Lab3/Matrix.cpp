#include "Matrix.h"

// Constructors

Matrix::Matrix() {
    num_rows = 0;
    num_cols = 0;

    mat = new int[0];
}

Matrix::Matrix(int r, int c) {
    assert (r >= 0 && c >= 0);
    
    num_rows = r;
    num_cols = c;

    mat = new int[num_rows * num_cols];

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mat[(i * num_cols) + j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &m) {
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
    cleanup();
}

// Accessors
int Matrix::getrows() const {
    return num_rows;
}

int Matrix::getcols() const {
    return num_cols;
}

int Matrix::getelem(int r, int c) const {
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

// Operator overloads
Matrix& Matrix::operator=(const Matrix &m) {
    // Check for self-assignment
    if (this == &m)
        return *this;

    cleanup();
    copy(m);

    return *this;
}

Matrix& Matrix::operator+=(const Matrix &m) {
    if ((num_rows != m.getrows()) || (num_cols != m.getcols()))
        return *this;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mat[(i * num_cols) + j] += m.getelem(i, j);
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix &m) {
    if ((num_rows != m.getrows()) || (num_cols != m.getcols()))
        return *this;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mat[(i * num_cols) + j] -= m.getelem(i, j);
        }
    }

    return *this;

}

Matrix& Matrix::operator*=(const Matrix &m) {
    // check for correct dimensions
    if (num_cols != m.getrows())
        return *this;

    Matrix newmat(num_rows, m.getcols());

    for (int i = 0; i < num_rows; i++) {
        int dest_col = 0;

        for (int j = 0; j < m.getcols(); j++) {
            int sum = 0;

            for (int k = 0; k < m.getrows(); k++) {
                sum += mat[(i * num_cols) + k] * m.getelem(k, j);
            }

            newmat.setelem(i, dest_col++, sum);
        }
    }

    *this = newmat;

    return *this;
}

const Matrix Matrix::operator+(const Matrix &m) const {
    Matrix ret = *this;
    ret += m;
    return ret;
}

const Matrix Matrix::operator-(const Matrix &m) const {
    Matrix ret = *this;
    ret -= m;
    return ret;
}

const Matrix Matrix::operator*(const Matrix &m) const {
    Matrix ret = *this;
    ret *= m;
    return ret;
}

bool Matrix::operator==(const Matrix &m) const {
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

bool Matrix::operator!=(const Matrix &m) const {
    return !(*this == m);
}

// Private
void Matrix::copy(const Matrix& m) {
    num_rows = m.getrows();
    num_cols = m.getcols();
    
    mat = new int[num_rows * num_cols];

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mat[(i * num_cols) + j] = m.getelem(i, j);
        }
    }
}

void Matrix::cleanup() {
    num_rows = 0;
    num_cols = 0;

    delete[] mat;
}
