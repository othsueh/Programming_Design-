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
#define MOD 1000000007

using namespace std;

signed main ()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> g(n+1);
  vector<int> degree(n+1);
  while(m--){
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    degree[b]++;
  }
  queue<int> q;
  vector<int> dp(n+1);
  FORE(i,1,n){
    if(degree[i] == 0) q.push(i);
  }
  dp[1] = 1;
  while(!q.empty()){
    int now = q.front();
    q.pop();
    for(int i: g[now]){
      if(--degree[i] == 0) q.push(i);
      dp[i] = (dp[i] + dp[now]) % MOD;
    }
  }
  printf("%d\n",dp[n]);
  return 0;
}
