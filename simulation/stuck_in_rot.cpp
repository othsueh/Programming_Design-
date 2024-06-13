#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define trav(a, x) for (auto& a : x)
using namespace std;

struct Cow{
  int id;
  pii pos;
  Cow(pii coor,int i){
    id = i;
    pos = coor;
  }
};
bool cmp(const Cow &o, const Cow &t) {
	if (o.pos.first == t.pos.first) { return o.pos.second < t.pos.second; }
	return o.pos.first < t.pos.first;
}
bool cmp2(const Cow &o, const Cow &t){
  if (o.pos.second == t.pos.second) { return o.pos.first < t.pos.first; }
  return o.pos.second < t.pos.second;
}
vector <Cow> c_N;
vector <Cow> c_E;
signed main()
{
  int n;
  scanf("%d", &n);
  FOR(i, n){
    char dir;
    int x, y;
    cin >> dir >> x >> y;
    if(dir == 'N'){
      c_N.push_back(Cow({x,y},i));
    }else{
      c_E.push_back(Cow({x,y},i));
    }
  }
  sort(c_N.begin(), c_N.end(), cmp);
  sort(c_E.begin(), c_E.end(), cmp2);
  
  bool stopped[2501];
	int blame[2501];
	fill(stopped, stopped + n, false);
	fill(blame, blame + n, 1e9);
  trav(c1,c_E){
    trav(c2, c_N){
      if(!stopped[c2.id] && !stopped[c1.id] &&
          c1.pos.second >= c2.pos.second &&
          c1.pos.first <= c2.pos.first){
        int xlen = c2.pos.first - c1.pos.first;
        int ylen = c1.pos.second - c2.pos.second;
        if(ylen < xlen){
          stopped[c1.id] = true;
          blame[c1.id] = min(blame[c1.id],xlen);
        }else if(xlen < ylen){
          stopped[c2.id] = true;
          blame[c2.id] = min(blame[c2.id],ylen);
        }
      }
    }
  }
  FOR(i, n){
    if(blame[i] == 1e9){
      printf("Infinity\n");
    }else printf("%d\n",blame[i]);
  }

}
