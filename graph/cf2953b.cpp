#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define F first
#define S second
#define eb emplace_back
#define sz(x) (int)(x.size())
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORE(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

signed main ()
{
  int n;
  scanf("%d", &n);
  vector<vector<int>> dis(n+1 , vector<int>(n+1, 0));
  vector<int> a(n+1);
  vector<int> vis(n+1, 0);
  vector<ll> ans(n+1, 0);
  FORE(i,1,n){
    FORE(j,1,n){
      scanf("%d", &dis[i][j]);
    }
  }
  FORE(i,1,n)
    scanf("%d", &a[i]);
  for(int k = n; k >= 1; k--){
    vis[a[k]] = 1;
    FORE(i,1,n)
      FORE(j,1,n)
        dis[i][j] = min(dis[i][j], dis[i][a[k]] + dis[a[k]][j]);
    ll sum = 0;
    FORE(i,1,n)
      FORE(j,1,n)
        if(vis[i] && vis[j])
          sum += dis[i][j];
    ans[k] = sum;
  }
  FORE(i,1,n)
    printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
  

