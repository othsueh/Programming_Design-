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
  vector<vector<pair<int, ll>>> g(n+1);
  FOR(i,0,m){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    g[a].eb(b, c);
  }
  queue<int> q;
  vector<ll> dis(n+1, 1LL<<60);
  vector<bool> inq(n+1, 0);
  vector<int> cnt(n+1, 0);
  dis[1] = 0; 
  inq[1] = 1;
  q.push(1);
  while(!q.empty()){
    int now = q.front();
    q.pop();
    cnt[now]++;
    if(cnt[now] > n){
      cout << "Negative cycle detected\n";
      return 0;
    }
    inq[now] = 0;
    for(pair<int, ll> i: g[now]){
      if(dis[i.F] > dis[now] + i.S){
      dis[i.F] = dis[now] + i.S;
      if(!inq[i.F]){
        q.push(i.F);
        inq[i.F] = 1;
      }
      }
    }
  }

  return 0;
} 
