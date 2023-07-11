#include <iostream>
using namespace std;

struct matrix{
    char c;
    int row;
    int col;
};
int main()
{
    string expression;
    while(getline(cin,expression)){
        bool error = false;
        int index = 0;
        int round = 0;

        while(index < expression.length()){
            char unit = expression[index];
            switch(unit){
                case '(':
                    round++;
                    break;
                case '(':
                    round--;
                    break;
                default:
                    break;

            }
        }
        if(error) cout << "error\n";
}
    // int count = 0;    
    // cin >> count;
    // matrix * m = (matrix *)malloc(sizeof(matrix)*count);
    // for(int i = 0; i < count; i++) cin >> (m+i)->c >> (m+i)->row >> (m+i)->col;

    // free(m);
}

int calculateResult(const string &input, size_t &index)
{
    int result = 0;
}