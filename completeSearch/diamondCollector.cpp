#include <iostream>
#include <algorithm>

using namespace std;

int arr[1005] = {0};
signed main()
{
  freopen("diamond.in","r",stdin);
  freopen("diamond.out","w",stdout);
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0; i < n; i++){
    scanf("%d",&arr[i]);
  }
  int most = 0;
  for(int i = 0; i < n; i++){
    int cnt = 0;
    for(int j = 0; j < n; j++){
      if(arr[j] >= arr[i] && arr[j] <= arr[i]+m){
        cnt++;
      }
    }
    most = max(most,cnt);
  }
  printf("%d\n",most);
}
