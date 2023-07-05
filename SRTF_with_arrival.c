//SRTF with arrival

#include<stdio.h>
int at[10],bt[10],tat[10],rt[10],wt[10],min,n,R,time,p[10];

void calculate(){
    while(R){
        min = n;
        for(int i = 0;i<n;i++){
            if(at[i]<=time && rt[i] != 0){
                if(rt[min] == rt[i]){
                    if(at[min] > at[i])
                        min = i;
            }
            else{
                if(rt[min] > rt[i])
                min = i;
            }
            
            }
        }
        rt[min]--;
        if(rt[min] ==0){
            R--;
            tat[min] = time+1-at[min];
            wt[min] = tat[min] - bt[min];
        }
        time++;
    }
}

void display(){
    int i;
    printf("\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    }

}

void main(){
    int sum = 0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    R = n;
    rt[n] = 999;
    for (int i = 0;i<n;i++){
        printf("Enter the value of AT and BT for P%d\n",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        p[i] = i+1;
        rt[i] = bt[i];
    }
    calculate();
    display();
}