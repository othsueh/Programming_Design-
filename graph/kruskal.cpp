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
  vector<pari<int, int>> edge;
  FOR(i, 0, m){
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    edge.eb(w,{a,b});
  }
  sort(all(edge));
  ll ans = 0;
  int cnt = 0;
  for(auto i : edge){
    int a = i.S.F, b = i.S.S, w = i.F;
    if(dsu.findDSU(a) != dsu.findDSU(b)){
      dsu.unionDSU(a, b);
      ans += w;
      cnt++;
    }
  }
  if(cnt < n-1) printf("IMPOSSIBLE\n");
  else printf("%lld\n", ans);


  return 0;
}
