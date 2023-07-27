#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    int n, k;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(scanf("%d%d",&n,&k)==2){
        while(n){
            --n;
            char command;
            scanf(" %c",&command);
            if(command == 'I'){
                int data;
                scanf("%d",&data);
                pq.push(data);
                if(pq.size() > k) pq.pop();
            }
            else{
                cout<<pq.top()<<'\n'; 
            }
        }
        while(!pq.empty()) pq.pop();
    }

}