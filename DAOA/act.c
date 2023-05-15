#include <stdio.h>

struct act{
    int act_no;
    int start,finish;
}d[100];
void swap(struct act *x, struct act *y)
{
    struct act temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main(){

int sol[100],i,temp,n,j;
printf("enter number of activities\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    printf("enter act_no\n");
    scanf("%d",&d[i].act_no);
}
for(i=0;i<n;i++)
{
    printf("enter start time\n");
    scanf("%d",&d[i].start);
    printf("enter start finish\n");
    scanf("%d",&d[i].finish);
}
 for (int i=1; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(d[j].finish > d[j+1].finish)
            {
                swap(&d[j],&d[j+1]);
                  }

        }
    }
    for(i=0;i<n;i++)
{
    printf("%d\t",d[i].act_no);
}
    sol[0]=d[0].act_no;
printf("\n solution:\n");
printf("%d\t",sol[0]);
i=0;
for (int j = 1; j < n; j++)
{
if (d[j].start >= d[i].finish)
{
printf("%d ",d[j].act_no);
i = j;
}
}
return 0;
}
