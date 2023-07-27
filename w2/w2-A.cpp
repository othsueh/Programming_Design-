#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
bool graph[9][9];
vector<char> visited;
int p, q,flag;
int dx[8] = {-2,-2,-1,-1,2,2,1,1};
int dy[8] = {-1,1,-2,2,-1,1,-2,2};
void dfs(int x, int y, int step)
{
    //new way
    if(flag) return;
    visited.push_back('A' + y - 1);
    visited.push_back('0' + x);
    graph[x][y] = 0;
    if(step == p*q){
        flag = 1;
        for(int i=0; i < visited.size(); i+=2){
            printf("%c%c", visited[i], visited[i+1]);
        }
        printf("\n");
        return;
    }
    //runtime error way
    for(int i = 0; i < 8; i++){
        int nex = x + dx[i];
        int ney = y + dy[i];
        if(nex < 1 || nex > p || ney < 1 || ney > q) continue;
        if(graph[nex][ney]){
            dfs(nex, ney, step+1);
        }
    }
}
int main()
{
    int testCase;
    scanf("%d", &testCase);
    for(int c = 1; c <= testCase; c++){
        flag = 0;
        memset(graph, 0, sizeof(graph));
        fill(visited.begin(), visited.end(), 0);
        scanf("%d %d", &p, &q);
        for(int i=1; i <= p; i++){
            for(int j=1; j <= q; j++){
                graph[i][j] = 1;
            }
        }
        printf("Scenario #%d:\n", c);
        dfs(1,1,1);
        if(!flag) printf("impossible\n");
        visited.clear();
        printf("\n");
    }
}