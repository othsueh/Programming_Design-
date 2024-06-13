#include <iostream>
#include <string>

using namespace std;

signed main()
{
  string original;
  string key;
  cin >> original >> key;
  int k = key.size();
  int n = original.size();
  string censor;
  for(int i = 0; i < n; i++){
    censor += original[i];
    if(censor.size() >= k && censor.substr(censor.size()-k) == key){
      censor.resize(censor.size()-k);
    }
  }
  printf("%s\n", censor.c_str());
}
