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

vector<int> dfs_array; 
vector<bool> dfs_visit(100005, 0);

void dfs(int u, vector<vector<int>> g){
  dfs_visit[u] = 1;
  for(int v: g[u])
    if(!dfs_visit[v])
      dfs(v, g);
  dfs_array.eb(u);
}

signed main ()
{
  int n,m;  
  scanf("%d %d", &n, &m);
  vector<vector<pii>> g(n+1);
  vector<vector<int>> trans(n+1);
  vector<ll> dis(n+1, -1e18);
  vector<bool> vis(n+1, 0);
  FOR(i,0,m){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    g[a].eb(b,c);
    trans[b].eb(a);
  }
  dis[1] = 0;
  FORE(t,1,n)
    FORE(i,1,n)
      if(dis[i] != -1e18)
        for(pii j: g[i]){
          if(dis[j.F] < dis[i] + j.S){
            if(t == n){
              vis[j.F] = 1;
              break;
            }
            dis[j.F] = dis[i] + j.S;
          }
        }
  dfs(n,trans);
  for(int i:dfs_array){
    if(vis[i]){
      printf("-1\n");
      return 0;
    }
  }
  printf("%lld\n", dis[n]);
  return 0;
}
