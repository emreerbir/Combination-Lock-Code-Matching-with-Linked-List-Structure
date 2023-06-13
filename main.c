#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Cark{
	int sayi;
	struct Cark* next;
	struct Cark* prev;
}cark;


int ortakSayiUret(int n);
void carkOlustur(int n, int m, cark* cark1, cark* cark2, cark* cark3, int ortakSayi);
void carkKaristir(cark* cark1, cark* cark2, cark* cark3, int m);
int carkKontrol(cark* tmp, cark* cark, int i);
int ucluKontrol(int m, int i, cark* cark1, cark* cark2, cark* tmp3);
void ortakSayiBul(cark* cark1, cark* cark2, cark* cark3, int m, int *knm1, int *knm2, int *knm3);
void carkYazdir(cark* head_cark);
cark* donmeYonu(cark* cark2, int knm1, int knm2, int m);
void degerAl(int *n, int *m);
int degerKontrol(int i, int j);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int n, m, ortakSayi;
	int knm1, knm2, knm3;
	cark* cark1;	
	cark* cark2;
	cark* cark3;
	
	cark1 = (cark*)malloc(sizeof(cark)); 
	cark2 = (cark*)malloc(sizeof(cark)); 
	cark3 = (cark*)malloc(sizeof(cark)); 
	
	
	degerAl(&n, &m);
	ortakSayi = ortakSayiUret(n);
	carkOlustur(n, m, cark1, cark2, cark3, ortakSayi);
	carkYazdir(cark1);
	carkYazdir(cark2);
	carkYazdir(cark3);
	ortakSayiBul(cark1, cark2, cark3, m, &knm1, &knm2, &knm3);
	cark2 = donmeYonu(cark2, knm1, knm2, m);
	cark3 = donmeYonu(cark3, knm1, knm3, m);
	carkYazdir(cark1);
	carkYazdir(cark2);
	carkYazdir(cark3);
	
	return 0;
}

void degerAl(int *n, int *m){
	do{
		printf("Sayilar 1-n arasinda deger alacaktir. n degerini giriniz: ");
		scanf("%d", n);
		printf("1-%d arasinda kac adet sayi olacagini giriniz: ", *n);
		scanf("%d", m);	
	}while(degerKontrol(*n, *m));
}

int degerKontrol(int i, int j){
	if(i< 2*j){
		printf("\nHatali deger! Tekrar giriniz.\n\n");
		return 1;
	}
	else{
		return 0;
	}
}

int ortakSayiUret(int n){
	int ortak = rand() % n + 1;
	
}

void carkOlustur(int n, int m, cark* cark1, cark* cark2, cark* cark3, int ortakSayi){
	int i;
	
	cark1->sayi=ortakSayi;
	cark1->next=NULL;	
	cark1->prev=cark1;
	cark2->sayi=ortakSayi;
	cark2->next=NULL;
	cark2->prev=cark2;
	cark3->sayi=ortakSayi;
	cark3->next=NULL;
	cark3->prev=cark3;
	
	for(i=1;i<m;i++){
		cark* tmp1 = (cark*)malloc(sizeof(cark));
		do{
			tmp1->sayi = rand() % n + 1;
		}while(carkKontrol(tmp1, cark1, i));
		tmp1->next=cark1;
		tmp1->prev=cark1->prev;
		tmp1->prev->next=tmp1;
		cark1->prev=tmp1;
		cark1=tmp1;
		
		cark* tmp2 = (cark*)malloc(sizeof(cark));
		do{
			tmp2->sayi = rand() % n + 1;
		}while(carkKontrol(tmp2, cark2, i));
		tmp2->next=cark2;
		tmp2->prev=cark2->prev;
		tmp2->prev->next=tmp2;
		cark2->prev=tmp2;
		cark2=tmp2;
		
		
	}
	
	for(i=1;i<m;i++){
		cark* tmp3 = (cark*)malloc(sizeof(cark));
		do{
			tmp3->sayi = rand() % n + 1;
		}while(carkKontrol(tmp3, cark3, i) || ucluKontrol(m, i, cark1, cark2, tmp3));
		tmp3->next=cark3;
		tmp3->prev=cark3->prev;
		tmp3->prev->next=tmp3;
		cark3->prev=tmp3;
		cark3=tmp3;
	}
	
	carkKaristir(cark1, cark2, cark3, m);
}



int carkKontrol(cark* tmp, cark* carkB, int i){
	int j;
	cark* tmpc = carkB;
	for(j=0;j<i;j++){
		if(tmpc->sayi==tmp->sayi){
			return 1;
		}
		tmpc=tmpc->next;
	}
	return 0;
}

int ucluKontrol(int m, int i, cark* cark1, cark* cark2, cark* tmp3){
	int j;
	cark* tmpc1 = (cark*)malloc(sizeof(cark));
	cark* tmpc2 = (cark*)malloc(sizeof(cark));
	tmpc1 = cark1;
	tmpc2 = cark2;
	for(j=1; j<m; j++){
		if(tmp3->sayi==tmpc1->sayi && tmp3->sayi==tmpc2->sayi){
			return 1;
		}
		tmpc1 = tmpc1->next;
		tmpc2 = tmpc2->next;
	}
	return 0;
}

void carkKaristir(cark* cark1, cark* cark2, cark* cark3, int m){
	int a, b, c, i, tmp;
	cark *tmp1, *tmp2, *tmp3;
	
	a = rand() % m +1;
	do{
		b = rand() % m +1;
	}while(b==a);
	
	do{
		c = rand() % m +1;
	}while(c==a || c==b);
	
	tmp = cark1->prev->sayi;
	tmp1 = cark1;
	for(i=1;i<a;i++){
		tmp1 = tmp1->next;
	}
	cark1->prev->sayi = tmp1->sayi;
	tmp1->sayi = tmp;
	
	
	tmp = cark2->prev->sayi;
	tmp2 = cark2;
	for(i=1;i<b;i++){
		tmp2 = tmp2->next;
	}
	cark2->prev->sayi = tmp2->sayi;
	tmp2->sayi = tmp;
	
	
	tmp = cark3->prev->sayi;
	tmp3 = cark3;
	for(i=1;i<c;i++){
		tmp3 = tmp3->next;
	}
	cark3->prev->sayi = tmp3->sayi;
	tmp3->sayi = tmp;
	
	
	
}

void carkYazdir(cark* head_cark){
	cark* tmp = head_cark;

	do{
		printf("%d \n", tmp->sayi);
		tmp = tmp->next;
	}while(tmp!=head_cark);
	printf("\n");
}

void ortakSayiBul(cark* cark1, cark* cark2, cark* cark3, int m, int* knm1, int* knm2, int* knm3){
	cark* tmp1, *tmp2, *tmp3;
	tmp1 = cark1;
	tmp2 = cark2;
	tmp3 = cark3;
	
	int i, j, k;
	
	for(i=0;i<m;i++){
		tmp2 = cark2;
		for(j=0;j<m;j++){
			if(tmp1->sayi==tmp2->sayi){
				tmp3 = cark3;
				for(k=0;k<m;k++){
					if(tmp1->sayi==tmp3->sayi){
						printf("Ortak sayi = %d\n", tmp1->sayi);
						printf("Ortak sayinin 1. carktaki konumu: %d\n", i+1);
						printf("Ortak sayinin 2. carktaki konumu: %d\n", j+1);
						printf("Ortak sayinin 3. carktaki konumu: %d\n\n", k+1);
						*knm1 = i;
						*knm2 = j; 
						*knm3 = k;
					}
					tmp3 = tmp3->next;
				}
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	
	
}

cark* donmeYonu(cark* cark2, int knm1, int knm2, int m){
	int i, fark=(knm1-knm2);
	cark* tmpd = cark2;
	if(fark < (m/2) && fark > -(m/2)){
		if(fark>0){
			for(i=0;i<fark;i++){
				tmpd = tmpd->prev;
			}
		}
		
		else{
			for(i=0;i<-fark;i++){
				tmpd = tmpd->next;
			}
		}
	}
	
	else{
		if(fark>0){
			for(i=0;i<m - fark;i++){
				tmpd = tmpd->next;
			}
		}
		else{
			for(i=0;i<m+fark;i++){
				tmpd = tmpd->prev;
			}
		}
	}
	return tmpd;
}















