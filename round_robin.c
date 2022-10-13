#include<stdio.h>
typedef struct{
        int no,at,bt,tat,wt,tbt;
} process;
process p[10];
int n,t,a,i,j,f=-1,r=-1,q[20],exist[10]={0},ct=0;
float sum_tat=0.0,sum_wt=0.0,avg_tat,avg_wt;
void insert(int p)
{
        if(f==-1)
        {
                f=0;
        }
        r=r+1;
        q[r]=p;
}
int delete()
{
        int p;
        p=q[f];
        f=f+1;
        return p;
}
int main()
{
        printf("Enter the number of processes : ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("\nEnter arrival time and burst time of process %d : ",i+1);
                scanf("%d%d",&p[i].at,&p[i].bt);
                p[i].tbt=p[i].bt;
        }
        printf("Enter the time quantum : ");
        scanf("%d",&t);
        insert(0);
        exist[0]=1;
        printf("\nGantt chart :-\n");
        while(f<=r)
        {
                a=delete();
                if(p[a].bt>=t)
                {
                        p[a].bt=p[a].bt-t;
                        ct=ct+t;
                }
                else
                {
                        ct=ct+p[a].bt;
                        p[a].bt=0;
                }
                printf("P%d(%d)  ",a+1,ct);
                for(i=0;i<n;i++)
                {
                        if(exist[i]==0 && p[a].at<=ct)
                        {
                                insert(i);
                                exist[i]=1;
                        }
                }
                if(p[a].bt==0)
                {
                        p[a].tat=ct-p[a].at;
                        p[a].wt=p[a].tat-p[a].tbt;
                        sum_tat+=p[a].tat;
                        sum_wt+=p[a].wt;
                }
                else
                {
                        insert(a);
                }
        }
        avg_tat=sum_tat/n;
        avg_wt=sum_wt/n;
        printf("\nAverage turnarround time : %.2f",avg_tat);
        printf("\nAverage waiting time : %.2f",avg_wt);
        return 0;
}
