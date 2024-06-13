#include <iostream>

using namespace std;

signed main()
{
  string T[101];
  int a[101], b[101];
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    cin >> T[i] >> a[i] >> b[i];
  }
  int A = -1, B = 1001;
  for(int i = n-1; i >= 0; i--){
    if(T[i] == "none"){
      A = max(A,a[i]);
      B = min(B,b[i]);
    }else if(T[i] == "on"){
      A -= b[i];
      B -= a[i];
      A = max(A,0);
    }else{
      A += a[i];
      B += b[i];
    } 
  }
  printf("%d %d\n", A, B);
  A = -1, B = 1001;
  for(int i = 0; i < n ;i++){
    if(T[i] == "none"){
      A = max(A,a[i]);
      B = min(B,b[i]);
    }else if(T[i] == "on"){
      A += a[i];
      B += b[i];
    }else{
      A -= b[i];
      B -= a[i];
      A = max(A,0);
    } 
  }
  printf("%d %d\n", A, B);
}
