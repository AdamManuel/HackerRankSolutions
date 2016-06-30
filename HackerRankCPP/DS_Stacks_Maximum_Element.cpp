/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int val;            //value
    struct node* next;  //left child
};

void initStack(struct node* head)
{
    head = NULL;
}

void getMax(node* root)
{
    int MaxElement = root->val;
    
    while(root->next != 0)
    {
        root = root->next;
        if(root->val > MaxElement)
            MaxElement = root->val;
    }
    cout << MaxElement << '\n';
}

struct node* pop(struct node* root)
{
    struct node* temp = root;
    root = root->next;
    free(temp); //free the memory
    return root;
}

struct node* push(struct node* root,int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) //if it did not allocate memory
    {
        exit(0);
    }
    temp->val = val;
    temp->next = root;
    root = temp;
    return root;
}

int main() {

    struct node* stack;
    initStack(stack);
    
    int numberOfCommands;
    cin >> numberOfCommands;
    for(int i = 0; i < numberOfCommands; i++)
    {
        int command;
        cin >> command;
        if(command == 1)
        {
            int val;
            cin >> val;
            //This if/else forces the top of the stack to always be the largest number in 
            //the stack. Kinda hacky but it'll work for this problem.
            if(stack == NULL || val > stack->val) 
                stack = push(stack, val);
            else
                stack = push(stack, stack->val);
        }
        if(command == 2)
        {
            stack = pop(stack);
        }
        if(command == 3)
        {
            //print max
            cout << stack->val << '\n';
        }
    }
    return 0;
}