//
//  Matrix.cpp
//  MatrixClass
//
//  Created by sasoh on 11.06.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Matrix.h"

Matrix::Matrix(const int rows_, const int columns_) {
    if (rows_ < 1) {
        cout << "Matrix row count is invalid, resetting to 3.\n";
        rows = 3;
    }
    else {
        rows = rows_;
    }
    if (columns_ < 1) {
        cout << "Matrix column count is invalid, resetting to 3.\n";
        columns = 3;
    }
    else {
        columns = columns_;
    }

    data = new double *[rows];
    for (int k = 0; k < rows; k++) {
        data[k] = new double[columns];
        for (int p = 0; p < columns; p++) {
            data[k][p] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &another) {
    rows = another.getRows();
    columns = another.getColumns();

    data = new double *[rows];
    for (int k = 0; k < rows; k++) {
        data[k] = new double[columns];
        for (int p = 0; p < columns; p++) {
            data[k][p] = another.getElement(k, p);
        }
    }
}

Matrix::~Matrix() {
    for (int k = 0; k < rows; k++) {
        delete []data[k];
    }
    delete []data;
}

Matrix &Matrix::operator=(const Matrix &another) {
    if (this != &another) {
        rows = another.getRows();
        columns = another.getColumns();
        for (int k = 0; k < rows; k++) {
            for (int p = 0; p < columns; p++) {
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
    return rows;
}

const int Matrix::getColumns() const {
    return columns;
}

const double Matrix::getElement(const int row, const int column) const {
    if ((row >= 0 && row < rows) && (column >= 0 && column < columns)) {
        return data[row][column];
    }
    else {
        cout << "Trying to access an element outside the bounds of the matrix.\n";
        return -9999;
    }
}

void Matrix::setElement(const int row, const int column, const double value) {
    if ((row >= 0 && row < rows) && (column >= 0 && column < columns)) {
        data[row][column] = value;
    }
    else {
        cout << "Trying to set value at a nonexisting location.\n"; 
    }
}

Matrix Matrix::operator+(const Matrix &another) const {
    Matrix result(rows, columns);
    if (another.getRows() == rows && another.getColumns() == columns) {
        for (int k = 0; k < rows; k++) {
            for (int p = 0; p < columns; p++) {
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
    Matrix result(rows, columns);
    if (another.getRows() == rows && another.getColumns() == columns) {
        for (int k = 0; k < rows; k++) {
            for (int p = 0; p < columns; p++) {
                result.setElement(k, p, getElement(k, p) - another.getElement(k, p));
            }
        }
    }
    else {
        cout << "You can't perform subtractiona on matrices with different dimensions.\n";
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &another) const {
    Matrix result(getRows(), another.getColumns());
    if (getRows() == another.getColumns()) {
        for (int k = 0; k < getRows(); k++) {
            for (int p = 0; p < another.getColumns(); p++) {
                double product = 0;
                for (int m = k; m < getColumns(); m++) {
                    product += getElement(k, m) * another.getElement(m, p);
                }
                result.setElement(k, p, product);
            }
        }
    }
    else {
        cout << "You can perform multiplication on (m x n) * (n x p) matrices.\n";
    }
    return result;
}

void Matrix::transpose() {
    Matrix copyObj(*this);
    
    // clear old matrix
    for (int k = 0; k < rows; k++) {
        delete []data[k];
    }
    delete []data;
    
    // create new
    rows = copyObj.getColumns();
    columns = copyObj.getRows();
    data = new double *[rows];
    for (int k = 0; k < rows; k++) {
        data[k] = new double[columns];
        for (int p = 0; p < columns; p++) {
            data[k][p] = copyObj.getElement(p, k);
        }
    }
}

bool Matrix::isSingular() {
    // TODO
    return false;
}