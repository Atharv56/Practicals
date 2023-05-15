#include <stdio.h>
#include <conio.h>
int p[100];
int karr[100][100];
int MandM(int n, int i, int j)
{
    int k;
    int min = 10000000;
    int mink;
    int count;
    if (i == j)
    {
        mink = 0;
        return 0;
    }
    for (k = i; k < j; k++)
    {
        count = MandM(n, i, k) + MandM(n, k + 1, j) + p[i - 1] * p[k]* p[j];
        if (count < min)
        {
            min = count;
            mink = k;
        }
    }
    karr[i][j] = mink;
    return min;
}
int main()
{
    int i, j, m, n, q[100][100], k[100];
    printf("Yash Thakar : 60009210205\n");
    printf("Enter the number of sequences\n");
    scanf("%d", &n);
    printf("Enter the sequence\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            q[i][j] = MandM(n, i, j);
        }
    }
    printf("\n");
    for (i = 1; i < n; i++)
    {
        for (m = 0; m < i; m++)
        {
            printf(" ");
        }
        for (j = i; j < n; j++)
        {
            printf("%d ", q[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 1; i < n; i++)
    {
        for (m = 0; m < i; m++)
        {
            printf(" ");
        }
        for (j = i; j < n; j++)
        {
            printf("%d ", karr[i][j]);
        }
        printf("\n");
    }
    return 0;
}


