#include <iostream>
<<<<<<< HEAD
=======
#include <stdio.h>
#include <stack>
#include <string>
>>>>>>> 82d621ae8ad69c7d35ab10440746267a45b2caad
using namespace std;

struct matrix{
    char c;
    int row;
    int col;
};
int main()
{
    int count = 0;
    scanf("%d",&count);
    matrix *m = (matrix*)malloc(sizeof(matrix)*count);
    for(int i = 0;i < count;i++) scanf(" %c%d%d",&(m+i)->c,&(m+i)->row,&(m+i)->col);
    // for(int i = 0;i < count;i++) cout<<(m+i)->c<<(m+i)->row<<(m+i)->col<<'\n';
    stack<matrix> s;
    string expression;
    cin.ignore();
    // while(getline(cin,expression)) cout<<expression<<"\n";
    while(getline(cin,expression)){
        while(!s.empty()) s.pop(); 
        int index = 0;
        int ans = 0;
        int flag = 0;
        while(index < expression.length()){
            int command = expression[index];
            ++index;
            if(command == '('){
                continue;
            }
            else if(command == ')'){ 
                matrix x = s.top();
                s.pop();
                matrix y = s.top();
                s.pop();
                if(x.row != y.col){
                    flag = 1;
                    cout<<"error\n";
                    break;
                }
                ans += x.row * x.col * y.row;
                matrix z;
                z.row = y.row;
                z.col = x.col;
                s.push(z);
            }
            else{
                matrix temp;
                for(int i = 0;i<count;i++){
                    if((m+i)->c == command){
                        temp = *(m+i);
                        break;
                    }
                }
                s.push(temp);
            }
        }
        if(index==expression.length() && !flag) cout<<ans<<'\n';
    }
    while(!s.empty()) s.pop();
    free(m);
}