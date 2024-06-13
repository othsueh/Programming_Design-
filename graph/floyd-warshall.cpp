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
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<vector<ll>> dis(n+1 , vector<ll>(n+1, 1LL<<60));
  FOR(i,0,m){
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    dis[a][b] = min(dis[a][b], c);
    dis[b][a] = min(dis[b][a], c);
  }
  FORE(i,1,n) dis[i][i] = 0;
  FORE(k,1,n) FORE(i,1,n) FORE(j,1,n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  while(q--){
    int a, b;
    scanf("%d %d", &a, &b);
    if(dis[a][b] == 1LL<<60) printf("-1\n");
    else printf("%lld\n", dis[a][b]);
  }
  return 0;
}
