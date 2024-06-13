#include <iostream>
#include <utility>
#define pii pair<int,int>
using namespace std;

int main()
{
  pii l,b,r;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      char c;
      scanf("%c", &c);
      if(c == 'B'){
        b = {i,j};
      }else if(c == 'L'){
        l = {i,j};
      }else if(c == 'R'){
        r = {i,j};
      }
    }
  }
  int init = abs(l.first-b.first)+abs(l.second-b.second)-1;
  if((l.first == b.first && r.first == b.first)&&((l.second < r.second && r.second < b.second)||(b.second < r.second && r.second < l.second))){
    init += 2;
  }
  else if((l.first == b.first && r.first == b.first)&&((l.first < r.first && r.first < b.first)||(b.first < r.first && r.first < l.first))){
    init += 2;
  }
  printf("%d\n", init);
}
