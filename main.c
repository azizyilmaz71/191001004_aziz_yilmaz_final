#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void GirisMetini(char mabilya[][20], char kalite[][20], int mabilyaFiyat[4], int kaliteFiyat[3], float toplamFiyat);
float metrekareHesap(float en, float uzunluk);
float FiyatHesaplama(int mobilya, int kalite, float metrekare);

int main(int argc, char *argv[]) {
	char durum;
	float toplamFiyat;
	char mabilya[][20] = { "Mutfak Dolabi", "Gardirop", "Yatak", "Masa" };
	char kalite[][20] = { "Ahsap", "Mdf", "Sunta" };
	int mabilyaFiyat[4] = { 4, 3, 2, 1 };
	int kaliteFiyat[3] = { 1000, 750, 400 };
	while(1){
		GirisMetini(mabilya, kalite, mabilyaFiyat, kaliteFiyat, toplamFiyat);
		printf("Devam etmek istermisiniz(E), (H): \n");
		scanf("%s", &durum);
		if(durum=='H')
			break;
		else{
			continue;
		}
	}
	
	return 0;
}


void GirisMetini(char mabilya[][20], char kalite[][20], int mabilyaFiyat[4], int kaliteFiyat[3], float toplamFiyat){
	printf("Magazamiza hos geldiniz!!\n");
	int i, mobilyaSecim, kaliteSecim;
	float en, uzunluk, metrekare, urunFiyat;
	
	printf("Urunler \n");
	for(i=0; i<4; i++){
		printf("%d- %s\n", i+1, mabilya[i]);
	}
	printf("Urun seciniz(1,2,3,4) \n");
	scanf("%d", &mobilyaSecim);
	
	printf("Kalite \n");
	for(i=0; i<3; i++){
		printf("%d- %s\n", i+1, kalite[i]);
	}
	printf("Kalite seciniz(1,2,3) \n");
	scanf("%d", &kaliteSecim);
	
	
	printf("En giriniz(metre): \n");
	scanf("%f", &en);
	printf("Uzunluk giriniz(metre): \n");
	scanf("%f", &uzunluk);
	
	metrekare = metrekareHesap(en, uzunluk);
	
	urunFiyat = FiyatHesaplama(mabilyaFiyat[mobilyaSecim-1], kaliteFiyat[kaliteSecim-1], metrekare);
	toplamFiyat = toplamFiyat + urunFiyat;
	
	printf("%s %s, %f metrekare, Toplam Fiyat %fTL \n", kalite[kaliteSecim-1], mabilya[mobilyaSecim-1], metrekare, toplamFiyat);
	
}

float metrekareHesap(float en, float uzunluk){
	return en*uzunluk;
}

float FiyatHesaplama(int mobilya, int kalite, float metrekare){
	return mobilya*kalite*metrekare;
}

