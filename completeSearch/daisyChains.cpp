#include <iostream>

using namespace std;

int flowers[105] = {0};
int main()
{
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &flowers[i]);
  }
  int validPhotos = 0;
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      double avgPetals = 0;
      for(int k = i; k <= j; k++){
        avgPetals += flowers[k];
      }
      avgPetals /= (j-i+1);
      for(int k = i; k <= j; k++){
        if(flowers[k] == avgPetals){
          validPhotos++;
          break;
        }
      }
    }
  }
  printf("%d\n", validPhotos);

}
