#include <stdio.h>

int a[12]={44,43,11,55,77,90,40,60,99,22,88,66};
int n = 12;
int quick(int,int);

int main()
{
    int i,top,beg,end,loc,lower[12],upper[12];

    printf("initial array : \n\n");
    for(i = 0;i<12;i++)
        printf("%d\t",a[i]);

    top = -1;
    if(n>1)
    {
        top = top + 1;
        lower[0] = 0;
        upper[0] = n -1;
    }
    while(top != -1)
    {
        beg = lower[top];
        end = upper[top];
        top = top - 1;
        loc = quick(beg,end);
        if(beg<loc-1)
        {
            top = top + 1;
            lower[top] = beg;
            upper[top] = loc - 1;
        }
        if(end>loc+1)
        {
            top = top + 1;
            lower[top] = loc + 1;
            upper[top] = end;
        }
    }
    printf("\nsorted array: \n\n");
    for(i=0;i<12;i++)
        printf("%d\t",a[i]);
        return 0;
}
int quick(int b,int e)
{
    int left,right,temp,loc1;
    left = b;
    right = e;
    loc1 = b;

while(1)
{
    while(a[loc1]<=a[right] && loc1 != right)
        right = right - 1;
    if(loc1 == right)
        return(loc1);
    if(a[loc1]>a[right])
    {
        temp = a[loc1];
        a[loc1] = a[right];
        a[right] = temp;
        loc1 = right;
    }
    while((a[left]<=a[loc1] && left != loc1))
        left = left + 1;
    if(loc1 == left)
        return (left);
    if(a[left]>a[loc1])
    {
        temp = a[loc1];
        a[loc1] = a[left];
        a[left] = temp;
        loc1=left;
    }
}
}






