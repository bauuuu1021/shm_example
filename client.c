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

    if ((ptr = (int *)shmat(id, NULL, 0))  == (int *)-1) {
        perror("[client] shmat ");
	return -1;
    }
    printf("[client] shm_addr  %p\n", ptr);

    while (getchar()) {
        printf("%d\n", ptr[0]);
        ptr[0] = ptr[0]-2;
        printf("%d\n", ptr[0]);
    }
}
