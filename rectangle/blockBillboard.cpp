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

int intersect(Rectangle a, Rectangle b)
{
  int xOverlap = max(0,min(a.x2,b.x2) - max(a.x1,b.x1));
  int yOverlap = max(0,min(a.y2,b.y2) - max(a.y1,b.y1));
  return xOverlap*yOverlap;
}
int main()
{
  Rectangle all[3];
  for(int i=0;i<3;i++)
  {
    scanf("%d %d %d %d",&all[i].x1,&all[i].y1,&all[i].x2,&all[i].y2);
  }
  printf("%d\n",all[0].area()+all[1].area() - intersect(all[0],all[2]) - intersect(all[1],all[2]));
}
