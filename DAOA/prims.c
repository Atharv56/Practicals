Implementation of minimum spanning tree using greedy algorithm (Prims’s algorithm). 
#include<stdio.h>
#include<stdbool.h> 
#define V 5

int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};

void main() 
{
  int no_edge = 0, selected[V], x=0, y=0, sum=0;
  selected[0] = true;

  printf("Edge : Weight\n");

  while (no_edge < V-1) 
  {
    int min = 9999;
    for (int i = 0; i<V; i++) 
    {
      if (selected[i]) 
      {
        for (int j = 0; j < V; j++) 
        {
          if (!selected[j] && G[i][j]) 
          {  // not in selected and there is an edge
            if (min > G[i][j]) 
            {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    sum += G[x][y];
    selected[y] = true;
    no_edge++;
  }
    printf("Total Cost: %d", sum);
}
