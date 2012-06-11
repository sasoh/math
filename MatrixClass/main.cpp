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
    Matrix obj1(2, 3);
    Matrix obj2(3, 2);
    obj1.setElement(0, 0, 1);
    obj1.setElement(0, 1, 0);
    obj1.setElement(0, 2, -2);
    obj1.setElement(1, 0, 0);
    obj1.setElement(1, 1, 3);
    obj1.setElement(1, 2, -1);
    
    obj2.setElement(0, 0, 0);
    obj2.setElement(0, 1, 3);
    obj2.setElement(1, 0, -2);
    obj2.setElement(1, 1, -1);
    obj2.setElement(2, 0, 0);
    obj2.setElement(2, 1, 4);
    
    cout << "M1:\n" << obj1;
    cout << "M2:\n" << obj2;
    cout << "M1 * M2:\n" << obj1 * obj2;
    obj1.transpose();
    cout << "M1T:\n" << obj1;
    return 0;
}

