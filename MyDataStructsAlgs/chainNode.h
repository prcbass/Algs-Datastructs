//
//  chainNode.h
//  MyDataStructsAlgs
//  INFO: Node for chain (LinkedList implementation of LinearList)
//  Full transparency: Sartaj Sahni's book, Data Structures, Algorithms, and Applications in C++ (2nd) was used as a reference source
//
//  Created by Sebastian Hernandez on 12/19/15.
//  Copyright © 2015 Sebastian Hernandez. All rights reserved.
//

#ifndef chainNode_h
#define chainNode_h

template<class T>
struct chainNode
{
    T data;
    chainNode<T> *next;
    
    chainNode(){};
    chainNode(const T& data)
    {this->data = data;}
    chainNode(const T& data, chainNode<T>* next)
    {this->data = data; this->next = next;}
};

#endif /* chainNode_h */
