//
//  SHExceptions.h
//  MyDataStructsAlgs
//  INFO: Exception classes used in my code
//  Full transparency: Sartaj Sahni's book, Data Structures, Algorithms, and Applications in C++ (2nd) was used as a reference source (http://www.cise.ufl.edu/~sahni/dsaac/)
//
//  Created by Sebastian Hernandez on 12/20/15.
//  Copyright © 2015 Sebastian Hernandez. All rights reserved.
//

#ifndef SHExceptions_h
#define SHExceptions_h

#include<string>

using namespace std;

class illegalIndex
{
public:
    //initialize inputMessage by default in-case an inputMessage is not specified
    illegalIndex(string inputMessage = "Illegal index")
        {message = inputMessage;}
    void outputMessage() {cout << message << endl;}

private:
    string message;
};


#endif /* SHExceptions_h */
