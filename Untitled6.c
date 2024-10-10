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
    int k;
    k=getchar();
    printf("%d", k+3);
    
    int x = k -'0';
    printf(" %d", x+3);
    
	return 0;
}






