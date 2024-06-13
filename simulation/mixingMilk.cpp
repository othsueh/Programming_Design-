#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
using namespace std;

signed main()
{
  vector<pii> milk(3);
  for(int i = 0; i < 3; i++){
    scanf("%d %d", &milk[i].first, &milk[i].second);
  }
  for(int i = 0; i < 100; i++){
    switch(i%3){
      case 0:
        if(milk[0].second + milk[1].second > milk[1].first){
          milk[0].second = milk[0].second + milk[1].second - milk[1].first;
          milk[1].second = milk[1].first;
        }else{
          milk[1].second += milk[0].second;
          milk[0].second = 0;
        }
        break;
      case 1:
        if(milk[1].second + milk[2].second > milk[2].first){
          milk[1].second = milk[1].second + milk[2].second - milk[2].first;
          milk[2].second = milk[2].first;
        }else{
          milk[2].second += milk[1].second;
          milk[1].second = 0;
        }
        break;
      case 2:
        if(milk[2].second + milk[0].second > milk[0].first){
          milk[2].second = milk[2].second + milk[0].second - milk[0].first;
          milk[0].second = milk[0].first;
        }else{
          milk[0].second += milk[2].second;
          milk[2].second = 0;
        }
        break;
      default:
        break;
    }
  }
  for(int i = 0; i < 3; i++){
    printf("%d\n",milk[i].second);
  }
}
