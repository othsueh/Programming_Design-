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
int n, m;
vector<vector<pii>> g;
signed main ()
{
  scanf("%d%d", &n, &m);
  g.resize(n+1);
  FOR(i, 0, m){
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    g[a].eb(b, w);
    g[b].eb(a, w);
  }
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, 1});
  ll ans = 0;
  int ok = 0;
  vector<bool> vis(n+1);
  while(!pq.empty()){
    int now = pq.top().S;
    int d = pq.top().F;
    pq.pop();
    if(vis[now]) continue;
    vis[now] = true;
    ok++;
    ans += d;
    for(pii i : g[now]){
      int to = i.F;
      int w = i.S;
      if(!vis[to]) pq.push({w, to});
    }
  }
  if(ok < n) printf("IMPOSSIBLE\n");
  else printf("%lld\n", ans);
  return 0;
}
