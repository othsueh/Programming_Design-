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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<pii>> g(n+1);
  FOR(i, 0, m){
    int u, v, w;
    cin >> u >> v >> w;
    g[u].eb(v, w);
  }
  vector<int> dist(n+1, 1 << 30);
  dist[1] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, 1});
  while(!pq.empty()){
    int now = pq.top().S;
    int d = pq.top().F;
    pq.pop();
    if(d!=dist[now]) continue;
    for(pii i: g[now]){
      printf("now: %d, d: %d, i.F: %d, i.S: %d\n", now, d, i.F, i.S);
      if(d + i.S < dist[i.F]){
        dist[i.F] = d + i.S;
        pq.push({dist[i.F], i.F});
    }
  }
  }
  FOR(i, 1, n+1) cout << dist[i] << " ";
  cout << "\n";
  return 0;
}
