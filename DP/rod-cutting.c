#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
int price[105];
int dp[1000000005] = {0};


int rodValue(int n, int m)
{
  for(int i = 1; i <=m ; i++){
    for(int j = 1; j <= n; j++){
      if(j >= i){
        dp[j] = max(dp[j], dp[j-i]+price[i]);
      }
    }
  } 
  return dp[n];
}
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; i++){
    scanf("%d", &price[i]);
  }
  printf("%d\n", rodValue(n,m));
}
