#include<stdio.h>
int main()
{
        int n,m,i,j,mem[20],proc[20],idx,alloc[20];
        printf("Enter the number of processes : ");
        scanf("%d",&n);
        printf("Enter the size of each process : ");
        for(i=0;i<n;i++)
        {
                scanf("%d",&proc[i]);
        }
        printf("Enter the number of memory blocks : ");
        scanf("%d",&m);
        printf("Enter the size of each memory block : ");
        for(i=0;i<m;i++)
        {
                scanf("%d",&mem[i]);
        }
        for(i=0;i<n;i++)
        {
                alloc[i]=-1;
        }
        for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
                        if(mem[j]>=proc[i])
                        {
                                alloc[i]=j;
                                mem[j]-=proc[i];
                        }
                }
        }
        printf("PROCESS NO\tPROCESS SIZE\tBLOCK NO\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t\t%d\t\t",i+1,proc[i]);
                if(alloc[i]==-1)
                {
                        printf("Not allocated\n");
                }
                else
                {
                        printf("%d\n",alloc[i]+1);
                }
        }
        return 0;
}
