//FCFS with arrival

#include<stdio.h>
int p[10],at[10],bt[10],wt[10],tat[10],n,time;
float awt, atat;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(){
    int i,j;
    for(i = 0; i<n-1; i++){
        for(j = i+1; j<n;j++){
            if(at[i] > at[j]){
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&p[i],&p[j]);
            }
        }
    }
}

void calculate_all(){
    int i;
    for(i = 0; i<n; i++){
        if(at[i] <= time){
            time = time + bt[i];
            tat[i] = time - at[i];
            wt[i] = tat[i] - bt[i];
        }
        else {time++;i--;}
    }
}

void display(){
    int i;
    printf("Process\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    }
}

void main(){
    int i;
    printf("Enter the number of Processes: ");
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        printf("Enter the AT and BT for P%d: ",i+1);
        scanf("%d%d",at+i,bt+i);
        p[i] = i+1;
    }
    sort();
    calculate_all();
    display();
}