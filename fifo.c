#include<stdio.h>

int getFault(int pages[],int frames[],int n ,int k){
    int count = 0,r = 0;
    for(int i=0;i<k;i++){
        frames[i] = -1;
    }
    for(int i=0;i<n;i++){
        int avail = 0;
        for(int j=0;j<k;j++){
            if(frames[j] == pages[i]){
                avail = 1;
            }
        }
        if(avail == 0){
            frames[r] = pages[i];
            r = (r+1)%k;
            count++;
        }
    }
    return count;
}

int main(){
    int n,pages[50],frames[50],k;
    printf("Enter the number of pages:");
    scanf("%d",&n);
    printf("Enter the page numbers:");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    printf("Enter the number of frames:");
    scanf("%d",&k);
    int fault = getFault(pages,frames,n,k);
    printf("Page faults are: %d",fault);
    return 0;
}

output:
Enter the number of pages:10
Enter the page numbers:
1 2 3 4 5 1 2 3 4 5
Enter the number of frames:4
Page faults are: 10
