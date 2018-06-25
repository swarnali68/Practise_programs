#include<stdio.h>
#include<sys/stat.h>
//#include <string.h>
#include <fcntl.h>
//#include <sys/stat.h>
//#include <sys/types.h>
//#include <unistd.h>

int main()
{
        int fd2;
        char buff[512];
        char buff2[512];

        mkfifo("/tmp/myfifo", 0666);

        while(1)
        {
                fd2 = open("/tmp/myfifo", O_RDONLY);

                read(fd2, buff2, sizeof(buff2));
                printf("user1: %s", buff2);
                close(fd2);

                fd2 = open("/tmp/myfifo", O_WRONLY);

                fgets(buff, sizeof(buff), stdin);
                write(fd2, buff, sizeof(buff));
                close(fd2);

        }
        return 0;
}

