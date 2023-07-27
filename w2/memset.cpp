#include <stdio.h>
#include <cstring>
using namespace std;

int map[10][10];
int main()
{
    int i = 3;
    while(i--){
        if(memset(map, 0, sizeof(map))) printf("true\n");
        for(int i = 0; i<10; i++){
            for(int j = 0; j<10; j++){
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        for(int i = 0; i<10; i++){
            for(int j = 0; j<10; j++){
                map[i][j] = 1;
            }
        }
    }
}