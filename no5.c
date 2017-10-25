#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t anu[100];

void *search(void *argv)
{
	int jumlah=0;
	char nama[500];
	char line[500];
	FILE *novel;
	novel = fopen ("Novel.txt", "r");

	strcpy (nama, argv);
	
	while(1)
	{
		if (fscanf(novel, "%s", line)==EOF) 
		break;
		if(strstr(line, argv)!=NULL)
		jumlah = jumlah+1;
	}
		fclose(novel);
		printf("%s : %d\n", nama, jumlah);
}

int main (int argc, char **argv)
{
	int hm=0;
	for(hm=1; hm<argc; hm++){
		pthread_create(&anu[hm], NULL, search, (void*)argv[hm]);
		}
	for(hm=0; hm<argc; hm++){
		pthread_join(anu[hm], NULL);
		}	
	return 0;
}
		
