#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
FILE *dosya, *temp_dosya;

struct stoklar{
char isim[20],gram[20],fiyat[20],aciklama[60],kod[20];
};
struct stoklar urun;


void ekle(){
		
    int giris;

	
	dosya = fopen("stok.txt","a+");
	
    printf("Ürün kodu : ");
	scanf(" %s",urun.kod);
	printf("Ürün adi : "); 
	scanf(" %s",urun.isim);
	printf("Gram : "); 
	scanf(" %s",urun.gram);
	printf("Fiyat : "); 
	scanf(" %s",urun.fiyat);
	printf("Ürün açiklamasi : ");
	scanf(" %s",urun.aciklama);
	
	
	fprintf(dosya,"%s \t %s \t %s \t %s \t %s\n",urun.kod,urun.isim,urun.gram,urun.fiyat,urun.aciklama);
	

	fclose(dosya);
	
	printf ("Stok eklemeye devam et (1)\n");
    printf ("Ana menü (2)\n");
    scanf("%d",&giris);
    	
		if (giris==1){
		ekle();
	} else {
		main();
	}

}
void kontrol(){

    printf("\n");

    dosya = fopen("stok.txt","r");

    if(dosya == NULL){

        printf("Dosya okunamiyor.\n");
        return;
    }

    while(!feof(dosya)){

        fputchar(fgetc(dosya));
    }

    fclose(dosya);
    main();
}
void guncelleme(){
	char kod[20], guncel_isim[20], guncel_gram[20], guncel_fiyat[20],guncel_aciklama[60];
	dosya = fopen("stok.txt","r+");
	temp_dosya = fopen("temp_stok.txt","a+");
	int enabled = 1;
	
	printf("Guncellenecek urun kodu giriniz: ");
	scanf("%s", &kod);
	
	while(fscanf(dosya,"%s\t %s\t %s\t %s\t %s\n",urun.kod,urun.isim,urun.gram,urun.fiyat,urun.aciklama)!=EOF){
	 	if(strcmp(urun.kod, kod)){
	 		fprintf(temp_dosya,"%s\t %s\t %s\t %s\t %s\n",urun.kod,urun.isim,urun.gram,urun.fiyat,urun.aciklama);
		 } else{
		 	printf("Yeni isim: ");
		 	scanf("%s",&guncel_isim);
		 	printf("Yeni gram: ");
		 	scanf("%s",&guncel_gram);
		 	printf("Yeni fiyat: ");
		 	scanf("%s",&guncel_fiyat);
		 	printf("Yeni açiklama: ");		 	
			scanf("%s",&guncel_aciklama);
		
			
			strcpy(urun.isim,guncel_isim);
		 	strcpy(urun.gram,guncel_gram);
		 	strcpy(urun.fiyat,guncel_fiyat);
		 	strcpy(urun.aciklama,guncel_aciklama);
		 	
		 	fprintf(temp_dosya,"%s\t %s\t %s\t %s\t %s\n",urun.kod,urun.isim,urun.gram,urun.fiyat,urun.aciklama);
		 	
			enabled = 0;
		 	
		 	
		 }
	if(enabled == 0){
		fclose(dosya);
		fclose(temp_dosya);
		remove("stok.txt");
		rename("temp_stok.txt","stok.txt");
		printf("-----Stok basariyla guncellendi!-----\n\n\n\n");
		main();
		
	}else {
		printf("-----Kayit Bulunamadi!-----\n\n\n\n");
		guncelleme();
	}
	
   
}
}
void silme(){
	
	int giris;
	char sayi[20];
	
	dosya = fopen("stok.txt", "r+");
	temp_dosya = fopen("temp_stok.txt","a+");

	printf("Silmek istediginiz ürünün kodunu giriniz: ");
	scanf("%s", &sayi);
	
	 if(strcmp(urun.kod, sayi)){
	 	printf("\nHatali veya eksik tuslama yaptiniz.\n");
	 	silme();
	 } 
	 while(fscanf(dosya,"%s\t %s\t %s\t %s\t %s\n",urun.kod,urun.isim,urun.gram,urun.fiyat,urun.aciklama)!=EOF){
	 	if(strcmp(urun.kod, sayi)){
	 		fprintf(temp_dosya,"%s\t %s\t %s\t %s\t %s\n",urun.kod,urun.isim,urun.gram,urun.fiyat,urun.aciklama);
		 } else{
		 	continue;
		 }
	 }

 fclose(dosya);
 fclose(temp_dosya);
 remove("stok.txt");
 rename("temp_stok.txt","stok.txt");
 
    printf ("Stok silmeye devam et (1)\n");
    printf ("Ana menü (2)\n");
    scanf("%d",&giris);
    	
		if (giris==1){
		silme();
	} else {
		main();
	}
}
int main() {
    int giris;
    
	setlocale(LC_ALL, "Turkish");
	
	printf("\n--------ANA MENU--------\n");
	printf("Stok giris (1)\n");
	printf("Stok kontrol (2)\n");
	printf("Stok silme (3)\n");
	printf("Stok güncelleme (4)\n");
	printf("------------------------\n");
	scanf("%d",&giris);
	
	
	if (giris==1){
		ekle();
	} else if(giris==2){
		kontrol();
	}
     else if(giris==3){
     	silme();
	 } else {
	 	guncelleme();
	 }
}
