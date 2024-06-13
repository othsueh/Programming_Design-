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
#define MAX 2147483647
using namespace std;
signed main ()
{
  int n;
  scanf("%d",&n);
  vector<string> a(n+1);
  for(int i = 1 ; i <= n; i++) cin >> a[i], a[i] = " "+a[i];
  vector<pii> d = {{1,0},{-1,0},{0,1},{0,-1}};
  vector<vector<int>> dis(n+1, vector<int>(n+1, MAX));
  dis[2][2] = 1;
  queue<pii> q;
  q.push({2,2});
  while(!q.empty()){
    pii now = q.front();
    q.pop();
    for(pii i:d){
      int nx = now.F+i.F, ny = now.S+i.S;
      if(a[nx][ny] == '#' || dis[nx][ny] != MAX) continue;
      dis[nx][ny] = dis[now.F][now.S]+1;
      q.push({nx,ny});
    }
  }
  if(dis[n-1][n-1] == MAX) cout << "No solution!";
  else cout << dis[n-1][n-1];
  

  return 0;
}
