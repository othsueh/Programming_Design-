#include <stdio.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct EDGE{
    int weight;
    int start;
    int end;
    bool operator<(const EDGE &a)const {
        return a.weight < weight;
    }
};
typedef EDGE* Edge;
vector<Edge> edges;



int main()
{
    int dataSet;
    scanf("%d", &dataSet);
    for(int i=1; i <= dataSet; i++){
        int locations, roads, cost;
        scanf("%d %d %d", &locations, &roads, &cost);
        for(int j = 0; j < roads; j++){
            Edge e = (Edge)malloc(sizeof(EDGE));
            scanf("%d %d %d", &e->start, &e->end, &e->weight);
            edges.emplace_back(e);
        }
        sort(edges.begin(), edges.end());
        for(int j = 0; j< edges.size(); j++){
            Edge e = edges.front();
            edges.erase(edges.begin());
            printf("%d\n", e->weight);
        }
    }
}