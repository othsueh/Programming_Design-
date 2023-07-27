#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
    int shop;
    while(scanf("%d", &shop)==1){
        map<string, int> shopRank;
        string s;
        for(int i = 0; i < shop; i++){
            cin>>s;
            shopRank[s] = 0;
        }
        int ranking;
        scanf("%d",&ranking);
        for(int i = 0; i < ranking; i++){
            int score;
            string shopName;
            for(int j= 0; j<shop;j++){
                cin>>score>>shopName;
                shopRank[shopName] += score;
            }
            int rank = 1;
            map<string, int> :: iterator it;
            for(it=shopRank.begin();it!=shopRank.end();it++){
                if(it->second > shopRank["memory"]){
                    rank++;
                }
            }
            printf("%d\n",rank);
        }
    }
}