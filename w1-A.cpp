#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<char> s;
    int count=0;
    scanf("%d",&count);
    cin.ignore();
    while(count){
        --count;
        string expression;
        getline(cin,expression);
        size_t index = 0;
        while(index <= expression.length()){
            char unit = expression[index];
            if(unit == ' ' || index == expression.length()){
                while(!s.empty()){
                    cout<<s.top();
                    s.pop();
                }
                cout<<' ';
            }
            else s.push(unit);
            ++index;
        }
        cout<<'\n';
    }
}