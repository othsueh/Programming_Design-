#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define sz(x) (int)(x.size())
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i < b; i++)

using namespace std;
const int MAX = 1e6 + 5;
signed main()
{
  int n,m,a,b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  vector<vector<int>> path(n+1);
  vector<int> p(n+1);
  vector<bool> vis(n+1);
  FOR(i, 0, m){
    int u,v;
    scanf("%d %d", &u, &v);
    path[u].pb(v);
    path[v].pb(u);
  }
  FOR(i, 1, n+1) sort(all(path[i])),p[i] = i;
  queue<pii> q;
  int ans = 0;
  q.push({a,0});
  vis[a] = true;
  while(!q.empty()){
    int u = q.front().F, d = q.front().S;
    q.pop();
    if(u == b){
      ans = d-1;
      break;
    }
    for(auto v : path[u]){
      if(!vis[v]){
        vis[v] = true;
        p[v] = u;
        q.push({v,d+1});
      }
    }
  }
  printf("%d\n", ans);
  vector<int> pp;
  int now = b;
  pp.pb(now);
  while(now != p[now]){
    now = p[now];
    pp.pb(now);
  }
  reverse(all(pp));
  FOR(i, 0, sz(pp)){
    if(i==sz(pp)-1) printf("%d\n", pp[i]);
    else printf("%d-", pp[i]);
  }
}
