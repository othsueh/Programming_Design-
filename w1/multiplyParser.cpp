#include <iostream>

using namespace std;

int calcResult(const string &input, size_t index);
int main(){
    string expression;
    getline(cin,expression);
    size_t index = 0;
    int result = 1;
    result *= calcResult(expression,index);
    cout<<result<<'\n';
}

int calcResult(const string &input, size_t index){
    int result = 1;
    while(index < input.length()){
        char unit = input[index];
        switch(unit){
            case '(' : 
                index++;
                result *= calcResult(input,index);
                break;
            case ')' :
                index++;
                return result;
            default:
                index++;
                result = unit - '0';
                break;
        }
    }
    return 0;
}
