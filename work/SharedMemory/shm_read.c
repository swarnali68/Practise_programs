#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>

int main()
{
        key_t key;
        int shmid;
        char* p;
        void* mem;

        /*Initialize*/
        shmid = shmget(12345678,1024,IPC_CREAT|0666);

        /*attach*/
        mem = shmat(shmid,NULL,0);

        p = (char*) mem;

	printf("%s\n",p);
        /*Detach*/
        shmdt(mem);

        return 0;

}

