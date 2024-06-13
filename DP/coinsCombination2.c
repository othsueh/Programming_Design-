#include <stdio.h>
const int mod = 1e9+7;
int money[101];
int dp[1000001] = {0};

int ways(int n, int m)
{
  dp[0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 1; j <= m; j++){
      if(money[i] <= j){
        dp[j] = (dp[j] + dp[j-money[i]])%mod;
      }
    }
  }
  return dp[m]; 
}

int main()
{
  int m, n;
  scanf("%d %d",&n,&m);
  for(int i = 0; i < n; i++){
    scanf("%d",&money[i]);
  }
  printf("%d\n",ways(n,m));
}
