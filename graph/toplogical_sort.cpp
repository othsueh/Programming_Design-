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
vector<vector<int>> g;
vector<int> indegree;
vector<int> vis;
queue<int> q;
vector<int> ans;

void dfs(int u)
{
  vis[u] = 1;
  for(auto i: g[u]){
    if(vis[i] == 1){
      printf("Not a DAG\n");
      exit(0);
    }
    if(!vis[i]) dfs(i);
  }
  ans.pb(u);
  vis[u] = 2;
}
void topological_sort(int n)
{
  FOR(i,1,n+1){
    if(indegree[i] == 0) q.push(i);
  }
  while(!q.empty()){
    int u = q.front();
    q.pop();
    ans.pb(u);
    for(auto v : g[u]){
      indegree[v]--;
      if(indegree[v] == 0) q.push(v);
    }
  }
}
signed main ()
{

  int n, m;
  scanf("%d %d", &n, &m);
  g = vector<vector<int>>(n+1);
  indegree = vector<int>(n+1,0);
  vis = vector<int>(n+1,0);
  FOR(i,0,m){
    int u,v;
    scanf("%d %d", &u, &v);
    g[u].pb(v);
    indegree[v]++;
  }
  dfs(1);
  for(auto i : ans) printf("%d ", i);
  return 0;
}
