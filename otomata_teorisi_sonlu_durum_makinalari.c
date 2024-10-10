#include <stdio.h>
#include <stdlib.h>

int kacinci(char dizi[], char c){
	int i, j=0;
	for(i=0;i<strlen(dizi);i++){
		if(c==dizi[i]){
			j=i;
			break;
		}
	}
	return j;
}


int main() {
	
	int state_sayisi, alfabe_boyut,i, c_alfabe_boyut;
	
	
	printf("Hos geldiniz ! Oncellikle gecis diyagramini olusturalim. Kac tane sonlu durum var?");
	scanf("%d", &state_sayisi);
	
	
	printf("\nGirdi Alfabeniz kac sembolden olusuyor ? ");
	scanf("%d", &alfabe_boyut);
	
	char girdi_alfabe[alfabe_boyut];
	
	printf("\nGirdi Alfabesinin sembollerini giriniz (sirasiyla ve aralarinda bosluk olmadan , orn : ab) :");
	
    scanf("%s", girdi_alfabe );   //girdi_alfabesi
	
	
	printf("\nCikti Alfabeniz kac sembolden olusuyor ? ");
	scanf("%d", &c_alfabe_boyut);

	char cikti_alfabe[c_alfabe_boyut];
	
	printf("\nCikti Alfabesinin sembollerini giriniz (sirasiyla ve aralarinda bosluk olmadan , orn : 01):");
	
	scanf("%s", cikti_alfabe ); //cikti alfabesi
	
	int gecis_cikti_tablosu[state_sayisi][alfabe_boyut*2];
	int gecici;
	
	fflush(stdin);
	
	int j, kontor2;
	
	for(i=0;i<state_sayisi;i++){
		printf("%d. durum icin :\n",i);
		for(j=0;j<alfabe_boyut;j++){
			
			kontor2=j*2;
			
			printf("%c girdisinde ciktiyi giriniz :", girdi_alfabe[j] );
			scanf("%d", &gecici);
			gecis_cikti_tablosu[i][kontor2]=gecici;
			fflush(stdin);
			
			printf("%c girdisiyle varilan durumu giriniz(durum no'sunu giriniz, orn q1 ise 1 giriniz) :", girdi_alfabe[j] );
			scanf("%d", &gecici);
			gecis_cikti_tablosu[i][kontor2+1]=gecici;
			fflush(stdin);
			
		
		}
	}
	
	
	/*
	printf("\nolusan matris:\n");
	
	for(i=0;i<state_sayisi;i++){
    	for(j=0;j<alfabe_boyut*2;j++){
    		printf("%d",gecis_cikti_tablosu[i][j] );
		}
		printf("\n");
	}
	
	*/ //bu kod, matris olarak kaydedilen gecis tablosu ve cikti tablosunu yazdirmak icindir, bu iki tablo tek bir matriste tutuluyor
	
	char input_string[20];
	
	printf("Lutfen bir string giriniz :");
	scanf("%s", input_string);
	
	int string_boyut=strlen(input_string);
	
	printf("\n");
	
	printf("input:     ");
	
	for(i=0;i<string_boyut;i++){
		printf("%c  ", input_string[i]);
	}
	
	printf("\n");
	
	int current_state=0, index;
	int output_dizi[string_boyut];
	int stateler_dizisi[string_boyut];
	int k=0;
	
	for(i=0;i<string_boyut;i++){
		
		index=kacinci(girdi_alfabe,input_string[i]);
		kontor2=index*2;
		output_dizi[k]=gecis_cikti_tablosu[current_state][kontor2];
		stateler_dizisi[k]=gecis_cikti_tablosu[current_state][kontor2+1];
		current_state=gecis_cikti_tablosu[current_state][kontor2+1];
	    k++;
	
	}
	
	printf("output:    ");
	
	for(i=0;i<string_boyut;i++){
		printf("%d  ", output_dizi[i] );
	}
	
	printf("\n");
	
	printf("state:q0 ");
	
	for(i=0;i<string_boyut;i++){
    	printf(" q%d", stateler_dizisi[i] );
	}
	
	
	
	
	
	return 0;
}










