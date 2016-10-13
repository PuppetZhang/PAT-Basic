#include<stdio.h>  
#include<string.h>  
int main()  
{  
    int n[5],sum1=0,sum2=0,sum3=0,max=0,num,i,l;  
    double ave;  
    for(i=0;i<5;i++) n[i]=0;  
    scanf("%d",&l);  
    for(i=0;i<l;i++){  
        scanf("%d",&num);  
        if(num%10==0){  
            n[0]++;sum1+=num;  
        }  
        if(num%5==1&&n[1]%2==0){  
            n[1]++;sum2+=num;  
        }else if(num%5==1&&n[1]%2==1){  
            n[1]++;sum2-=num;  
        }  
        if(num%5==2) n[2]++;  
        if(num%5==3){  
            sum3+=num;n[3]++;  
        }  
        if(num%5==4){  
            n[4]++;  
            if(num>max) max=num;  
        }  
    }  
    ave=sum3*1.0/n[3];  
    if(n[0]==0) printf("N ");else printf("%d ",sum1);  
    if(n[1]==0) printf("N ");else printf("%d ",sum2);  
    if(n[2]==0) printf("N ");else printf("%d ",n[2]);  
    if(n[3]==0) printf("N ");else printf("%.1lf ",ave);  
    if(n[4]==0) printf("N");else printf("%d",max);  
    return 0;  
}  