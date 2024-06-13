//reference: https://www.cnblogs.com/dgsvygd/p/16579729.html
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define pii pair<int, int>
#define F first
#define S second
#define eb emplace_back
#define sz(x) (int)(x.size())
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORE(i, a, b) for(int i = a; i <= b; i++)
#define MAXN 1000005
using namespace std;
int dfn[MAXN], low[MAXN], cnt = 0;
int scc[MAXN],scc_cnt = 0;
bool vis[MAXN] = {0}; 
ll val[MAXN], val_c[MAXN], dp[MAXN];
vector<vector<int>> g(MAXN);
vector<vector<int>> gc(MAXN);
stack<int> st;
void dfn_low(int u)
{
  vis[u] = 1;
  st.push(u);
  dfn[u] = low[u] = ++cnt;
  for(int v: g[u]){
    if(!dfn[v]){
      dfn_low(v);
      low[u] = min(low[u], low[v]);
    }else if(vis[v]){
      low[u] = min(low[u], dfn[v]);
    }
  }
  if(dfn[u] == low[u]){
    scc_cnt++;
    while(st.top() != u){
      int x = st.top();
      st.pop();
      scc[x] = scc_cnt;
      vis[x] = 0;
      val_c[scc_cnt] += val[x];
    }
    val_c[scc_cnt] += val[u];
    scc[u] = scc_cnt;
    vis[u] = 0;
    st.pop();
  }
}
void build(int n)
{
  FORE(i,1,n){
    for(int v: g[i]){
      if(scc[i] != scc[v]){
        gc[scc[v]].eb(scc[i]);
      }
    }
  }
}
ll dps(int u)
{
  if(dp[u])
    return dp[u];
  ll ans = 0;
  for(int v: gc[u]){
    ans = max(ans, dps(v));
  }
  return dp[u] = ans + val_c[u];
}
signed main ()
{
  int n, m;
  scanf("%d%d", &n, &m);
  FORE(i,1,n){
    scanf("%d", &val[i]);
  }
  FOR(i,0,m){
    int u,v;
    scanf("%d%d", &u, &v);
    g[u].eb(v);
  }
  FORE(i,1,n)
    if(!dfn[i])
      dfn_low(i);
  build(n);
  ll ans = 0;
  for(int i = 1; i <= scc_cnt; i++){
    ans = max(ans, dps(i));
  }
  printf("%lld\n", ans);
  return 0;
}
