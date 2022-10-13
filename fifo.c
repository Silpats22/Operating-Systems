#include<stdio.h>
void main()
{
        int i,j,pf=0,count=0,f,k,rs[30],m[10],n;
        printf("Enter the number of page requests : ");
        scanf("%d",&n);
        printf("Enter the reference string : ");
        for(i=0;i<n;i++)
        {
                scanf("%d",&rs[i]);
        }
        printf("Enter the number of frames : ");
        scanf("%d",&f);
        for(i=0;i<f;i++)
        {
                m[i]=-1;
        }
        printf("\nThe page replacement process is--\n");
        for(i=0;i<n;i++)
        {
                for(k=0;k<f;k++)
                {
                        if(m[k]==rs[i])
                        {
                                break;
                        }
                }
                if(k==f)
                {
                        m[count++]=rs[i];
                        pf++;
                }
                for(j=0;j<f;j++)
                {
                        printf("\t%d",m[j]);
                }
                if(f==k)
                printf("\tPF No.%d",pf);
                printf("\n");
                if(count==f)
                count=0;
        }
        printf("\nThe number of page faults using FIFo are %d",pf);
}
