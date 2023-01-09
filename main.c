#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>

void *myThread(void *str)
{
	char *arg= (char*)str;
	system(arg);
}

void slice_cmd(char arr[], char ret_arr[], char ext[], char text[], int *flag, int *thread_flag)
{
	int i=0, j=0, k=0;

	// ls pwd echo

	while(arr[i]!=' ' && arr[i]!='\n' && arr[i]!='\0')
	{
		ret_arr[i]=arr[i];
		i++;
	}
	i++;
	ret_arr[i-1]='\0';

	// - and .. extensions

	if(arr[i]=='-')
	{
		while(arr[i]!=' ' && arr[i]!='\0')
		{
			ext[j]=arr[i];
			i++;
			j++;
		}
		i++;
	}

	if(arr[i]=='.' && arr[i+1]=='.')
	{
		ext[j]='.';
		ext[j+1]='.';
		i+=2;
		j+=2;
	}
	ext[j]='\0';

	// text part

	while(arr[i]!='\0')
	{
		if(arr[i]=='&' && arr[i+1]=='t')
		{
			*thread_flag=1;
		}
		if(arr[i]=='"')
		{
			i++;
			*flag=1;
		}
		else
		{
			text[k]=arr[i];
			i++;
			k++;
		}
	}
	text[k]='\0';
}

int main()
{
	// INPUT

	char cmd[100]; // INPUT TAKING CMD
	char ret_arr[10]; // FOR STORING LS ECHO CD PWD MKDIR DATE RM CAT
	char ext[10]; // -E OR SAME TYPE OF EXTENSIONS
	char text[80]; // ADDRESS OR ANYTHING PASSED

	char* directory_array[50];
	int pwd_index=-1;
	char home[]="/home/shantanu132";
	printf("********************************************************************************\n");
	printf("             ||       THIS IS THE BEST LINUX SHELL      ||\n");
	printf("********************************************************************************\n\n");

	while(1)
	{
		char cmd[100]=""; // INPUT TAKING CMD
		char ret_arr[10]=""; // FOR STORING LS ECHO CD PWD MKDIR DATE RM CAT
		char ext[10]=""; // -E OR SAME TYPE OF EXTENSIONS
		char text[80]=""; // ADDRESS OR ANYTHING PASSED
		char cwd[100]="";
		int flag=0; // for echo command
		int thread_flag=0; // for thread detection

		// INPUT OF COMMAND 
		printf(">>> ");
		int i;
		for(i=0; i<100; i++)
		{
			char c;
			scanf("%c",&c);
			if(c=='\n')
			{
				break;
			}
			else
			{
				cmd[i]=c;
				//printf("%c",c);
			}
		}
		cmd[i]='\0';
		//printf("%ld %ld %ld %ld",sizeof(cmd),sizeof(ret_arr),sizeof(ext),sizeof(text));

		slice_cmd(cmd,ret_arr,ext,text,&flag,&thread_flag);
		//printf("%s %d\n",directory_array[pwd_index],pwd_index);
		//printf("%d",thread_flag);

		if(thread_flag==1)
		{
			char cmd1[100]="";
			int cm=0;
			while(cmd[cm]!='&')
			{
				cmd1[cm]=cmd[cm];
				cm++;
			}
			pthread_t p1;
			pthread_create(&p1,NULL,myThread,(void*)cmd1);
			pthread_join(p1,NULL);
		}
		else
		{
			if(!strcmp(ret_arr,"cat"))
			{
				int rc=fork();
				if(rc==0) // CHILD PROCESS!
				{
					//printf("INITIATING CHILD PROCESS!\n");
					execl("/home/shantanu132/Desktop/assignment1/cat","/home/shantanu132/Desktop/assignment1/cat",ext,text,NULL);
					//printf("DO NOT PRINT THIS!\n");
				}
				else
				{
					int rc_wait=wait(NULL);
				}
			}
			else if(!strcmp(ret_arr,"mkdir"))
			{
				int rc=fork();
				if(rc==0) // CHILD PROCESS!
				{
					//printf("INITIATING CHILD PROCESS!\n");
					execl("/home/shantanu132/Desktop/assignment1/mkdir","/home/shantanu132/Desktop/assignment1/mkdir",ext,text,NULL);
					//printf("DO NOT PRINT THIS!\n");
				}
				else
				{
					int rc_wait=wait(NULL);
				}
			}
			else if(!strcmp(ret_arr,"date"))
			{
				int rc=fork();
				if(rc==0) // CHILD PROCESS!
				{
					//printf("INITIATING CHILD PROCESS!\n");
					execl("/home/shantanu132/Desktop/assignment1/date","/home/shantanu132/Desktop/assignment1/date",ext,text,NULL);
					//printf("DO NOT PRINT THIS!\n");
				}
				else
				{
					int rc_wait=wait(NULL);
				}

			}
			else if(!strcmp(ret_arr,"rm"))
			{
				int rc=fork();
				if(rc==0) // CHILD PROCESS!
				{
					//printf("INITIATING CHILD PROCESS!\n");
					execl("/home/shantanu132/Desktop/assignment1/rm","/home/shantanu132/Desktop/assignment1/rm",ext,text,NULL);
					//printf("DO NOT PRINT THIS!\n");
				}
				else
				{
					int rc_wait=wait(NULL);
				}
			}
			else if(!strcmp(ret_arr,"ls"))
			{
				int rc=fork();
				if(rc==0) // CHILD PROCESS!
				{
					//printf("INITIATING CHILD PROCESS!\n");
					execl("/home/shantanu132/Desktop/assignment1/ls","/home/shantanu132/Desktop/assignment1/ls",ext,text,NULL);
					//printf("DO NOT PRINT THIS!\n");
				}
				else
				{
					int rc_wait=wait(NULL);
				}
			}
		}

		if(!strcmp(ret_arr,"cd"))
		{
			//printf("%s",ext);
			if(ext[0]!='\0')
			{
				if(ext[0]=='-')
				{
					if(pwd_index==-1 || pwd_index==0)
					{
						printf("DOES NOT EXIST!\n");
					}
					else
					{
						pwd_index--;
						int ch=chdir(directory_array[pwd_index]);
					}
				}
				else if(!strcmp(ext,"..\0"))
				{
					int j=0; // when the last / occurs
					int k=0;
					getcwd(cwd,sizeof(cwd));
					//printf("%s",cwd);

					while(cwd[k]!='\0')
					{
						if(cwd[k]=='/')
						{
							j=k;
						}
						k++;
					}

					char dir[80];
					k=0;
					while(k<j)
					{
						dir[k]=cwd[k];
						k++;
					}
					chdir(dir);
					pwd_index++;
					directory_array[pwd_index]=strdup(dir);
				}
				else
				{
					printf("INVALID COMMAND! (COMMAND NOT FOUND)\n");
				}
			}

			else 
			{
				if(text[0]=='\0')
				{
					chdir("/home/shantanu132");
					pwd_index++;
					directory_array[pwd_index]="/home/shantanu132";
				}
				else if(!strcmp(text,"/\0"))
				{
					chdir("/");
					pwd_index++;
					directory_array[pwd_index]="/";
					
				}
				else
				{
					char dir[]="/";
					strcat(dir,text);
					getcwd(cwd,sizeof(cwd));
					strcat(cwd,dir);
					int ch=chdir(cwd);
					if(ch<0)
					{
						printf("%s: DIRECTORY NOT FOUND (DOES NOT EXIST)!!\n",cwd);
					}
					else
					{
						pwd_index++;
						directory_array[pwd_index]=strdup(cwd);
					}
				}
			}
		}
		else if(!strcmp(ret_arr,"echo"))
		{
			if(ext[0]=='\0')
			{
				int p=0;
				int ind=0;
				char output[100]="";
				
				while(text[p]!='\0')
				{
					if(text[p]=='"')
					{
						p++;
					}
					else if(text[p]=='\\' && flag==1)
					{
						output[ind]=text[p];
						p++;
						ind++;
					}
					else
					{
						if(text[p]!='\\')
						{
							output[ind]=text[p];
							ind++;
						}
						p++;
					}
				}
				printf("%s\n",output);
			}
			else if(!strcmp(ext,"-e\0"))
			{
				int p=0;
				int ind=0;
				char output[100]="";
				while(text[p]!='\0')
				{
					if(text[p]=='\\' && flag==1)
					{
						p++;
						if(text[p]=='n')
						{
							output[ind]='\n';
							ind++;
						}
						else if(text[p]=='c')
						{
							break;
						}
						else if(text[p]=='t')
						{
							output[ind]='\t';
							ind++;
						}
						else
						{
							output[ind]='\\';
							ind++;
							output[ind]=text[p];
							ind++;
						}
						p++;
					}
					else
					{
						output[ind]=text[p];
						p++;
						ind++;
					}
				}
				printf("%s\n",output);
			}
			else if(!strcmp(ext,"-E\0"))
			{
				int p=0;
				int ind=0;
				char output[100]="";
				
				while(text[p]!='\0')
				{
					if(text[p]=='"')
					{
						p++;
					}
					else if(text[p]=='\\' && flag==1)
					{
						output[ind]=text[p];
						p++;
						ind++;
					}
					else
					{
						if(text[p]!='\\')
						{
							output[ind]=text[p];
							ind++;
						}
						p++;
					}
				}
				printf("%s\n",output);
			}
			else
			{
				printf("INVALID COMMAND\n");
			}

		}
		else if(!strcmp(ret_arr,"pwd"))
		{
			if(ext[0]=='\0')
			{
				getcwd(cwd,sizeof(cwd));
				printf("%s\n",cwd);
			}
			else if(!strcmp("-P\0",ext))
			{
				getcwd(cwd,sizeof(cwd));
				printf("%s\n",cwd);
			}
			else if(!strcmp("-L\0",ext))
			{
				char path[100];
				char *env="path";
				if(getenv(env)==NULL)
				{
					getcwd(cwd,sizeof(cwd));
					printf("%s\n",cwd);
				}
			}
			else
			{
				printf("INVALID COMMAND!\n");
			}
		}
		
	}

	return 0;
}