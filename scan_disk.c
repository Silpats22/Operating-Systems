#include<stdio.h>
#include<stdlib.h>
int main()
{
        int i,j,temp,index,n,RQ[50],size,head,move,THM=0;
        printf("Enter the number of requests : ");
        scanf("%d",&n);
        printf("Enetr the request sequence : ");
        for(i=0;i<n;i++)
        {
                scanf("%d",&RQ[i]);
        }
        printf("Enter the initial head position : ");
        scanf("%d",&head);
        printf("Enter the size of the disk : ");
        scanf("%d",&size);
        printf("Enter disk arm movement direction(1 for high and 0 for low) : ");
        scanf("%d",&move);
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(RQ[j+1]<RQ[j])
                        {
                                temp=RQ[j+1];
                                RQ[j+1]=RQ[j];
                                RQ[j]=temp;
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                if(head<RQ[i])
                {
                        index=i;
                        break;
                }
        }
        if(move==1)
        {
                for(i=index;i<n;i++)
                {
                        THM+=abs(RQ[i]-head);
                        head=RQ[i];
                }
                THM+=abs(size-RQ[i-1]-1);
                head=size-1;
                for(i=index-1;i>=0;i--)
                {
                        THM+=abs(RQ[i]-head);
                        head=RQ[i];
                }
        }
        else
        {
                for(i=index-1;i>=0;i--)
                {
                        THM+=abs(RQ[i]-head);
                        head=RQ[i];
                }
                THM+=abs(RQ[i+1]-0);
                head=0;
                for(i=index;i<n;i++)
                {
                        THM+=abs(RQ[i]-head);
                        head=RQ[i];
                }
        }
        printf("Total Head Moment : %d\n",THM);
        return 0;
}
