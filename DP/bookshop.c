#include <stdio.h>
int book[1001][2];
int dp[100001] = {0};

int maxPage(int n, int x)
{
  for(int i = 0; i <n; i++){
    for(int j = x; j >= book[i][0]; j--){
      if(dp[j] < dp[j-book[i][0]]+book[i][1])
        dp[j] = dp[j-book[i][0]]+book[i][1];
    }
  }
  return dp[x];
}
int main()
{
  int n,x;
  scanf("%d %d", &n,&x);
  for(int i=0; i <n; i++)
    scanf("%d", &book[i][0]);
  for(int i=0; i <n; i++)
    scanf("%d", &book[i][1]);
  printf("%d\n", maxPage(n,x));
}
