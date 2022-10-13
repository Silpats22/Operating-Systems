#include<stdio.h>
int main()
{
        int i,ind=0,j,k,y,flag,safe[20],n,m,Alloc[20][20],Max[20][20],Available[10],Need[20][20],finish[10];
        printf("Enter the number of processes : ");
        scanf("%d",&n);
        printf("Enter the number of resource type : ");
        scanf("%d",&m);
        printf("Enter the allocation matrix :\n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
                        scanf("%d",&Alloc[i][j]);
                }
        }
        printf("Enter the Maximum matrix :\n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
                        scanf("%d",&Max[i][j]);
                }
        }
        printf("Enter available resource types : ");
        for(i=0;i<m;i++)
        {
                scanf("%d",&Available[i]);
        }
        for(i=0;i<n;i++)
        {
                printf("\n");
                for(j=0;j<m;j++)
                {
                        Need[i][j]=Max[i][j]-Alloc[i][j];
                        printf("%d",Need[i][j]);
                }
        }
        for(i=0;i<n;i++)
        {
                finish[i]=0;
        }
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        if(finish[j]==0)
                        {
                                flag=0;
                                for(k=0;k<m;k++)
                                {
                                        if(Need[j][k]>Available[k])
                                        {
                                                flag=1;
                                                break;
                                        }
                                }
                                if(flag==0)
                                {
                                        safe[ind++]=j;
                                        for(y=0;y<m;y++)
                                        Available[y]+=Alloc[j][y];
                                        finish[j]=1;
                                }
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                printf("%d  ",finish[i]);
        }
        flag=1;
        for(i=0;i<n;i++)
        {
                if(finish[i]==0)
                {
                        printf("System is not in safe state\n");
                        flag=0;
                        break;
                }
        }
        if(flag==1)
        {
                printf("Safe sequence is :-\n");
                for(i=0;i<n;i++)
                {
                        printf("P%d",safe[i]);
                        if(i<n-1)
                        {
                                printf("-->");
                        }
                }
        }
        printf("\n");
        return 0;
}
