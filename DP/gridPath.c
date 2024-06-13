#include <stdio.h>
#define MOD 1000000007
int dp[1001][1001]={0};
char grid[1001][1001];
int ways(int n)
{
  for(int i = 0; i <n; i++){
    if(grid[0][i]!='*')
      dp[0][i]=1;
    else 
      break;
  }
  for(int i = 0; i <n; i++){
    if(grid[i][0]!='*')
      dp[i][0]=1;
    else 
      break;
  }
  for(int i = 1;i <n;i++){
    for(int j = 1;j < n;j++){
      if(grid[i][j]!='*')
        dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
      else 
        continue;
    }
  }
  return dp[n-1][n-1];

}
int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i <n;i++)
    for(int j=0; j<n;j++)
      scanf(" %c", &grid[i][j]);
  printf("%d\n", ways(n));
}
