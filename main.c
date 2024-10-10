#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 15
#define MAX_DUGUM 15

typedef struct dugum{
	char sehir_ismi[MAX_SIZE];
	int plaka_no;
	struct dugum *next;
}DUGUMLER;

typedef struct liste{
	DUGUMLER dizi[MAX_DUGUM];
}LISTELER;


int main() {
	
	int i=0, d, plk, j;
	int boyut,k;
	
	LISTELER liste;
	DUGUMLER* gecici;
	
	char string[110], sehir[MAX_SIZE], plaka[3];
	
	printf("VERILER text dosyadan listeye(grafa) aktariliyor... \n");
	
	FILE *fp;
	fp=fopen("text.txt", "r");
	
	
	
	if(fp==NULL){
		printf("couldn't open file !");
		exit(1);
	}
	
	while(!feof(fp)){
	
	fgets(string, 100, fp);
	boyut = strlen(string); //||
	k=0;
	int is_first=0;
	
	for( j=0; j<boyut;j++){
		
		if((string[j] >= 'A' && string[j] <= 'Z') || (string[j] >= 'a' && string[j] <= 'z')){
			if(string[j] >= 'A' && string[j] <= 'Z'){
				sehir[0]='\0';
				k=0;
				
			}
		sehir[k] = string[j];
		k++;
		}
		
		if(string[j] == '/'){
			sehir[k]='\0';
			d=0;
			if(is_first == 0){
				strcpy((liste.dizi[i].sehir_ismi), sehir);
				liste.dizi[i].next = NULL;
				gecici=&liste.dizi[i];
				is_first++;
			}
			else{
			    gecici = &liste.dizi[i];
				while(gecici->next!=NULL){
					gecici=gecici->next;
				}
				gecici->next = (struct dugum*)malloc(sizeof(struct dugum));
				gecici=gecici->next;
				strcpy((gecici->sehir_ismi), sehir);
				gecici->next=NULL;
			}
		}
		
		if(isdigit(string[j])){
			plaka[d]=string[j];
			d++;
			if(d==2){
				plaka[d]='\0';
				plk= atoi(plaka);
				gecici->plaka_no = plk;
			}
		}
		
		
	}
	
    i++;
}
	
	fclose(fp);
	
	printf("Aktarma tamamlandi ! \n LISTE :\n\n");
	
	for(j=0; j< i; j++){
		if(liste.dizi[j].next == NULL){
			printf(" %s / %d -> NULL", liste.dizi[j].sehir_ismi, liste.dizi[j].plaka_no );
		}
		else{
			gecici=&liste.dizi[j];
			while(gecici!=NULL){
				printf(" %s / %d -> ", gecici->sehir_ismi, gecici->plaka_no );
				gecici=gecici->next;
			}
			printf("NULL");
		}
		printf("\n");
	}
	
	int plaka_secim, gd, cd;
	printf("Lutfen sehir plakasini giriniz : ");
	scanf("%d", &plaka_secim);
	printf("\n%d plakali dugumun giris derecesi : %d, cikis derecesi : %d", plaka_secim, gd, cd);
	
	return 0;
}








