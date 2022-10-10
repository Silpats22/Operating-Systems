#include<stdio.h>
struct process{
int no;
int at;
int bt;
int tat;
int ct;
int wt;
} p[10];
int n,i,j;
float sum_wt=0.0,sum_tat=0.0,avg_wt,avg_tat;
void sort(int n)
{
        struct process temp;
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j].at>p[j+1].at)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
}
void ct(int n)
{
        p[0].ct=p[0].at+p[0].bt;
        for(i=1;i<n;i++)
        {
                if(p[i].at>p[i-1].ct)
                {
                        p[i].ct=p[i].at+p[i].bt;
                }
                else
                {
                        p[i].ct=p[i-1].ct+p[i].bt;
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
        avg_tat=sum_tat/n;
}
void wt(int n)
{
        for(i=0;i<n;i++)
        {
                p[i].wt=p[i].tat-p[i].bt;
                sum_wt+=p[i].wt;
        }
        avg_wt=sum_wt/n;
}
int main()
{
        printf("Enter the number of processes : ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter the arrival time and burst time of process %d : ",i+1);
                scanf("%d%d",&p[i].at,&p[i].bt);
                p[i].no=i+1;
        }
        sort(n);
        ct(n);
        tat(n);
        wt(n);
        printf("process || arrival time || burst time || completion time || turnarround time || waiting time ||\n");
        for(i=0;i<n;i++)
        {
        printf("  %d    ||     %d       ||      %d    ||       %d        ||      %d          ||    %d        ||\n",p[i].no,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
                }
        printf("Gantt chart :-\n");
        for(i=0;i<n;i++)
        {
                printf("P%d(%d,%d)",p[i].no,p[i].bt,p[i].ct);
                if(i<n-1)
                {
                        printf("--->");
                }
        }
        printf("\nAvearge waiting time : %.2f\n",avg_wt);
        printf("Average turnarround time : %.2f\n",avg_tat);
        return 0;
}
