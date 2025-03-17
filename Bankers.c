#include<stdio.h>
#include<stdbool.h>
void main(){
    int n,m;
    printf("Number of processes: ");
    scanf("%d",&n);
    printf("Number of resources type: ");
    scanf("%d",&m);
    int process[n],Allocation[n][m],Max[n][m],Available[m];
    
    
    printf("Enter the Allocation %d*%d matrix:\n",n,m); //Allocation
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&Allocation[i][j]);
        }
    }
    
    printf("Enter the Max %d*%d matrix:\n",n,m); //Max
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&Max[i][j]);
        }
    }
    
    
    printf("Enter the Available resources for first process:\n"); //Initialize Available
        for(int j=0;j<m;j++){
            scanf("%d",&Available[j]);
        }
    
    
    int work[m];
        for(int j=0;j<m;j++){
            work[j] = Available[j]; //Assign Availbale to work
        }
  
    
    
    bool Finish[n];
    for(int i=0;i<n;i++){
        Finish[i] = false;  //Initialize Finish to false
    }
    
    
    int Need[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Need[i][j] = Max[i][j] - Allocation[i][j]; //Need
        }
    }
    printf("Need matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",Need[i][j]); //Need
        }
        printf("\n");
    }
    int k = n;
    int res = 0;
    while(k > 0){
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<m;j++){
            if(Need[i][j] <= work[j]){
                count++;
                if(count == m && Finish[i] == false){
                    Finish[i] = true;
                    k -= 1;
                    res += 1;
                    printf("p%d ",i);
                    for(int j=0;j<m;j++){
		     work[j] += Allocation[i][j];
    		  }
                }
            }
            else{
                break;
            }
        }
    }
    }
    if(res == n){
      printf("\nSafe sequence is occured");
      }
      else{
    	printf("\nDeadlock occured");
      }
}


output:


Number of processes: 5
Number of resources type: 3
Enter the Allocation 5*3 matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the Max 5*3 matrix:
7 5 3 
3 2 2
9 0 2
2 2 2
4 3 3
Enter the Available resources for first process:
3 3 2
Need matrix:
7 4 3 
1 2 2 
6 0 0 
0 1 1 
4 3 1 
p1 p3 p4 p0 p2 
Safe sequence is occured


