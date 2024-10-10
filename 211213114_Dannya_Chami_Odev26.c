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
	int c=0;;
	char ch;
	
	printf("Hos geldiniz ! Oncellikle gecis tablosunu ve cikti tablosunu olusturalim. Kac tane sonlu durum var?");
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
	
	int j;
	
	int gecis_cikti_tablosu[state_sayisi][alfabe_boyut+1];
	int gecici;
	
	fflush(stdin);
	
for(i=0;i<state_sayisi;i++){
    	
printf("\n%d. durum icin :\n",i);
        
    for(j=0;j<=alfabe_boyut;j++){
      	
    if(j==alfabe_boyut){
        printf("karakter ciktisi:");   
	}
    else{
    	printf("%c girdisinden sonra gecilen durum :", girdi_alfabe[j]);
    }
    gecici=getchar();
	gecis_cikti_tablosu[i][j]=gecici;
	
	fflush(stdin);
}

}

/*    for(i=0;i<state_sayisi;i++){
    	for(j=0;j<=alfabe_boyut;j++){
    		printf("%c",gecis_cikti_tablosu[i][j] );
		}
		printf("\n");
	}
*/ //bu kod, matris olarak kaydedilen gecis tablosu ve cikti tablosunu yazdirmak icindir, bu iki tablo tek bir matriste tutuluyor

    char input_string[20];
    
    printf("Lutfen string giriniz :");
    scanf("%s", input_string);
    
    int string_boyut=strlen(input_string);
    int index;
    int current_state=0;
    char output_string[20];;
    char first = gecis_cikti_tablosu[0][alfabe_boyut];
    int kontor=0;
    
    printf("\nGirdiginiz string :\n");
    
    printf("    ");
    for(i=0;i<string_boyut;i++){
    	printf("%c  ", input_string[i]);
	}
	
    
    printf("\n");
    printf("q%d ", current_state);
    
    for(i=0;i<string_boyut;i++){
    	index=kacinci(girdi_alfabe, input_string[i]);
    	current_state=(gecis_cikti_tablosu[current_state][index])-'0';
    	output_string[kontor]=gecis_cikti_tablosu[current_state][alfabe_boyut];
    	printf("q%d ", current_state);
    	kontor++;
	}
	
	
	printf("\n");
	printf("%c   ", first);
	
	for(i=0;i<string_boyut;i++){
		printf("%c  ", output_string[i]);
	}
	
	

	return 0;
}









