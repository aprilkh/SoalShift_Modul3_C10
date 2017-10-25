#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

void faktorial(int angka)
{
	pthread_t id = pthread_self();
	if (angka >= 1)
	return angka*faktorial(angka-1);
	else
	return 1;
}

int main()
{
	int angka;
	scanf("%d", &angka);
	printf("Hasil %d! = %d\n", angka, faktorial(angka));
	return 0;
}	
