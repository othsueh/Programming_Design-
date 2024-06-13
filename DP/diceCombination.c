//source : https://cses.fi/problemset/task/1633
#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
int dp[1000001] = {0};
int mod = 1000000007;
int ways(int n)
{
  dp[0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= 6; j++){
      if(j > i) break;
      dp[i] = (dp[i] + dp[i-j])%mod;
    }
  }
  return dp[n];
}
int main()
{
  int n;
  scanf("%d",&n);
  printf("%d\n",ways(n));
}
