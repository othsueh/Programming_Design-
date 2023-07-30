#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#define MAX 65535
#define DMAX 1.796e+308
using namespace std;

int coordinates[501][2];
int visited[501];
priority_queue<double, vector<double>, less<double> > pq;
void dataClean()
{
    memset(visited, 0, sizeof(visited));
    fill(&coordinates[0][0], &coordinates[0][0]+sizeof(coordinates)/sizeof(coordinates[0][0]), MAX);
    pq = priority_queue<double, vector<double>, less<double> >();
    return;
}
void miniPrime(int start, int num, int snum)
{
    visited[start] = 1;
    int count = 1;
    int candidate;
    while(count < num){
        double min = DMAX;
        for(int i = 0; i < num; i++){
            if(visited[i]==1){
                for(int j =0; j<num;j++){
                    if(i == j) continue;
                    double length = sqrt(pow(coordinates[i][0]-coordinates[j][0],2)+pow(coordinates[i][1]-coordinates[j][1],2));
                    if(min != DMAX && visited[j] == 0 && length < min){
                        min = length;
                        candidate = j;
                    }
                    else if(min == DMAX && visited[j] == 0){
                        min = length;
                        candidate = j;
                    }
                }
            }
        }
        visited[candidate] = 1;
        pq.push(min);
        count++;
    }
    while(--snum) pq.pop();
    printf("%.2lf\n", pq.top());
}
int main()
{
    int dataSet;
    scanf("%d", &dataSet);
    while(dataSet--){
        dataClean();
        int sateliteNum, portNum;
        scanf("%d %d", &sateliteNum, &portNum);
        for(int i = 0; i < portNum; i++) scanf("%d %d", &coordinates[i][0], &coordinates[i][1]);
        miniPrime(0, portNum, sateliteNum);  
    }
}