#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

typedef struct{
    int start, end;
}connect;

int main()
{
    int town, road;
    while(scanf("%d%d",&town, &road) == 2 && town){
        set<int> town_set[1000];
        for(int i = 0; i < town; i++){
            town_set[i].insert(i+1);
        }
        connect roads[10000];
        for(int i = 0; i < road; i++){
            int temp_a, temp_b;
            scanf("%d%d",&temp_a, &temp_b);
            if(temp_a >= temp_b){
                roads[i].start = temp_b;
                roads[i].end = temp_a;
            }
            else{
                roads[i].start = temp_a;
                roads[i].end = temp_b;
            }
        }
        for(int i = 0; i < road; i++){
            set<int>::iterator s1, s2;
            int town1, town2;
            for(town1 = 0; town1 < town; town1++){
                s1 = town_set[town1].find(roads[i].start);
                printf("s1 = %d town_set[%d].end() = %d\n",*s1 , town1+1,*town_set[town1].end());
                if(s1 != town_set[town1].end()){
                    break;
                }
            }
            for(town2 = 0; town2 < town; town2++){
                s2 = town_set[town2].find(roads[i].end);
                printf("s2 = %d town_set[%d].end() = %d\n", *s2,town2+2, *town_set[town2].end());
                if(s2 != town_set[town2].end()){
                    break;
                }
            }
            if(town1 != town2){
                town_set[town2].insert(town_set[town1].begin(), town_set[town1].end());
                town_set[town1].clear();
            }
        }
        int count = 0;
        for(int i = 0; i < town; i++){
            if(!town_set[i].empty()) count++;
        }
        printf("%d\n", count-1);
    }
}