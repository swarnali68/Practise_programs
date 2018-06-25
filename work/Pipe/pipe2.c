#include<stdio.h>

int main()
{
	char path[512] = "";
	FILE* fp;
	char buff[512];

	fp = popen("ls *", "w");

	while(fgets(buff, 512, fp) > 0)
		printf("%s",buff);


	pclose(fp);
}
