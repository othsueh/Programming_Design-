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
  int n,m,k;
  scanf("%d %d %d", &n, &m, &k);
  vector<vector<pii>> g(n+1);
  FOR(i,0,m){
    int u,v,w;
    scanf("%d %d %d", &u, &v, &w);
    g[u].eb(v,w);
  }
  vector<vector<ll>> ans(n+1,vector<ll>());
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
  pq.push({0,1});
  while(!pq.empty()){
    int now = pq.top().S;
    ll d = pq.top().F;
    pq.pop();
    if(ans[now].size()>=k) continue;
    ans[now].eb(d);
    for(pii i: g[now]){
        pq.push({d+i.S,i.F});
    }
  }
  FOR(i,0,k){
    printf("%ld ", ans[n][i]);
  }
  printf("\n");
  return 0;
}
