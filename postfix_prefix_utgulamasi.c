#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>


#define MAX_DIZI 20

typedef struct Yigin{
       int idx;
       int dizi[MAX_DIZI];
}Yiginlar;


void yigina_ekle(Yiginlar* yigin, int sayi) {

    yigin->idx++;
    yigin->dizi[yigin->idx] = sayi;
}


int yigindan_cikar(Yiginlar* yigin) {

    int cikar = yigin->dizi[yigin->idx] ;
    yigin->idx--;
    return cikar;

}


int main() {
	
	Yiginlar yigin;
	yigin.idx=-1;
	
	char ifade_temp[40], ifade[MAX_DIZI], str[3];
	int k, i, j, x, ascii, op1, op2, sonuc;
	char operator;
	
	printf("Lutfen bir ifade giriniz :");	
	gets(ifade_temp);
	
	
	int ifade_t_b = strlen(ifade_temp);
	
	i = ifade_t_b -1;
	
	while(i>=0){
		
		if(isspace(ifade_temp[i])!=0){
			i--;
		}
		
		else{
		
		ascii=ifade_temp[i];
		
		if(ascii>=48 && ascii <=57){
		
		k= i;
		j=0;
		while(isspace(ifade_temp[k])==0){
			k--;
		}
		k++;
		
		
		while(k<=i){
		str[j]=ifade_temp[k];
		k++;
		j++;
		}
		x=atoi(str);
		yigina_ekle(&yigin, x);
		strcpy(str, "jjj");
		i=i-j;

    }
        else{
        	operator = ifade_temp[i];
        	if(ascii==43){
        		op1=yigindan_cikar(&yigin);
        		op2=yigindan_cikar(&yigin);
        		sonuc = op1+op2;
        		yigina_ekle(&yigin, sonuc);
			}
			if(ascii==42){
        		op1=yigindan_cikar(&yigin);
        		op2=yigindan_cikar(&yigin);
        		sonuc = op1*op2;
        		yigina_ekle(&yigin, sonuc);
			}
			if(ascii==47){
        		op1=yigindan_cikar(&yigin);
        		op2=yigindan_cikar(&yigin);
        		sonuc = op1/op2;
        		yigina_ekle(&yigin, sonuc);
			}
			if(ascii==45){
        		op1=yigindan_cikar(&yigin);
        		op2=yigindan_cikar(&yigin);
        		sonuc = op1-op2;
        		yigina_ekle(&yigin, sonuc);
			}
			if(ascii==94){
        		op1=yigindan_cikar(&yigin);
        		op2=yigindan_cikar(&yigin);
        		sonuc = (int)pow(op1,op2);
        		yigina_ekle(&yigin, sonuc);
			}
        
		i--;	
		}

	}
	
	
	}
	
	
	
	printf("SONUC : %d ", yigindan_cikar(&yigin) );




	return 0;
}

























