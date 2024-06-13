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
  vector<vector<pii>> g;
  int n;
  vector<int> dis;
  FOR(i,0,n)
    FORE(j,1,n)
      for(pii k : g[i]){
        if(dis[k.F] > dis[j] + k.S){
          if(i == n-1){
            cout << "Negative cycle detected\n";
            return 0;
          }
          dis[k.F] = dis[j] + k.S;
        }
      }    
  

  return 0;
}
