#include <iostream>
using namespace std;

int main()
{
  int m,n,f;
  scanf("%d %d %d",&m,&n,&f);
  for(int i = 0; i < m; i++){
      string s;
      for(int j = 0; j < n; j++){
        char c;
        scanf(" %c",&c);
        for(int k = 0; k < f; k++){
          s += c;
        }
      }
      for(int k = 0; k < f; k++){
        printf("%s\n",s.c_str());
      }
        
  }
}
