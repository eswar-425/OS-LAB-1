#include<stdio.h>
void findTurnAroundTime(int tat[],int n,int bt[]){
    int k = 0;
    for(int i=0;i<n;i++){
        k = k + bt[i];
        tat[i] = k;
        }
    for(int i =0 ;i<n;i++){
       printf("%d ",tat[i]);
       }
       printf("\n");
    }

void findWaitingTime(int wt[],int tat[],int bt[],int n){
    for(int i=0;i<n;i++){
        wt[i] = tat[i] - bt[i];
        }
    for(int i =0 ;i<n;i++){
       printf("%d ",wt[i]);
       }
       printf("\n");
    }


void priorityScheduling(int processes[],int bt[], int priority[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(priority[j] > priority[j+1]){
                int temp1 = priority[j];
                priority[j] = priority[j+1];
                priority[j+1] = temp1;
                
                int temp2 = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp2;
                
                int temp3 = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp3;
                }
            }
         }
     for(int i=0;i<n;i++){
         printf("%d ",processes[i]);
         }
         printf("\n");
     for(int i=0;i<n;i++){
         printf("%d ",priority[i]);
         }
         printf("\n");
     for(int i=0;i<n;i++){
         printf("%d ",bt[i]);
         }
         printf("\n");
     int tat[n],wt[n];
     findTurnAroundTime(tat,n,bt);
     findWaitingTime(wt,tat,bt,n);
     }

int main(){
    int processes[] = {1,2,3,4,5};
    int bt[] = {10,5,12,4,9};
    int priority[] = {2,1,3,4,0};
    int n = sizeof(processes)/sizeof(processes[0]);
    int tat[n],wt[n];
    priorityScheduling(processes,bt, priority,n);
    findTurnAroundTime(tat,n,bt);
    findWaitingTime(wt,tat,bt,n);
    printf("Processes\t\t\tBurstTime\t\t\tPriority\t\t\tTurnAroundTime\t\t\tWaitingTime\n");
    for(int i=0;i<n;i++){
        printf("%d    %d     %d     %d     %d\n",processes[i],bt[i],priority[i],tat[n],wt[n]);
    }
    return 0;
    }
