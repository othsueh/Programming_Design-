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

int n, m;
int cnt;

struct DSU{
  vector<int> dsu;
  explicit DSU(int n): dsu(n+1){
    FORE(i, 1, n) dsu[i] = i;
  }
  int findDSU(int a){
    if(dsu[a] != a) dsu[a] = findDSU(dsu[a]);
    return dsu[a];
  }
  void unionDSU(int a, int b){
    a = findDSU(a);
    b = findDSU(b);
    if(a == b) return ;
    dsu[b] = a;
    cnt--;
  }
};
signed main ()
{
  scanf("%d%d", &n, &m);
  DSU dsu(n);
  cnt = n;
  vector<pii> edge(m+1);
  FORE(i, 1, m){
    int a, b;
    scanf("%d%d", &a, &b);
    edge[i] = {a, b};
  }
  vector<bool> del(m+1);
  int q;
  scanf("%d", &q);
  vector<int> query(q),answer(q);
  FOR(i,0,q){
    scanf("%d", &query[i]);
    del[query[i]] = true;
  }
  FORE(i, 1, m) if(!del[i]) dsu.unionDSU(edge[i].F, edge[i].S);
  for(int i = q-1; i >= 0; i--){
    answer[i] = cnt;
    int u = edge[query[i]].F, v = edge[query[i]].S;
    dsu.unionDSU(u, v);
  }
  
  for(int i : answer) printf("%d\n", i);
  return 0;
}
