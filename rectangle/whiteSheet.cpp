#include <iostream>
using namespace std;

struct Rectangle
{
    int x1, y1,x2,y2;
    int area()
    {
      return (x2-x1)*(y2-y1);
    }
};

signed main()
{
  Rectangle all[3];
  for(int i=0;i<3;i++)
  {
    scanf("%d %d %d %d",&all[i].x1,&all[i].y1,&all[i].x2,&all[i].y2);
  }
  if((all[2].x1 <= all[0].x1 && all[2].y1 <= all[0].y1 && all[2].x2 >= all[0].x2 && all[2].y2 >= all[0].y2)
      ||(all[1].x1 <= all[0].x1 && all[1].y1 <= all[0].y1 && all[1].x2 >= all[0].x2 && all[1].y2 >= all[0].y2)){
    printf("NO\n");
  }else if(all[2].x2 >= all[0].x2 && all[1].x1 <= all[0].x1 && all[1].x1 < all[2].x1 && all[1].x2 >= all[2].x1 && all[1].y1 <= all[0].y1 && all[1].y2 >= all[0].y2 && all[2].y1 <= all[0].y1 && all[2].y2 >= all[0].y2){
    printf("NO\n");
  }else if(all[1].x2 >= all[0].x2 && all[2].x1 <= all[0].x1 && all[2].x1 < all[1].x1 && all[2].x2 >= all[1].x1 && all[1].y1 <= all[0].y1 && all[1].y2 >= all[0].y2 && all[2].y1 <= all[0].y1 && all[2].y2 >= all[0].y2){
    printf("NO\n");
  }else if(all[2].y2 >= all[0].y2 && all[1].y1 <= all[0].y1 && all[1].y1 < all[2].y1 && all[1].y2 >= all[2].y1 && all[1].x1 <= all[0].x1 && all[1].x2 >= all[0].x2 && all[2].x1 <= all[0].x1 && all[2].x2 >= all[0].x2){
    printf("NO\n");
  }else if(all[1].y2 >= all[0].y2 && all[2].y1 <= all[0].y1 && all[2].y1 < all[1].y1 && all[2].y2 >= all[1].y1 && all[1].x1 <= all[0].x1 && all[1].x2 >= all[0].x2 && all[2].x1 <= all[0].x1 && all[2].x2 >= all[0].x2){
    printf("NO\n");
  }else{
    printf("YES\n");
  }
}
