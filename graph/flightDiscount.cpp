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
  vector<vector<ll>> dist(n+1,vector<ll>(2,1e18));
  FOR(i, 0, m){
    int u, v, w;
    cin >> u >> v >> w;
    g[u].eb(v, w);
  }
  priority_queue<pair<ll,pii>, vector<pair<ll,pii>>, greater<pair<ll,pii>>> pq;
  dist[1][0] = 0;
  pq.push({0,{1,0}});
  while(!pq.empty()){
    pii now = pq.top().S;
    ll d = pq.top().F;
    pq.pop();
    if(d > dist[now.first][now.S]) continue;
    for(pii i: g[now.F]){
      if(dist[i.F][now.S] > d + i.S){
        dist[i.F][now.S] = d + i.S;
        pq.push({dist[i.F][now.S],{i.F,now.S}});
      }
      if(now.S == 0 && dist[i.F][1] > d + i.S/2){
        dist[i.F][1] = d + i.S/2;
        pq.push({dist[i.F][1],{i.F,1}});
      }
    }
  }
  printf("%lld\n", dist[n][1]);

  return 0;
}
