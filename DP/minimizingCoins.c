//source:https://cses.fi/problemset/task/1634
#include <stdio.h>
#define min(a,b) ((a<b)?a:b)
int coins[101];
int dp[1000001];

void init()
{
  for(int i = 0; i < 1000001; i++){
    dp[i] = 1000001;
  }
}
int minCoins(int n, int x)
{
  dp[0] = 0;
  for(int i = 1; i <= x;i++){
    for(int j = 0; j <n; j++){
      if(coins[j] > i) continue;
      dp[i] = min(dp[i],dp[i-coins[j]]+1);
    }
  }
  return dp[x];
}
int main()
{
  init();
  int n, x;
  scanf("%d %d", &n, &x);
  for(int i = 0; i < n; i++){
    scanf("%d",&coins[i]);
  }
  minCoins(n,x);
  if(dp[x] == 1000001)
    printf("-1\n");
      else
    printf("%d\n",dp[x]);
}
