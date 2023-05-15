#include <stdio.h>

struct edge{
    int node1, node2, cost;
}d[100];

int flag[100];

void main()
{
    int i, j, k, n, e, a[50][50], cost, min, index=0, l, h, totalcost=0, check[50], counter=1;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            a[i][j]=30000;
        }
    }
    
    for(k=0; k<e; k++)
    {
        printf("Enter the 1st node no : ");
        scanf("%d", &i);
        
        printf("Enter the 2nd node no: ");
        scanf("%d", &j);
        
        printf("Enter cost: ");
        scanf("%d", &cost);
    
        a[i-1][j-1] = cost;
    }
    
    for(i=0; i<n*n; i++)
    {
        min=29999;
        for(j=0; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                if(min > a[j][k])
                {
                    min=a[j][k];
                    l = j;
                    h = k;
                }
            }
        }
        
        if(flag[l]==0 && flag[h]==0) 
        {
            d[index].node1= l;
            d[index].node2 = h;
            d[index].cost= a[l][h];
            flag[l]= counter;
            flag[h]= counter;
            counter++;
            index++;
        }
        
        else if(flag[l]==flag[h])
        {
          break;   
        }
        
        else
        {
            if(flag[l]==0)
                flag[l]= flag[h];
            else if(flag[h]==0)
                flag[h]= flag[l];
            else
            {
                for(i=0; i<n; i++)
                {
                    if(flag[i]==flag[l])
                        flag[i]=flag[h];
                }
            }
                
            d[index].node1= l;
            d[index].node2 = h;
            d[index].cost= a[l][h];
            index++;
        }
        a[l][h] = 30000;
    }
    
    printf("Node 1\tNode 2\tCost\n");
    
    for(i=0; i<index; i++)
     printf("%d\t\t%d\t\t%d\n", d[i].node1+1, d[i].node2+1, d[i].cost);
    
    for(i=0; i<index; i++)
        totalcost = totalcost + d[i].cost;
        
    printf("Total Cost: %d", totalcost);
}
