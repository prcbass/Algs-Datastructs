//
//  chain.h
//  MyDataStructsAlgs
//  INFO: A LinkedList implementation of a linear list, complete with common methods
//  Full transparency: Sartaj Sahni's book, Data Structures, Algorithms, and Applications in C++ (2nd) was used as a reference source (http://www.cise.ufl.edu/~sahni/dsaac/)
//
//  Created by Sebastian Hernandez on 12/19/15.
//  Copyright © 2015 Sebastian Hernandez. All rights reserved.
//
//

//TODO: Implement this class with smart pointers.
//TODO: Implement classes "indexOf" and below

#ifndef chain_h
#define chain_h

#include<sstream>
#include<iostream>
#include<string>
#include "chainNode.h"
#include "SHExceptions.h"

using namespace std;

template<class T>
class chain
{
public:
    //constructor
    chain();
    //copy constructor
    chain(const chain<T>& sourceList);
    ~chain();
    
    bool empty() const {return listSize == 0;};
    int size() const {return listSize;}
    T& getData (int index) const;
    int indexOf(const T& element) const;
    void erase(int index);
    void erase(const T& element);
    void insert(int index, const T& element);
    void insertAtEnd(const T& element);
    void output(ostream& out) const;
    
protected:
    void checkIndex(int index) const;
    chainNode<T>* firstNode;
    int listSize;
};

template<class T>
chain<T>::chain()
{
    firstNode = NULL;
    listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& sourceList)
{
    listSize = sourceList.listSize;
    
    if(listSize == 0) //empty list
    {
        firstNode = NULL;
        return;
    }
    
    //make a copy of sourceList.firstNode so we can perform operations on it
    chainNode<T>* sourceNode = sourceList.firstNode;
    firstNode = new chainNode<T>(sourceNode->data);
    
    chainNode<T>* currentNode = firstNode;
    
    sourceNode = sourceNode->next; //move sourceNode down so we can check for NULL in while loop
    while(sourceNode != NULL)
    {
        currentNode->next = new chainNode<T>(sourceNode->data);
        currentNode = currentNode->next;
        sourceNode = sourceNode->next;
    }
    currentNode->next = NULL; //end chain once loop has exited
}

template<class T>
chain<T>::~chain()
{
    while(firstNode != NULL)
    {
        chainNode<T>* currentNode = firstNode->next;
    
        //we delete what firstNode contains (what the memory contains at that memory address)
        //but firstNode still has the same memory address (and can therefore be reassigned)
        delete firstNode;
        firstNode = currentNode;
    }
}

template<class T>
void chain<T>::checkIndex(int index) const
{
    if(index < 0 || index >= listSize)
    {
        ostringstream s;
        s << "index = " << index << " but size = " << listSize;
        throw illegalIndex(s.str());
    }
}

template<class T>
T& chain<T>::getData(int index) const
{
    checkIndex(index);
    
    chainNode<T>* currentNode = firstNode;
    
    for(int i=0; i<index; ++i)
        currentNode = currentNode->next;
    
    return currentNode->data;
    
}


template<class  T> //TODO: make sure that stopping at the 2nd to last node works
void chain<T>::output(ostream& out) const
{
    chainNode<T>* currentNode;
    out << "[";
    for(currentNode = firstNode;
        currentNode->next != NULL;
        currentNode=currentNode->next)
        
        out << currentNode->data << ", ";
    
    currentNode = currentNode->next;
    out << currentNode->data << " ]";
}

//to overload the '<<' operator
template<class T>
ostream& operator<<(ostream& out, const chain<T>& a)
{
    a.output(out); return out;
}


#endif /* chain_h */
