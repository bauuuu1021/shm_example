#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int test_func(int val) {
	int ret = val+1;
	return ret;
}

int *ptr;

int main () {
	int id;

	printf("[server] pid %d\n", getpid());

	if ((id = shmget(IPC_PRIVATE, 4096, IPC_CREAT | 0660)) < 0) {
		perror("[server] shmget ");
		return -1;
	}
	printf("[server] shm_id %d\n", id);
	
	if ((ptr = (int *)shmat(id, NULL, 0)) < 0) {
		perror("[server] shmat ");
		return -1;
	}
	printf("[server] shm  %p\n", (void *)ptr);

	while (getchar()) {
		printf("%d\n", ptr[0]);
		ptr[0] = test_func(ptr[0]);
		printf("%d\n", ptr[0]);
	}
}
