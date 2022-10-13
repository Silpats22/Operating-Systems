#include<stdio.h>
typedef struct{
        int no,at,bt,tbt,pt,tat,wt;
} process;
process p[10];
int n,i,j,t,count=0,sp;
float sum_tat=0.0,sum_wt=0.0,avg_tat,avg_wt;
int main()
{
        printf("Enter the number of processes : ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter the arrival time burst time and priority of process %d : ",i+1);
                scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pt);
                p[i].tbt=p[i].bt;
                p[i].no=i;
        }
        p[9].pt=1000000;
        for(t=0;count!=n;t++)
        {
                sp=9;
                for(i=0;i<n;i++)
                {
                        if(p[sp].pt>p[i].pt && p[i].at<=t && p[i].bt>0)
                        {
                                sp=i;
                        }
                }
                p[sp].bt=p[sp].bt-1;
                if(p[sp].bt==0)
                {
                        count++;
                        p[sp].tat=t+1-p[sp].at;
                        p[sp].wt=p[sp].tat-p[sp].tbt;
                        sum_tat+=p[sp].tat;
                        sum_wt+=p[sp].wt;
                }
        }
        avg_tat=sum_tat/n;
        avg_wt=sum_wt/n;
        printf("PROCESS NO\tARRIVAL TIME\tBURST TIME\tPRIORITY\tTURNAROUND TIME\tWAITING TIME\n");
        for(i=0;i<n;i++)
        {
                printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i].no,p[i].at,p[i].tbt,p[i].pt,p[i].tat,p[i].wt);
        }
        printf("\nAverage turnarround time : %.2f",avg_tat);
        printf("\nAverage waiting time : %.2f\n",avg_wt);
        return 0;
}
