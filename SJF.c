#include<stdio.h>

int main(){
    int n,p[5]={1,2,3,4,5},bt[20],wt[20],tat[20];
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the burst time for process %d--",i+1);
        scanf("%d",&bt[i]);
     }
     for(int i=0;i<n-1;i++){
          for(int j=0;j<n-i-1;j++){
              if(bt[j] > bt[j+1]){
                   int temp = bt[j];
                   bt[j] = bt[j+1];
                   bt[j+1] = temp;
                   int temp1= p[j];
                   p[j] = p[j+1];
                   p[j+1] = temp1;
               }
           }
      }
      
      printf("\nPROCESS\t\tBT\t\tTAT\t\tWT");
      int ct = 0;
      float avgwt = 0;
      for(int i=0;i<n;i++){
         ct = ct + bt[i];
          tat[i ] = ct;
          wt[i] = tat[i] - bt[i];
          avgwt = avgwt + wt[i];
          printf("\n%d\t\t\t%d\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
       }
       printf("\nAverage Waiting Time: %.2f ",avgwt/n);
       return 0;
 }

Enter the number of processes:5
Enter the burst time for process 1--2
Enter the burst time for process 2--0
Enter the burst time for process 3--5
Enter the burst time for process 4--1
Enter the burst time for process 5--8

PROCESS		BT		TAT		WT
2			0		0		0
4			1		1		0
1			2		3		1
3			5		8		3
5			8		16		8
Average Waiting Time: 2.40 
