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
  int r,c;
  scanf("%d %d", &r, &c);
  pii fresh, forest;
  scanf("%d %d %d %d", &fresh.F, &fresh.S, &forest.F, &forest.S);
  vector<vector<int>> g(r,vector<int>(c,-1));
  int n;
  scanf("%d", &n);
  FOR(i,0,n){
    int x,y,l;
    cin >> x >> y >> l;
    g[x][y] = l;
  }
  g[fresh.F][fresh.S] = g[forest.F][forest.S] = 0;
  vector<vector<int>> dist(r+2,vector<int>(c+2,1<<30));
  dist[fresh.F][fresh.S] = 0;
  priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
  pq.push({0,fresh});
  vector<pii> dir = {{0,1},{0,-1},{1,0},{-1,0}};
  while(!pq.empty()){
    int x = pq.top().S.F, y = pq.top().S.S;
    int d = pq.top().F;
    pq.pop();
    if(d!=dist[x][y]) continue;
    for(pii di: dir){
      int nx = x+di.F, ny = y+di.S;
      if(nx<0||nx>=r||ny<0||ny>=c) continue;
      if(g[nx][ny]==-1) continue;
      if(nx==forest.F&&ny==forest.S){
        printf("%d\n", dist[x][y]);
        return 0;
      }
      if(max(d,g[nx][ny])<dist[nx][ny]){
        dist[nx][ny] = max(d,g[nx][ny]);
        pq.push({dist[nx][ny],{nx,ny}});
      }
    }
  }
  printf("%d\n", dist[forest.F][forest.S]);
  return 0;
}
