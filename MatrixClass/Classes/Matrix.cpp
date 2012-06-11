//
//  Matrix.cpp
//  MatrixClass
//
//  Created by sasoh on 11.06.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Matrix.h"

Matrix::Matrix(const int rows, const int columns) {
    if (rows < 1) {
        cout << "Matrix row count is invalid, resetting to 3.\n";
        i = 3;
    }
    if (columns < 1) {
        cout << "Matrix column count is invalid, resetting to 3.\n";
        j = 3;
    }
    
    i = rows;
    j = columns;
    
    data = new double *[i];
    for (int k = 0; k < i; k++) {
        data[k] = new double[j];
        for (int p = 0; p < j; p++) {
            data[k][p] = 0;
        }
    }
}

Matrix::~Matrix() {
    for (int k = 0; k < i; k++) {
        delete []data[k];
    }
    delete []data;
}

Matrix &Matrix::operator=(const Matrix &another) {
    if (this != &another) {
        i = another.getRows();
        j = another.getColumns();
        for (int k = 0; k < i; k++) {
            for (int p = 0; p < j; p++) {
                data[k][p] = another.getElement(k, p);
            }
        }
    }
    return *this;
}

std::ostream& operator<< (std::ostream& stream, const Matrix &another) {
    for (int k = 0; k < another.getRows(); k++) {
        for (int p = 0; p < another.getColumns(); p++) {
            stream << setw(6) << std::left << another.getElement(k, p) << " ";
        }
        // new line after each row
        stream << endl;
    }
    return stream;
}

const int Matrix::getRows() const {
    return i;
}

const int Matrix::getColumns() const {
    return j;
}

const double Matrix::getElement(const int row, const int column) const {
    if ((row >= 0 && row < i) && (column >= 0 && column < j)) {
        return data[row][column];
    }
    else {
        cout << "Trying to access an element outside the bounds of the matrix.\n";
        return -9999;
    }
}

void Matrix::setElement(const int row, const int column, const double value) {
    if ((row >= 0 && row < i) && (column >= 0 && column < j)) {
        data[row][column] = value;
    }
    else {
        cout << "Trying to set value at a nonexisting location.\n"; 
    }
}

Matrix Matrix::operator+(const Matrix &another) const {
    Matrix result(i, j);
    if (another.getRows() == i && another.getColumns() == j) {
        for (int k = 0; k < i; k++) {
            for (int p = 0; p < j; p++) {
                result.setElement(k, p, getElement(k, p) + another.getElement(k, p));
            }
        }
    }
    else {
        cout << "You can't perform addition on matrices with different dimensions.\n";
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &another) const {
    Matrix result(i, j);
    if (another.getRows() == i && another.getColumns() == j) {
        for (int k = 0; k < i; k++) {
            for (int p = 0; p < j; p++) {
                result.setElement(k, p, getElement(k, p) - another.getElement(k, p));
            }
        }
    }
    else {
        cout << "You can't perform subtractiona on matrices with different dimensions.\n";
    }
    return result;
}

bool Matrix::transpose() {
    // TODO
    return false;
}

bool Matrix::isSingular() {
    // TODO
    return false;
}