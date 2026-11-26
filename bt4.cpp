#include<stdio.h>
int main(){
	int a, b; 
	 printf("Nhap a: ");
    scanf("%d", &a);
     printf("Nhap b: ");
    scanf("%d", &b);
	int x = a, y = b;
	while (y != 0){
		int r = x % y;
		x = y;
		y = r; 
	} 
	int ucln = x;
	 long long bcnn = (long long )a / ucln*b;
	 printf("UCLN = %d\n", ucln);
	 printf("BCNN = %lld\n", bcnn);
	 return 0; 
} 
