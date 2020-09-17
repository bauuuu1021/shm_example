#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int *ptr;

int main () {
    int id;

    // Create a shared memory section
    if ((id = shmget(IPC_PRIVATE, 4096, IPC_CREAT | 0660)) < 0) {
        perror("[server] shmget ");
        return -1;
    }

    printf("[server] shm_id %d\n", id);
    printf("[server] Copy the shm_id above to the client program\n\n");

    // Attach the memory section, the return value is a pointer to 
    // the shared memory section
    if ((ptr = (int *)shmat(id, NULL, 0)) < 0) {
        perror("[server] shmat ");
        return -1;
    }

    printf("[server] The original value is %d\n", ptr[0]);
    printf("[server] Press enter to increase the value\n");

    while (getchar()) {
        printf("Before: %d\n", ptr[0]);
        ptr[0] = ptr[0]+1;
        printf("After : %d\n", ptr[0]);
    }
}
