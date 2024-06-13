#include <iostream>
#include <vector>
#define MAX 100005
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define ll long long
#define FOR(i, a, b) for(int i = a; i < b; i++)

using namespace std;
const int MOD = 1e9 + 7;
vector<int> v[MAX];
bool vis[MAX] = {false};

ll pow_fast(ll a, ll k){
  ll ans = 1;
  while(k){
    if(k&1) ans = (ans*a) % MOD;
    a = (a*a) % MOD;
    k >>= 1;
  }
  return ans;
}
void dfs(int s, ll &ans)
{
  vis[s] = true;
  ans++;
  int l = v[s].size();
  FOR(i, 0, l){
    if(!vis[v[s][i]]){
      dfs(v[s][i], ans);
    }
  }
}
int main()
{
  ll n,k;
  scanf("%d %d", &n, &k);
  FOR(i, 1, n) {
    int u,y,x;
    scanf("%d %d %d", &u, &y, &x);
    if(x) continue;
    v[y].pb(u);
    v[u].pb(y);
  }
  ll ans = pow_fast(n, k);
  FOR(i, 1, (n+1)){
    if(!vis[i]){
      ll temp = 0;
      dfs(i, temp);
      ans = (ans - pow_fast(temp,k) + MOD)%MOD;
    }
  }
  printf("%lld\n", ans);
}
