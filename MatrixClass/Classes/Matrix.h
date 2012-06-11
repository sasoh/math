//
//  Matrix.h
//  MatrixClass
//
//  Created by sasoh on 11.06.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#ifndef MatrixClass_Matrix_h
#define MatrixClass_Matrix_h

class Matrix {
public:
    Matrix(int i_ = 3, int j_ = 3);
    ~Matrix();
    Matrix &operator=(const Matrix &another);
    friend std::ostream& operator<< (std::ostream& stream, const Matrix &another);
    
    bool transpose();
    bool isSingular();
    Matrix *getInverseMatrix(bool *error);
private:
    double **data;
    int i;
    int j;
};



#endif
