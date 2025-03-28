#include<stdio.h>

int getFault(int pages[], int frames[], int n, int k) {
    int count = 0;
    int time[k]; // To track the last accessed time of each frame
    for (int i = 0; i < k; i++) {
        frames[i] = -1; // Initialize frames
        time[i] = -1; // Initialize time
    }

    for (int i = 0; i < n; i++) {
        int avail = 0, least = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < k; j++) {
            if (frames[j] == pages[i]) {
                avail = 1;
                time[j] = i; // Update last accessed time
                break;
            }
        }

        // If the page is not available, replace the least recently used
        if (avail == 0) {
            for (int j = 1; j < k; j++) {
                if (time[j] < time[least]) {
                    least = j; // Find the least recently used frame
                }
            }
            frames[least] = pages[i]; // Replace it with the new page
            time[least] = i; // Update the access time
            count++;
        }
    }
    return count;
}

int main() {
    int n, pages[50], frames[50], k;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &k);
    int fault = getFault(pages, frames, n, k);
    printf("Page faults are: %d\n", fault);
    return 0;
}
