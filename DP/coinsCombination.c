#include <stdio.h>
const int mod = 1e9+7;
int money[101];
int dp[1000001] = {0};

int combination(int n, int m)
{
  dp[0] = 1;
  for(int i = 1; i <= m; i++){
    for(int j = 0; j < n;j++){
      if(money[j] <= i){
        dp[i] = (dp[i] + dp[i-money[j]])%mod;
      }
    } 
  }
  return dp[m];
}
int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0; i < n; i ++){
    scanf("%d",&money[i]);
  }
  printf("%d\n",combination(n,m));
}
