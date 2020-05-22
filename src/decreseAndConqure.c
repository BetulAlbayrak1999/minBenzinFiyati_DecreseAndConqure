/*
 Proje odevi: decrese and conqure
*/

#include <stdio.h>
#include <stdlib.h>

#define k 50//arac en az k km kadar gider
#define f 100//arac bir depo benzin ile max f km kadar gidebiliyor
#define yol 1500//menzile olan toplam yol
int main(void) {
    int istasyonSayisi = 5;
	struct benzin{
		int m; //artan uzaklikta benzin istasyonu
		int p; //benzin istasyondaki bir depo benzinin ucrteti
	}istasyon[5];

	int globalFiyat = 0;
    //degerleri belirleme
	istasyon[0].m = 0;
	istasyon[0].p = 3;
    istasyon[1].m = 30;
   	istasyon[1].p = 5;
    istasyon[2].m = 70;
   	istasyon[2].p = 4;
    istasyon[3].m = 130;
    istasyon[3].p = 3;
    istasyon[4].m = 180;
   	istasyon[4].p = 6;



   	int i = 0, j = 0, localFiyat, benzinAlindi = 0, count = 0;
   	while(i < istasyonSayisi){
   		while(istasyon[i].m - benzinAlindi < k)//eger alindigi istasyondan arasinda 50 dan az km varsa gec
   			i++;

   		if(istasyon[i].m - benzinAlindi >= f){
   			j = i - 1;
   	   		if(istasyon[j].m > benzinAlindi){
   	   		    localFiyat = istasyon[j].p;
   	   			while(istasyon[j - 1].m - benzinAlindi >= k && localFiyat > istasyon[j-1].p){
   	   			    localFiyat = istasyon[j-1].p;
   	   				benzinAlindi = istasyon[j-1].m;
   	   				j--;
   	   				count++;
   	   			}
   	   			if(count == 0){
   	   				benzinAlindi = istasyon[j].m;
   	   			}
   	   			count = 0;
   	   		    globalFiyat = globalFiyat + localFiyat;
   	   		}
   		}
   		i++;
   	}

   	printf("gereken en az benzin ucreti: %d", globalFiyat);
   	return 0;
}
