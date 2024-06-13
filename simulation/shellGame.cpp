#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  vector<int> a = {1,0,0};
  vector<int> b = {0,1,0};
  vector<int> c = {0,0,1};
  int score[3] = {0};
  for(int i = 0; i < n; i++){
    int x,y,g;
    scanf("%d %d %d",&x,&y,&g);
    swap(a[x-1],a[y-1]);
    swap(b[x-1],b[y-1]);
    swap(c[x-1],c[y-1]);
    if(a[g-1] == 1)
      score[0]++;
    if(b[g-1] == 1)
      score[1]++;
    if(c[g-1] == 1)
      score[2]++;
  }
  printf("%d\n",max({score[0],score[1],score[2]}));

}
