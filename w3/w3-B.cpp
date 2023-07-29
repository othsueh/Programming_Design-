#include <stdio.h>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 1.796e+308
int nodeNum;
int visited[102];
double coordinates[102][2];
double length;

void dataClean()
{
    memset(visited, 0, sizeof(visited));
    fill(&coordinates[0][0], &coordinates[0][0]+sizeof(coordinates)/sizeof(coordinates[0][0]), MAX);
    return;
}

double distance(double *i, double *j)
{
    return sqrt(pow(i[0]-j[0],2)+pow(i[1]-j[1],2));
}

void miniPrime(int start, int num)
{
    length = 0;
    visited[start] = 1;
    int count = 1;
    while(count < num){
        double min = MAX;
        int candidate;
        for(int i = 0; i < num; i++){
            if(visited[i] == 1){
                for(int j = 0; j < num; j++){
                    if(i == j) continue;
                    double dis = distance(coordinates[i], coordinates[j]);
                    if(min != MAX && visited[j] == 0 && dis < min){
                        min = dis;
                        candidate = j;
                    }
                    else if(min == MAX && visited[j] == 0){
                        min = dis;
                        candidate = j;
                    }
                }
            }
        }
        visited[candidate] = 1;
        length += min;
        count++;
    }


}
int main()
{
    int dataSet;
    scanf("%d", &dataSet);
    for(int t = dataSet; t >0; t--){
        dataClean();
        scanf("%d", &nodeNum);
        for(int i = 0; i < nodeNum;i++) scanf("%lf %lf", &coordinates[i][0], &coordinates[i][1]);
        miniPrime(0, nodeNum);
        if(t == dataSet) printf("%.2lf\n", length);
        else printf("\n%.2lf\n", length);
    }
}