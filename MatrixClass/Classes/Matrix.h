//
//  Matrix.h
//  MatrixClass
//
//  Created by sasoh on 11.06.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <iomanip>

#ifndef MatrixClass_Matrix_h
#define MatrixClass_Matrix_h

using std::cin;
using std::cout;
using std::endl;
using std::setw;

class Matrix {
public:
    // essential class functions
    Matrix(const int rows = 3, const int columns = 3);
    ~Matrix();
    Matrix &operator=(const Matrix &another);
    friend std::ostream& operator<< (std::ostream& stream, const Matrix &another);
    
    // accessors
    const int getRows() const;
    const int getColumns() const;
    const double getElement(const int row = 0, const int column = 0) const;
    void setElement(const int row = 0, const int column = 0, const double value = 0);

    // common operations
    Matrix operator+(const Matrix &another) const;
    Matrix operator-(const Matrix &another) const;
    Matrix operator*(const Matrix &another) const;
    bool transpose();
    bool isSingular();
    Matrix *getInverseMatrix(bool *error);
private:
    double **data;
    int i;
    int j;
};

#endif
