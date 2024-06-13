#include <iostream>

using namespace std;

int main()
{
  int n;
  int barnRoom[1001];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &barnRoom[i]);
  }
  int minDist = 1e9;
  for(int entry = 0; entry < n; entry++){
    int sum = 0;
    for(int i = 0; i < n; i++){
      int locate = (entry + i) % n;
      sum += i * barnRoom[locate];
    }
    minDist = min(minDist, sum);
  }
  printf("%d\n", minDist);
}
