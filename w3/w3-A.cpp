#include <stdio.h>
#include <cstring>
#include <vector>
#define MAX 65535
using namespace std;

int map[27][27];
int visited[27];
int length;
void dataClean()
{
    memset(visited, 0, sizeof(visited));
    fill(&map[0][0], &map[0][0]+sizeof(map)/sizeof(map[0][0]), MAX);
    for(int i = 0; i < 27; i++) map[i][i] = 0;
    length = 0;
    return;
}
void miniPrime(int start, int num)
{
    int count = 1;
    visited[start] = 1;
    while(count < num){
        int min = MAX;
        int candidate;
        for(int i = 1; i <= num;i++){
            if(visited[i] == 1){
                for(int j = 1;j <= num; j++){
                    if(i == j) continue;
                    if(min != MAX && visited[j] == 0 && map[i][j] < min){
                        min = map[i][j];
                        candidate = j;
                    }
                    else if(min == MAX && visited[j] == 0){
                        min = map[i][j];
                        candidate = j;
                    }
                }
            }
        }
        visited[candidate] = 1;
        length += min;
        count++;
    }
    printf("%d\n", length);
    
}
int main()
{
    int dataSet;
    while(scanf("%d", &dataSet) == 1 && dataSet){
        dataClean();
        for(int i = 0; i < dataSet-1; i++){
            char headTown;
            int villageNum;
            scanf(" %c %d", &headTown, &villageNum);
            if(villageNum == 0) continue;
            else{
                for(int j =0; j < villageNum; j++){
                    char villageName;
                    int cost,x,y;
                    scanf(" %c %d", &villageName, &cost);
                    x = headTown-'A' + 1; 
                    y = villageName-'A' + 1;
                    map[x][y] = cost;
                    map[y][x] = cost; 
                }
            }
        }
        miniPrime(1, dataSet);
    }
}

// subtopic : testLoop
    // for(int i = 1; i <= dataSet;i++){
    //     for(int j = 1; j <= dataSet; j++){
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }