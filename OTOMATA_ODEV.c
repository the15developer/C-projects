#include <stdio.h>
#include <stdlib.h>



int main() {
	int state_sayisi, alfabe_boyut,i, c_alfabe_boyut;
	int c=0;;
	char ch;
	
	printf("Merhaba  ! Kac tane sonlu durum var?");
	scanf("%d", &state_sayisi);
	
	
	printf("\nGirdi Alfabeniz kac sembolden olusuyor ? ");
	scanf("%d", &alfabe_boyut);
	
	char girdi_alfabe[alfabe_boyut];
	
	printf("\nGirdi Alfabesinin sembollerini giriniz :");
	
    scanf("%s", girdi_alfabe );   //girdi_alfabesi
	
	
	printf("\nCikti Alfabeniz kac sembolden olusuyor ? ");
	scanf("%d", &c_alfabe_boyut);

	char cikti_alfabe[c_alfabe_boyut];
	
	printf("\nCikti Alfabesinin sembollerini giriniz :");
	
	scanf("%s", cikti_alfabe ); //cikti alfabesi
	
	int j;
	
	int gecis_cikti_tablosu[state_sayisi][alfabe_boyut+1];
	int gecici;
	int e;
	e=getchar();
	
for(i=0;i<state_sayisi;i++){
    	
printf("%d. durum icin :",i+1);
        
    for(j=0;j<=alfabe_boyut;j++){
      	
    if(j==alfabe_boyut){
        printf("karakter ciktisi:");   
	}
    else{
    	printf("%c girdisinden sonra gecilen durum :", girdi_alfabe[j]);
    }
    gecici=getchar();
	gecis_cikti_tablosu[i][j]=gecici;
}

}

    for(i=0;i<state_sayisi;i++){
    	for(j=0;j<alfabe_boyut;j++){
    		printf("%d",gecis_cikti_tablosu[i][j] );
		}
		printf("\n");
	}


	return 0;
}






















