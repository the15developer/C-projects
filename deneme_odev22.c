#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	char dizi[3];
	int i;
	
	printf("Alfabeyi giriniz :");
	
	for(i=0; i<3;i++)
	scanf("%c", &dizi[i]);
	
	for(i=0; i<3;i++)
	printf("%c", dizi[i]);
	
	char ilkHarf = dizi[0];
	char ikinciHarf = dizi[2];
	
	
	
	
	return 0;
}









