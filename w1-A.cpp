#include <iostream>
#include <deque>
using namespace std;
void CallandDelete(int *index);
struct node{
    int u;
    int w;
    int val;
};
int main()
{
    //topic : speed up the input
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    deque<int>d[n+1];
    while(q){
        int command = 0;
        cin>>command;
        switch(command){
            case 1:
            node c1;
            cin >> c1.u >> c1.w>>c1.val;
            if(c1.w) d[c1.u].push_back(c1.val);
            else d[c1.u].push_front(c1.val);
            break;
            case 2:
            node c2;
            cin >> c2.u >> c2.w;
            if(d[c2.u].empty()) cout<<'\n';
            else {
                if(c2.w){
                    cout<<d[c2.u].back()<<'\n';
                    d[c2.u].pop_back();
                }
                else{
                    cout<<d[c2.u].front()<<'\n';
                    d[c2.u].pop_front();
                }
            }
            break;
            case 3: 
            break;
            default:
            break;
        }
    }
}

void CallandDelete(int *index){
    if(*index != 0){
    cout<<*index<<'\n';
    *index = 0;
    }
    else cout<<-1<<'\n';
}