#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argv[1][0]=='\0' && argv[2][0]=='\0')
	{
		struct tm* local;
	    time_t t = time(NULL);
	    local = localtime(&t);
	    printf("%s IST\n",asctime(local));
	}
	else if(!strcmp(argv[1],"-u\0"))
	{
		struct tm* local;
	    time_t t = time(NULL);
	    local = gmtime(&t);
	    printf("%s UTC\n",asctime(local));
	}
	else if(!strcmp(argv[2],"+%D\0"))
	{
		struct tm* local;
		time_t t=time(NULL);
		local=localtime(&t);
	    printf("%d/%d/%d",local->tm_mday,(local->tm_mon+1),(local->tm_year+1900));
	}
	else
	{
		printf("INVALID COMMAND!\n");
	}


	return 0;


}