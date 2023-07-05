//SJF with arrival

#include<stdio.h>
int at[10],bt[10],p[10],n,wt[10],tat[10],time,rt[10],R;


void calculate(){
     int min;
    time = 0;
    R = n;
    while(R!=0){
        min = n;
        for(int i = 0; i<n; i++){
            if (at[i]<=time && rt[i] !=0){
                if(bt[min]>bt[i])
                min = i;
            } 
        }
        if(min == n){
            time++;
        }
        else{
            time = time + bt[min];
            tat[min] = time - at[min];
            wt[min] = tat[min] - bt[min];
            R--;
            rt[min] = 0;
        }
    }

}

void display(){
    int i;
    printf("**************************\n");
    printf("\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i<n; i++){
        
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    }
    printf("**************************\n");

}

void main(){
    int i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    bt[n] = 999;
    for (i=0; i<n; i++){
        printf("Enter the %d AT and BT: ", i+1);
        scanf("%d%d",(at+i),(bt+i));
        p[i] = i+1;
        rt[i] = bt[i];
    }
    calculate();
    display();
}