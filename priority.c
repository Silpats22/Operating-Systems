#include<stdio.h>
typedef struct{
        int no,at,bt,pt,ct,tat,wt;
} process;
process p[10];
int i,j,n,ready,flag=0;
float sum_tat=0.0,sum_wt=0.0,avg_tat,avg_wt;
void sort(int  n)
{
        process temp;
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j+1].at<p[j].at)
                        {
                                temp=p[j+1];
                                p[j+1]=p[j];
                                p[j]=temp;
                        }
                }
        }
}
void priority(int n)
{
        process temp;
        p[0].ct=p[0].at+p[0].bt;
        ready=p[0].ct;
        for(i=1;i<n;i++)
        {
                if(p[i].at<=ready)
                {
                        for(j=i+1;j<n;j++)
                        {
                                if(p[j].at<=ready && p[j].pt<p[i].pt)
                                {
                                        temp=p[j];
                                        p[j]=p[i];
                                        p[i]=temp;
                                }
                        }
                flag=1;
                }
                if(flag==1)
                {
                        p[i].ct=p[i-1].ct+p[i].bt;
                        ready=p[i].ct;
                        flag=0;
                }
                else
                {
                        p[i].ct=p[i].at+p[i].bt;
                        ready=p[i].ct;
                }
        }
}
int main()
{
        printf("Enter the number of processes : ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("\nEnter the arrival time burst time and priority of process %d : ",i+1);
                scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pt);
                p[i].no=i+1;
        }
        sort(n);
        priority(n);
        for(i=0;i<n;i++)
        {
                p[i].tat=p[i].ct-p[i].at;
                sum_tat+=p[i].tat;
        }
        for(i=0;i<n;i++)
        {
                p[i].wt=p[i].tat-p[i].bt;
                sum_wt+=p[i].wt;
        }
        printf("PROCESS NO\tARRIVAL TIME\tBURST TIME\tPRIORITY\tCOMPLETION TIME\tTURNAROUND TIME\tWAITING TIME\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i].no,p[i].at,p[i].bt,p[i].pt,p[i].ct,p[i].tat,p[i].wt);
        }
        for(i=0;i<n;i++)
        {
                printf("P%d(%d)",p[i].no,p[i].ct);
                if(i<n-1)
                {
                        printf("-->");
                }
        }
        avg_tat=sum_tat/n;
        avg_wt=sum_wt/n;
        printf("\nAverage turnarround time : %.2f",avg_tat);
        printf("\nAverage waiting time : %.2f",avg_wt);
        return 0;
}
