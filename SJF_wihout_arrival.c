//SJF without arrival
//Assignment- create a function for calculation of AWT and ATAT

#include<stdio.h>
int bt[10],p[10],wt[10],tat[10],n;
float awt, atat;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(){
    int i,j;
    for(i = 0; i<n-1; i++){
        for(j =i+1; j<n; j++){
            if(bt[i] > bt[j]){
                swap(&bt[i],&bt[j]);
                swap(&p[i],&p[j]);
            }
        }
    }
}

void calculate_all(){
    int i;
    wt[0] = 0; //wait time for first process will always be 0
    tat[0] = bt[0]; // tat time for first process will always be equal to first BT
    for(i = 1; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }
}

void display(){
    int i;
    printf("Process\tBT\tWT\tTAT\n");
    for(i =0; i<n; i++){
        printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
}

void main(){
    int i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i =0; i<n; i++){
        printf("Enter BT for P%d: ",i+1);
        scanf("%d",bt+i);
        p[i] = i+1;
    }
    sort(); //sort Brust time and Process ID
    calculate_all();
    display();
}