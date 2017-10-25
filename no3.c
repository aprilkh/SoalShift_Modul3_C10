#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid1;
pthread_t tid2;
int status=0;
int statusloh=100;
int statuskep=100;

void* loh(void *arg)
{
	while(statusloh>=100){
	sleep(15);
	statusloh = statusloh-15;}
}

void* kep(void *arg)
{
	while(statuskep>=100){
	sleep(10);
	statuskep = statuskep-10;}
}

int main()
{
	pthread_create(&(tid1), NULL, &loh, NULL);
	pthread_create(&(tid2), NULL, &kep, NULL);
	
	while(status!=1)
	{
	int pilih;
	printf("Status Lohan %d\n", statusloh);
	printf("Status Kepiting %d\n", statuskep);
	printf("1. Beri Makan Lohan\n");
	printf("2. Beri Makan Kepiting\n");
	scanf ("%d", &pilih);
	if (pilih == 1)
	statusloh = statusloh+10;
	else if (pilih == 2)
	statuskep = statuskep+10;

	if(status == 1 || statusloh > 100 || statuskep > 100){
		printf("Game Over\n");
		return 0;
		}
	}
	return 0;
}

