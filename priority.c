
#include<stdio.h>
void findTurnAroundTime(int tat[],int n,int bt[]){
    int k = 0;
    for(int i=0;i<n;i++){
        k = k + bt[i];
        tat[i] = k;
        }
}
void findWaitingTime(int wt[],int tat[],int bt[],int n){
    for(int i=0;i<n;i++){
        wt[i] = tat[i] - bt[i];
        }
}
void priorityScheduling(int processes[],int bt[], int priority[],int n){
    int tat[n],wt[n];
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
     findTurnAroundTime(tat,n,bt);
     findWaitingTime(wt,tat,bt,n);
     printf("Processes\tBT\tPriority\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t\t%d\t%d\t\t\t%d\t%d\n",processes[i],bt[i],priority[i],tat[i],wt[i]);
     }
}
int main(){
    int processes[] = {1,2,3,4,5};
    int bt[] = {10,5,12,4,9};
    int priority[] = {2,1,3,4,0};
    int n = sizeof(processes)/sizeof(processes[0]);
    priorityScheduling(processes,bt, priority,n);
    return 0;
    }

output:
Processes	BT	Priority	TAT	WT
5			9	0			9	0
2			5	1			14	9
1			10	2			24	14
3			12	3			36	24
4			4	4			40	36
