// -*- C++ -*-

/* 
 * File:   Header.h
 * Author: adam
 *
 * Created on June 29, 2016, 2:16 AM
 */

#ifndef HEADER_H
#define HEADER_H

struct node
{
    int val;            //value
    struct node* left;  //left child
    struct node* right; //right child
    int ht;             //height of the node
} node;


#endif /* HEADER_H */

//Introduction Methods
void Input_and_Output();
void Basic_Data_Types();
void Conditional_Statements();
void Conditional_Statements_For_Loop(int a);
void For_Loop();

//Balanced_Trees Methods
