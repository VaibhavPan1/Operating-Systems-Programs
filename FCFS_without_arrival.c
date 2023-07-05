//FCFS Without Arrival Time 

#include<stdio.h>
int p[10],bt[10],wt[10],tat[10],n;
float awt,atat;

void calculate_all(){
    int i;
    wt[0] = 0; // wait time for first process will be 0
    tat[0] = bt[0] //Turn around time for first process will be equal to its Brust Time
    //calculation starts from second process
    for(i = 1; i<n; i++){ 
        wt[i] = bt[i-1] + wt[i-1];
        tat[i] = bt[i] + wt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
    }
    awt = awt/(float)n;
    atat = atat/(float)n;
}

void display(){
    int i;
    printf("Process\tBT\tWT\tTAT\n");
    for(i = 0; i<n; i++){
        printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
}

void main(){
    int i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i = 0; i<n;i++){
        printf("Enter BT for P%d: ",i+1);
        scanf("%d",bt+i);
        p[i] = i+1;
    }
    calculate_all();
    display();
}