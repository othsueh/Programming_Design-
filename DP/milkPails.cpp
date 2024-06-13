#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
int dp[1005] = {0};

int main()
{
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);
  int x,y,m;
  scanf("%d %d %d", &x, &y, &m);
  dp[0] = 1;
  for(int i = 1; i <= m; i++){
    if(i >= x) dp[i] = dp[i] + dp[i-x];
    if(i >= y) dp[i] = dp[i] + dp[i-y];
  }
  for(int i = m; i >= 0; i--){
    if(dp[i]){
      printf("%d\n", i);
      break;
    }
  }
}
