#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int *ptr;

int main () {
    int id;

    printf("[client] pid %d\n", getpid());
    printf("[client] insert shm_id:");
    scanf("%d%*c", &id);

    // Attach the memory section, the return value is a pointer to 
    // the shared memory section
    if ((ptr = (int *)shmat(id, NULL, 0))  == (int *)-1) {
        perror("[client] shmat ");
        return -1;
    }
    
    printf("[client] The original value is %d\n", ptr[0]);
    printf("[client] Press enter to decrease the value\n");
    
    while (getchar()) {
        printf("Before: %d\n", ptr[0]);
        ptr[0] = ptr[0]-1;
        printf("After : %d\n", ptr[0]);
    }
}
