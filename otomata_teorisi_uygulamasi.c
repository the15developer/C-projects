#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

typedef struct dugum{
	char ifade[10];
	struct dugum *next;
}DUGUMLER;

typedef struct liste{
	DUGUMLER dizi[10];
}LISTELER;

int hangisi(char c, char *string){
	int i, a;
	for(i=0;i<strlen(string);i++){
		if(string[i]==c){
			a=i;
			return a;
		}
	}
}

int upperVarMi(char *string, char *dizi){
	int boyut = strlen(string);
	int i, ascii, flag=0, k=0;
	for(i=0;i<boyut;i++){
		ascii=string[i];
		if(ascii>=65 && ascii<=90){
			flag = 1;
			dizi[k]=string[i];
			k++;
		}
	}
	dizi[k]='\0';
	if(flag==1)
	return 1;
	else
	return 0;
}


int main() {
	
	
	char st1[20], st2[50];
	char giris_alfabesi[10];
	
	printf("Lutfen giris alfabesini giriniz:");
	scanf("%[^\n]s", st1);
	
	printf("Girilen : %s", st1);
	
	
	int boyut = strlen(st1);
	int i, k=0;
	
	for(i=0; i< boyut; i++){
		if(st1[i]=='{' || st1[i]=='}' || st1[i]==',' || isspace(st1[i])!= 0 ){
			continue;
		}
		else{
		giris_alfabesi[k]=st1[i];
		k++;	
		}
	}
	
	printf("Giris alfabesi : %s", giris_alfabesi);
	
	printf("Lutfen CFG giriniz :");
	scanf("%s", st2);
	
	printf("Girilen : %s", st2);
	boyut = strlen(st2);
	
	
	char nonterm[10];
	
	LISTELER tablo;
	
	DUGUMLER *gecici= &tablo.dizi[0];
	DUGUMLER *gecici2;

	int ascii;
	
	int j=0,r;
    k=0, i=0;


  while(i<boyut){ 
    ascii=st2[i];

    if(i==0 || st2[i-1] ==','){
      nonterm[k] = st2[i];
      gecici = &tablo.dizi[k];
      k++;
      i++;
      
    }

    else if(st2[i]=='-'){
    i=i+3;
    
    }
    
    else if(st2[i]==','){
    	j=0;
    	i++;
    
	}

    else if(st2[i] == '|') {
    gecici->ifade[j]='\0';
    j=0;

    gecici->next = (DUGUMLER*)malloc(sizeof(DUGUMLER));

    gecici=gecici->next;
    i++;
    
    }

    else if( (ascii>=65 && ascii<=90) || (ascii>=97 && ascii<=122) ){
    
    gecici->ifade[j] = st2[i];
    j++;
    i++;
    
    }
    
    else{
    	i++;
    	
	}


}
    gecici->ifade[j]='\0';
    nonterm[k]='\0';
    

	printf("simdi bakalim dogru mu :");
	
	for(i=0;i<2;i++){
		printf("%d.", i);
		gecici=&tablo.dizi[i];
		
		while(gecici!=NULL){
			printf("%s,", gecici->ifade);
			gecici=gecici->next;
		}	
		printf("\n");
		
	}
	
	char nt[5],hey[5];
	char matris[20][10];
	int x,h,v,o;
	j=0; 
	
	
	for(i=0;i<k;i++){
		
	gecici=&tablo.dizi[i];
	
	while(gecici!=NULL){
		
		x=upperVarMi(gecici->ifade, nt);
		strcpy(hey,nt);
		
		if( x==0 ){
		strcpy(matris[j],gecici->ifade);
		j++;	
		}
		
		else{
		o=0;	
		for(v=0;v<strlen(gecici->ifade);v++){
			ascii=gecici->ifade[v];
			
			if( ascii>=65 && ascii<=90 ){
				h=hangisi(gecici->ifade[v]);
				gecici2=&tablo.dizi[h];
				while(gecici2!=NULL){
					for(r=0;r<strlen(gecici2->ifade);r++){
						matris[j][o]=gecici2->ifade[r];
						o++;
						j++;	
					}
				gecici=gecici->next;
					
				}
			
			}
			else{
				matris[j][o]=gecici->ifade[v];
				o++;
			}
			
		}	
		j++;	
		}
		
		gecici=gecici->next;
		for(v=0;v<boyut;v++)
	    nt[v]='\0';
	}	
	
}

	printf("matris :");
	
	for(i=0;i<j;i++){
		printf("%s", matris[i]);
		printf("\n");
	}
	

	
	
	
	
	
	return 0;
}








