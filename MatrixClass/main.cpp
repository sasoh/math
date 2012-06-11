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
    Matrix obj1(4, 4);
    Matrix obj2(4, 4);
    obj1.setElement(3, 3, 4);
    obj2.setElement(3, 2, 0.5);
    cout << "M1:\n" << objs1;
    cout << "M2:\n" << obj2;
    cout << "M1 + M2:\n" << obj1 + obj2;
    cout << "M1 - M2:\n" << obj1 - obj2;
    return 0;
}

