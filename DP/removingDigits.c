#include<stdio.h>
#define min(a,b) (a<b?a:b)
int dp[1000001];


int process(int n)
{
  dp[0] = 0;
  for(int i=1; i <= n; i++){
    for(int k = i; k; k/=10){
      int d = k%10;
      if(d){
        dp[i] = min(dp[i], 1+dp[i-d]);
      }
    }
  }
  return dp[n];
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 1; i <= n; i++)
    dp[i] = 1e9;
  printf("%d\n",process(n));
}
