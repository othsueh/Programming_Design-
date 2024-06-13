#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int num[7];
  for(int i=0;i<7;i++)
  {
    scanf("%d",&num[i]);
  }
  sort(num,num+7);
  printf("%d %d %d\n",num[0],num[1],num[6]-num[0]-num[1]);
}
