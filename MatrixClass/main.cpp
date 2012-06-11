//
//  main.cpp
//  MatrixClass
//
//  Created by sasoh on 11.06.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, const char * argv[]) {
    Matrix *obj = new Matrix(4, 4);
    obj->setElement(3, 3, 1);
    cout << "My first matrix:" << endl << *obj;
    return 0;
}

