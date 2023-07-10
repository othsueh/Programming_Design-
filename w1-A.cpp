#include <iostream>
#include <deque>
#define N 150000
using namespace std;
deque<int>d[N+1];
struct node{
    int u;
    int w;
    int val;
};
int main()
{
    //topic : speed up the input
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF){
        for(int i = 0; i<=n; i++) d[i].clear();
        while(q){
            --q;
            int command = 0;
            scanf("%d",&command);
            switch(command){
                case 1:
                    node c1;
                    scanf("%d%d%d",&c1.u,&c1.w,&c1.val);
                    if(c1.w) d[c1.u].push_back(c1.val);
                    else d[c1.u].push_front(c1.val);
                break;
                case 2:
                    node c2;
                    scanf("%d%d",&c2.u,&c2.w);
                    if(d[c2.u].empty()) cout<<-1<<'\n';
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
                    node c3;
                    scanf("%d%d%d",&c3.u,&c3.w,&c3.val);
                    if(c3.val) {
                        while(!d[c3.w].empty()){
                            d[c3.u].push_back(d[c3.w].back());
                            d[c3.w].pop_back();
                        }
                    }
                    else{
                        while(!d[c3.w].empty()){
                        d[c3.u].push_back(d[c3.w].front());
                        d[c3.w].pop_front();
                    }}
                    break;
                default:
                    break;
        }
        }
    }
}
