//source : https://atcoder.jp/contests/dp/tasks/dp_e
#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
int array[105][2];
int dp[1000000005] = {0};
int knapstack(int n, int m)
{
  for(int i = 0; i < n; i++){
    for(int j = m; j > 0; j--){
      if(j >= array[i][0]){
        dp[j] = max(dp[j],dp[j-array[i][0]]+array[i][1]);
      }
    }
  }
  return dp[m];
}
void clear(int m){
  for(int i = 0; i <= m; i++){
    dp[i] = 0;
  }
}
int main() {
  int t;
  scanf("%d",&t);
  while(t--){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++){
      scanf("%d %d",&array[i][0],&array[i][1]);
    }
    printf("%d\n",knapstack(n,m)); 
    clear(m); 
  }
}
