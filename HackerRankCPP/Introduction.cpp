/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include "Header.h"

using namespace std;

void Input_and_Output()
{
    int a,b,c;
    cin >> a >> b >> c;
    printf("%d", (a+b+c));
}

void Basic_Data_Types()
{
    int Integer = 0;
    long Long = 0;
    long long LongLong = 0;
    char Char = 0;
    float Float = 0;
    double Double = 0;
    scanf("%d %ld %lld %c %f %lf", &Integer, &Long, &LongLong, &Char, &Float, &Double);
    printf("%d\n%ld\n%lld\n%c\n%f\n%lf", Integer, Long, LongLong, Char, Float, Double);
}

void Conditional_Statements()
{
    int input = 0;
    cin >> input;
    switch(input)
    {
        case 1: cout << "one";
            break;
        case 2: cout << "two";
            break;
        case 3: cout << "three";
            break;
        case 4: cout << "four";
            break;
        case 5: cout << "five";
            break;
        case 6: cout << "six";
            break;
        case 7: cout << "seven";
            break;
        case 8: cout << "eight";
            break;
        case 9: cout << "nine";
            break;
        default: cout << "Greater than 9";
            break;
    }
}

void Conditional_Statements_For_Loop(int a)
{
    int input = a;
    switch(input)
    {
        case 1: cout << "one\n";
            break;
        case 2: cout << "two\n";
            break;
        case 3: cout << "three\n";
            break;
        case 4: cout << "four\n";
            break;
        case 5: cout << "five\n";
            break;
        case 6: cout << "six\n";
            break;
        case 7: cout << "seven\n";
            break;
        case 8: cout << "eight\n";
            break;
        case 9: cout << "nine\n";
            break;
        default: 
            if(a%2==0)
                cout << "even\n";
            else
                cout << "odd\n";
            break;
    }
}

void For_Loop()
{
    int start = 0;
    int stop = 0;
    cin >> start >> stop;
    for(int i = start; i <= stop; i++)
    {
        Conditional_Statements_For_Loop(i);
    }
}