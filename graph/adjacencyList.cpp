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
#define maxn 100005
using namespace std;

vector<bool> vis;
vector<vector<pii>> g;

void dfs(int u)
{
  vis[u] = true;
  for(auto i : g[u]){
    if(!vis[i.F]) dfs(i.F);
  }
  printf("%d\n", u);
}

void bfs(int u)
{
  queue<int> q;
  q.push(u);
  while(!q.empty()){
    int v = q.front();
    printf("%d\n", v);
    q.pop();
    for(auto i : g[v]){
      if(!vis[i.F]){
        vis[i.F] = true;
        q.push(i.F);
      }
    }
  }
}
signed main ()
{
  int n,m;
  scanf("%d %d", &n, &m);
  g = vector<vector<pii>>(n+1);
  vis = vector<bool>(n+1,false);
  FOR(i,0,m){
    int u,v,w;
    scanf("%d %d %d", &u, &v, &w);
    g[u].pb({v,w});
  }
  bfs(1);
  return 0;
}
