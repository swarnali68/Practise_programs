#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	char buff[512];
	char buff2[512];

	mkfifo("/tmp/myfifo", 0666);

	while(1)
	{
		fd = open("/tmp/myfifo", O_WRONLY);

		fgets(buff, sizeof(buff), stdin);
		write(fd, buff, sizeof(buff));
		close(fd);

		fd = open("/tmp/myfifo", O_RDONLY);

		read(fd, buff2, sizeof(buff2));
		printf("user2: %s", buff2);
		close(fd);
	}
	return 0;
}
