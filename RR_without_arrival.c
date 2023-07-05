//RR without arrival

#include<stdio.h>
int time, rt[10], tq, bt[10], tat[10],wt[10],R,n,p[10];

void calculate(){;
    time = 0;
    R = n;
    while(R!=0){
        for(int i = 0; i<n; i++){            
            if(rt[i]!=0){
                if(rt[i]>tq){  
                    rt[i]-=tq;
                    time+=tq;
                }
                else{
                    time+=rt[i];
                    rt[i] = 0;
                    R--;
                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];
                }
            }
        }
    }
}

void display(){
    int i;
    printf("*************************\n");
    printf("\tBT\tWT\tTAT\n");
    for (i = 0; i<n;i++){
        printf("P%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
}

void main(){
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i = 0; i<n;i++){
        printf("Enter the BT for %d process: \n",i+1 );
        scanf("%d", bt+i);
        p[i] = i+1;
        rt[i] = bt[i];
    }
    calculate();
    display();
}