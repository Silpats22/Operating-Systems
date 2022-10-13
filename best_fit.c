#include<stdio.h>
int main()
{
        int idx,i,n,m,j,proc[20],mem[20],alloc[20];
        printf("Enter the number of processes : ");
        scanf("%d",&n);
        printf("Enter the size of each block : ");
        for(i=0;i<n;i++)
        {
                scanf("%d",&proc[i]);
        }
        printf("Enter the number of memory  blocks :");
        scanf("%d",&m);
        printf("Enter the size of each memory block :");
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
                idx=-1;
                for(j=0;j<m;j++)
                {
                        if(mem[j]>=proc[i])
                        {
                                if(idx==-1)
                                {
                                        idx=j;
                                }
                                else if(mem[idx]>mem[j])
                                {
                                        idx=j;
                                }
                        }
                }
                if(idx!=-1)
                {
                        alloc[i]=idx;
                        mem[idx]-=proc[i];
                }
        }
        printf("PROCESS NO\tPROCESS SIZE\tBLOCK NO\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t\t%d\t\t",i+1,proc[i]);
                if(alloc[i]!=-1)
                {
                        printf("%d\n",alloc[i]+1);
                }
                else
                {
                        printf("Not allocated\n");
                }
        }
        return 0;
}
