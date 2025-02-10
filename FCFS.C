#include <stdio.h>

void turnAroundTime(int n, int tat[], int bt[]) {
    int ct = 0;
    for (int i = 0; i < n; i++) {
        ct += bt[i];
        tat[i] = ct;
    }
}

void waitingTime(int n, int tat[], int bt[], int wt[]) {
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }
}

void avgWaitingTime(int size, int bt[]) {
    int tat[size], wt[size];
    
    turnAroundTime(size, tat, bt);
    waitingTime(size, tat, bt, wt);
    
    int sum = 0;
    printf("Processes\tBurst Time\tTAT\tWaiting Time\n");
    
    for (int i = 0; i < size; i++) {
        sum += wt[i];
        printf("%d\t\t%d\t\t%d\t%d\n", (i + 1), bt[i], tat[i], wt[i]);
    }
    
    float avg = (float)sum / size;  // Use float for more accurate average
    printf("Average Waiting Time: %.2f\n", avg);
}

int main() {
    int processes[] = {1, 2, 3};
    int size = sizeof(processes) / sizeof(processes[0]);
    int bt[] = {10, 5, 8};
    
    avgWaitingTime(size, bt);
    return 0;
}
Processes	Burst Time	TAT	Waiting Time
1		10		10	0
2		5		15	10
3		8		23	15
Average Waiting Time: 8.33
