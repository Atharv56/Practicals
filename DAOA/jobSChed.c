#include<stdio.h>

int max;

struct job
{
    int num, deadline, profit;
} j[100], temp;

void swap(struct job *x, struct job *y)
{
    struct job temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void job_schedule(struct job j[], int n)
{
    int i, k, total_profit=0, s[100]={0};
    
    for(i=0; i<n; i++)
    {
        k = j[i].deadline-1;
        
        while(k>=0 && s[k]!=0)
            k--;
            
        if(k>=0)
        {
            s[k]=j[i].num;
            total_profit += j[i].profit;
        }
    }
    
    printf("\n\nThe scheduled jobs are:");
    for(i=0; i<max; i++)
    {
        if(s[i]!=0)
        {
            printf("\t%d",s[i]);
        }
    }
    printf("\n\nThe maximum profit achieved is %d",total_profit);
}


void main()
{
    int i, k, n;
    
    printf("ENTER NUMBER OF JOBS: ");
    scanf("%d", &n);
    
    for(i=0;i<=n-1;i++)
    {
        j[i].num = i+1;
        printf("ENTER DEADLINE: ");
        scanf("%d",&j[i].deadline);
        printf("ENTER PROFIT: ");
        scanf("%d",&j[i].profit);
    }
    
    for(i=0; i<n; i++)
    {
        for(k=0; k<n-i-1; k++)
        {
            if(j[k].profit < j[k+1].profit)
                swap(&j[k], &j[k+1]);
        }
    }
    
    max = j[0].deadline;
    for(i=0; i<n; i++)
    {
        if(max < j[i].deadline)
        {
            max=j[i].deadline;
        }
    }
    job_schedule(j, n);
}
