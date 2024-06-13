#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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

void solveDFS()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n+1);
  vector<int> t(n+1);
  vector<int> vis(n+1);
  vector<int> dp(n+1);
  vector<int> deg(n+1);
  FORE(i,1,n){
    cin >> t[i];
    int k;
    cin >> k;
    while(k--)
    {
      int x;
      cin >> x;
      g[i].eb(x);
      deg[x]++;
    }
  }
  stack<int> s;
  FORE(i,1,n){
    if(deg[i] == 0) s.push(i);
  }
  while(!s.empty())
  {
    int now = s.top();
    s.pop();
    if(vis[now]) continue;
    vis[now] = 1;
    dp[now] += t[now];
    for(int i: g[now])
    {
      if(!vis[i]){
        dp[i] = max(dp[i], dp[now]);
        s.push(i);
      }
    }
  }
  printf("%d\n", *max_element(all(dp)));
}
void solveBFS()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n+1);
  vector<int> t(n+1);
  vector<int> deg(n+1);
  FOR(i,1,n+1)
  {
    cin >> t[i];
    int k;
    cin >> k;
    while(k--)
    {
      int x;
      cin >> x;
      g[i].eb(x);
      deg[x]++;
    }
  }
  vector<int> dp(n+1);
  queue<int> q;
  FOR(i,1,n+1)
  {
    if(deg[i] == 0) q.push(i);
  }
  while(!q.empty()){
    int now = q.front();
    q.pop();
    dp[now] += t[now];
    for(int i: g[now])
    {
      dp[i] = max(dp[i], dp[now]);
      deg[i]--;
      if(deg[i] == 0) q.push(i);
    }
  }
  printf("%d\n", *max_element(all(dp)));
}
signed main()
{
  int time;
  scanf("%d", &time);
  while(time--) solveDFS();
  return 0;
}
