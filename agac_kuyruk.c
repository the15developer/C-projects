#include <stdio.h>
#include <stdlib.h>

typedef struct Agac{
   char harf;
   int frk;
   struct Agac *sag;
   struct Agac *sol;
}Agaclar;

char karakterler[100];
int k;

int fks(char* str){
    int sayac = 0;
	*(&k)=0;
    int i, j;
    for (i = 0; i < strlen(str); i++){
         int var = 0;
         for ( j = 0; j < i; j++){
              if (str[j] == str[i]){
                  var = 1;
                  break;
              }
         }

         if (var==0){
         	 *(&karakterler[*(&k)])=str[i];
             sayac++;
             (*(&k))++;
         }
        
    }
     return sayac;
}

int frekans(char* str, char kar){
	int i, sayac;
	for (i = 0; i < strlen(str); i++){
		if(str[i]==kar){
		sayac ++;	
		}
	}
	return sayac;
}

Agaclar* extract_min(Agaclar kuyruk[], int n){
	Agaclar* z=(Agaclar*)malloc(sizeof(Agaclar));
	Agaclar* min;
	int contor=0, j=0;
	
	while(&kuyruk[j]==NULL){
		j++;
		contor++;
	}
	
	min=&kuyruk[contor];
	
	for(j=contor+1; j<n;j++){
	if(&kuyruk[j] != NULL){
	if(kuyruk[j].frk < min->frk){
		min=&kuyruk[j];
	}
    }
	}
	   z->frk=min->frk;
	   z->harf=min->harf;
	   z->sag=min->sag;
	   z->sol=min->sol; 
	   
	   min=NULL;
	   
	    
	return z;
	
	}
	


    
Agaclar kuyruk[100];

int main() {
	char mesaj[100];
	int n,i, t;
	Agaclar *h_agac;
	
	printf("Mesaj giriniz :");
	scanf("%[^\n]s", mesaj);
	
	printf("%d \n", fks(mesaj));
	
	n = fks(mesaj);
	Agaclar kuyruk[n];
	
	for(i=0;i<k;i++){
		printf("%c ", karakterler[i]);
		kuyruk[i].harf=karakterler[i];
		kuyruk[i].frk= frekans(mesaj, karakterler[i]);
		kuyruk[i].sag==NULL;
		kuyruk[i].sol==NULL;
	}
	
	for(i=0;i<n-1;i++){
	t=0;
	Agaclar* yeni= (Agaclar*)malloc(sizeof(Agaclar));
	yeni->sol=extract_min(kuyruk,n);
	yeni->sag=extract_min(kuyruk,n);
	yeni->frk=yeni->sol->frk + yeni->sag->frk ;
	yeni->harf='\0';
	
	while(&kuyruk[t] != NULL){
		t++;
	}
	
	kuyruk[t]=*yeni;
	
	}
	
	h_agac = extract_min(kuyruk, n);
	
	return 0;
}






