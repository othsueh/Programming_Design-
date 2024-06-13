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

vector<int> dsu,sz;
void initDSU(int n)
{
  dsu.resize(n + 1);
  sz.resize(n + 1);
  FORE(i, 1, n) dsu[i] = i;
}
int findDSU(int a)
{
  if(dsu[a] != a) dsu[a] = findDSU(dsu[a]);
  return dsu[a];
}
void union (int a, int b)
{
  a = findDSU(a);
  b = findDSU(b);
  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);
  dsu[b] = a;
  sz[a] += sz[b];
}
signed main ()
{
  

  return 0;
}
