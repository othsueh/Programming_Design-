#include <stdio.h>
#include <cstring>
using namespace std;
int graph[27][27];
int y, x, flag;
int dx[8]={-2,-2,-1,-1, 1,1, 2,2};
int dy[8]={-1, 1,-2, 2,-2,2,-1,1};
int visit[27][2];

void dfs(int row, int col, int step)
{
    if(flag) return;
    graph[row][col] = 1;
    visit[step][0] = row;
    visit[step][1] = col;
    if(step==x*y){
        flag = 1;
        for(int i=1; i<=step; i++){
            printf("%c%d", visit[i][0]+'A'-1, visit[i][1]);
        }
        printf("\n\n");
        return;
    }
    for(int i = 0; i < 8;i++){
        int nex = row + dx[i];
        int ney = col + dy[i];
        if(nex <= x && nex >= 1 && ney <= y && ney >= 1 && !graph[nex][ney]){
            dfs(nex, ney, step+1);
        }
    }
    //! If not available, then set the point to 0
    graph[row][col] = 0;

}
int main()
{
    int testCase;
    scanf("%d", &testCase);
    for(int i = 1; i<=testCase; i++){
        memset(graph, 0, sizeof(graph));
        flag = 0;
        scanf("%d %d", &y, &x);
        printf("Scenario #%d:\n", i);
        dfs(1,1,1);
        if(!flag) printf("impossible\n\n");
    }
}

// vector<char> visited;
// int p, q,flag;
// int dx[8] = {-1,-2,-2,-1,1,2,2,1};
// int dy[8] = {2,1,-1,-2,-2,-1,1,2};
// void dfs(int x, int y, int step)
// {
//     visited.push_back('A' + y - 1);
//     visited.push_back('0' + x);
//     graph[x][y] = 1;
//     if(step == p*q){
//         flag = 1;
//         for(int i=0; i < visited.size(); i+=2){
//             printf("%c%c", visited[i], visited[i+1]);
//         }
//         printf("\n");
//         return;
//     }
//     else{
//         for(int i = 0; i < 8; i++){
//             int nex = x + dx[i];
//             int ney = y + dy[i];
//             if(nex < 1 || nex > p || ney < 1 || ney > q) continue;
//             if(!graph[nex][ney]){
//                 dfs(nex, ney, step+1);
//             }
//         }
//     }
//     //runtime error way : keep recursion && using vector
// }
// int main()
// {
//     int testCase;
//     scanf("%d", &testCase);
//     for(int c = 1; c <= testCase; c++){
//         flag = 0;
//         memset(graph, 0, sizeof(graph));
//         fill(visited.begin(), visited.end(), 0);
//         scanf("%d %d", &p, &q);
//         printf("Scenario #%d:\n", c);
//         dfs(1,1,1);
//         if(!flag) printf("impossible\n");
//         visited.clear();
//         if(c != testCase) printf("\n");
//     }
// }


