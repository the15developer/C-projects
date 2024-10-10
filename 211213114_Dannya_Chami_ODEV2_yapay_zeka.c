#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 15
#define MAX_DUGUM 20

char color[20];
	int d[20];
	int time;
	int pred[20];
	int f[20];
	int distance[20];
	
char sehirler[13][20] = {"Arad", "Timisoara", "Sibiu", "Zerind", "Lugoj", "Rimnicu Valcea", "Fagaras", "Oradea", "Mehadia", "Craiova", "Pitesti", "Bucuresti", "Drobeta"};

int matris[20][20];


typedef struct Kuyruk{
	int eleman[15];
	int indis;
}Kuyruklar;

int kuyruktan_cikar(Kuyruklar *k){
	int cikan, i;
	cikan=k->eleman[0];
	for(i=0;i<k->indis;i++){
		k->eleman[i]=k->eleman[i+1];
	}
	k->indis--;
	return cikan;
	
}

void kuyruga_ekle(Kuyruklar *k, int n){
	k->indis++;
	k->eleman[k->indis]=n;
}

void DFSVisit(int n){
	color[n]='g';
	d[n]=++time;
	printf("%s ", sehirler[n]);
	
	if(n==11){
		printf("\nBUKRES BULUNMUSTUR\n");
	}
	
	int j;
	for(j=0;j<20;j++){
		if( matris[n][j] >-1 && color[j]=='w'){
			pred[j]=n;
			distance[j]=distance[n]+matris[n][j];
			DFSVisit(j);
		}
	}
	
	color[n]='b';
	f[n]=++time;
	
}


int main() {
	
	Kuyruklar kuyruk;
	kuyruk.indis=-1;
	int a=getchar();
	char b;
	
	printf("eeeeeeee %c eeeeeeee", a);
	b=a;
	printf("eeeeeeee %c eeeeeeee", b);
	

	int i, j;
	   
	 	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
		matris[i][j]=-1;	
		}
	
	}
	
	
	matris[0][1]=118;
	matris[0][2]=140;
	matris[0][3]=75;
	matris[1][0]=118;
	matris[1][4]=111;
	matris[2][0]=140;
	matris[2][5]=80;
	matris[2][6]=99;
	matris[2][7]=151;
	matris[3][0]=75;
	matris[3][7]=71;
	matris[4][1]=111;
	matris[4][8]=70;
	matris[5][2]=80;
	matris[5][9]=146;
	matris[5][10]=97;
	matris[6][2]=99;
	matris[6][11]=211;
	matris[7][2]=151;
	matris[7][3]=71;
	matris[8][4]=70;
	matris[8][12]=75;
	matris[9][10]=138;	
    matris[12][9]=120;
    matris[10][11]=101;
    

	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
		printf("%d ", matris[i][j] );
		}
		printf("\n");
	}

   //BFS
 
    for(i=0;i<20;i++){
    	color[i]='w';			
	}
	
	for(i=0;i<20;i++){
    	d[i]=-1;			
	}
	
	for(i=0;i<20;i++){
     	pred[i]=-1;			
	}
	
	color[0]='g';
	d[0]=0;
	kuyruk.indis++;
	kuyruk.eleman[kuyruk.indis]=0;

	int u;
	
    printf(" BFS : Dugumlerin islenme sirasi :");
    
    while(kuyruk.indis>-1)	{
	u=kuyruktan_cikar(&kuyruk);
	printf("%s ", sehirler[u]);
	
	if(u==11){
	printf("\nBUKRES BULUNMUSTUR");
	break;}
	
	for(i=0;i<20;i++){
	 if(matris[u][i]>-1 && color[i] == 'w'){
	 	color[i]='g';
	 	d[i]=d[u]+matris[u][i];
	 	pred[i]=u;
	 	kuyruga_ekle(&kuyruk, i);
	 }	
				
}
    color[u]='b';
    
}

printf("\nBFS ile Arad'dan Bukres'e mesafe : %d \n", d[11]);

	//DFS
	
	time=0;
	
	
	for(i=0;i<20;i++){
    	d[i]=-1;			
	}
	

	
	for(i=0;i<20;i++){
		color[i]='w';	
		pred[i]=-1;
	}
	
	distance[0]=0;
	
	printf("DFS : dugumlerin ziyaret edilme sirasi :");
	
        i=0;     
    	if(color[i]=='w'){
    		DFSVisit(i);
		}
	
	printf("\nDFS ile Arad'dan Bukres'e mesafe : %d\n", distance[11]);
   
	
	return 0;
}


















