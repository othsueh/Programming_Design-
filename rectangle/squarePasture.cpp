#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int ori[4][2];
  for(int i = 0; i < 4; i++)
    scanf("%d %d", &ori[i][0], &ori[i][1]);
  int m1 = -1e8,m2 = 1e9,l1 = -1e8,l2 = 1e9;
  for(int i = 0; i < 4; i++){
    m1 = max(m1, ori[i][0]);
    m2 = min(m2, ori[i][0]);
    l1 = max(l1, ori[i][1]);
    l2 = min(l2, ori[i][1]);
  }
  int x = max(abs(m1-m2), abs(l1-l2));
  printf("%d\n", x*x);
}
