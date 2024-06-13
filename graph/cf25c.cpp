#include <iostream>
#include <cstring>
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
int dis[305][305] = {0};


signed main ()
{
  int n;
  scanf("%d", &n);
  FORE(i,1,n)
    FORE(j,1,n)
      scanf("%d", &dis[i][j]);
  int k;
  scanf("%d", &k);
  FOR(i,0,k){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(dis[a][b] > c){
      dis[a][b] = c;
      dis[b][a] = c;
      FORE(i,1,n)
        FORE(j,1,n){
          dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][a] + dis[a][j]);
          dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][b] + dis[b][j]);
        }
    }
    ll sum = 0;
    FORE(i,1,nm
      FORE(j,i+1,n)
        sum += dis[i][j];
    printf("%lld ", sum);
  }
  printf("\n");
}
