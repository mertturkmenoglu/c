/*29) klavyeden girilen pozitif iki tamsayinin 
bolunmesiyle elde edilen bolum ve kalani, 
bolme ve mod alma operatorleri olmadan 
hesaplayan program 
*/

#include <stdio.h>

int main(){

	int bolunen, bolen, bolum, kalan;

	printf("Bolunen sayiyi giriniz: ");
	scanf("%d", &bolunen);

	printf("\nBolen sayiyi giriniz: ");
	scanf("%d", &bolen);

	while(bolunen>0){
		bolunen -= bolen;
		bolum++;
	}
	if(bolunen != 0)
		bolum--;
	kalan= (bolen+bolunen)%bolen;

	printf("\nBolum: %d", bolum);
	printf("\nKalan: %d", kalan);

	return 0;
}
