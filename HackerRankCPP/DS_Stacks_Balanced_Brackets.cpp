/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
 * Put input into a stack
 * Once done pop until next character to pop is the otherside to the next character in the other stack
 * Go through one by one deleting the pairs
 * if one is not a pair print NO and move onto the next data
 * 
 */

char getOpposite(char input)
{
    if(input == ')'){
        return '(';
    }  
    if(input == '}'){
        return '{';
    }  
    if(input == ']'){
        return '[';
    }
    if(input == '('){
        return ')';
    }  
    if(input == '{'){
        return '}';
    }  
    if(input == '['){
        return ']';
    }
    return input;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        stack<char> leftSideBracket, rightSideBracket;
        for(int i = 0; i < s.length(); i++)
        {
            leftSideBracket.push((s[i]));
        }
        while(!leftSideBracket.empty())
        {
            if(rightSideBracket.empty())
            {
                rightSideBracket.push(getOpposite(leftSideBracket.top()));
                leftSideBracket.pop();
            }
            while(!leftSideBracket.empty() && !rightSideBracket.empty() && leftSideBracket.top() != rightSideBracket.top())
            {
                rightSideBracket.push(getOpposite(leftSideBracket.top()));
                leftSideBracket.pop();
            }
            while(!leftSideBracket.empty() && !rightSideBracket.empty() && leftSideBracket.top() == rightSideBracket.top())
            {
                rightSideBracket.pop();
                leftSideBracket.pop();
            }
        }
        if(rightSideBracket.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}