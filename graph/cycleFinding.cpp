#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
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
  vector<vector<pair<int,ll>>> g(n+1);
  FOR(i,0,m){
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    g[u].eb(v, w);
  }
  vector<ll> dist(n+1);
  vector<int> from(n+1,-1);
  int v = -1;
  FORE(t,1,n)
    FORE(i,1,n)
      for(pair<int,ll> j : g[i]){
        if(dist[j.F] > dist[i] + j.S){
          dist[j.F] = dist[i] + j.S;
          from[j.F] = i;
          if(t == n){
            v = j.F;
          }
        }
      }    
  if(v == -1){
    printf("NO\n");
    return 0;
  }
  vector<bool> vis(n+1,false);
  stack<int> cycle;
  while(!vis[v]){
    vis[v] = true;
    cycle.push(v);
    v = from[v];
  }
  vector<int> ans;
  ans.eb(v);
  while(1){
    ans.eb(cycle.top());
    if(cycle.top() == v) break;
    cycle.pop();
  }
  printf("YES\n");
  for(int i: ans) printf("%d ", i);
  printf("\n");
  return 0;
}
