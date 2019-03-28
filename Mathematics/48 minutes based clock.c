#include <stdio.h>
//#include <windows.h> // ONLY ON WINDOWS

int main(){
	
	int ss,dd,sn,saat;
	printf("Saat-Dakika-Saniye bilgilerini sirasiyla giriniz:\n");
	scanf("%d%d%d",&ss,&dd,&sn);
	saat=ss*2880+dd*60+sn;
	while(saat<86400){
		ss=saat/2880;
		dd=(saat-ss*2880)/60;
		sn=saat%60;
		printf("%d:%d:%d\n",ss,dd,sn);
		saat=saat+1;
		saat=saat%86400;
		//Sleep(1000);	// ONLY ON WINDOWS
	}	
	return 0;
}
