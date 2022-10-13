#include<stdio.h>
struct process
{
        int no,at,bt,ct,tat,wt;
};
int n,i,j,ready,flag;
float sum_tat=0.0,sum_wt=0.0,avg_tat,avg_wt;
struct process p[10];
void sort(int n)
{
        struct process temp;
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
void sjf(int n)
{
        struct process temp;
        p[0].ct=p[0].at+p[0].bt;
        ready=p[0].ct;
        for(i=1;i<n;i++)
        {
                if(p[i].at<=ready)
                {
                        for(j=i+1;j<n;j++)
                        {
                                if(p[i].at<=ready&&p[j].bt<p[i].bt)
                                {
                                        temp=p[i];
                                        p[i]=p[j];
                                        p[j]=temp;
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
void tat(int n)
{
        for(i=0;i<n;i++)
        {
                p[i].tat=p[i].ct-p[i].at;
                sum_tat+=p[i].tat;
        }
}
void wt(int n)
{
        for(i=0;i<n;i++)
        {
                p[i].wt=p[i].tat-p[i].bt;
                sum_wt+=p[i].wt;
        }
}
int main()
{
        printf("Enter the number of processses : ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("\nEnter the arrival time and burst time of process %d : ",i+1);
                scanf("%d%d",&p[i].at,&p[i].bt);
                p[i].no=i+1;
        }
        sort(n);
        sjf(n);
        tat(n);
        wt(n);
        avg_tat=sum_tat/n;
        avg_wt=sum_wt/n;
        printf("PROCESS NO\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tTURNARROUND TIME\tWAITING TIME\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i].no,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        }
        printf("Gantt chart :-\n");
        for(i=0;i<n;i++)
        {
                printf("P%d(%d)",p[i].no,p[i].ct);
                if(i<n-1)
                {
                        printf("-->");
                }
        }
        printf("\nAverage turnarround time : %.2f",avg_tat);
        printf("\nAverage waiting time : %.2f",avg_wt);
        return 0;
}
