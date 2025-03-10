#include<stdio.h>
#include<stdbool.h>
void main(){
    int n,m;
    printf("Number of processes: ");
    scanf("%d",&n);
    printf("Number of resources type: ");
    scanf("%d",&m);
    int process[n],Allocation[n][m],Max[n][m],Available[n][m];
    
    
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
    for(int i=0;i<1;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&Available[i][j]);
        }
    }
    
    
    int work[n][m];
    for(int i=0;i<1;i++){
        for(int j=0;j<m;j++){
            work[i][j] = Available[i][j]; //Assign Availbale to work
        }
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
    
    for(int i=0;i<1;i++){
        int count = 0;
        for(int j=0;j<m;j++){
            if(Need[i][j] <= work[i][j]){
                count++;
                if(count == 3 && Finish[i] == false){
                    Finish[i] = true;
                    for(int j=0;j<m;i++){
								work[i][j] = work[i][j] + Allocation[i][j];
    						}
                }
            }
            else{
                break;
            }
        }
    }
    
}







