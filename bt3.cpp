#include<stdio.h>
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int a[6];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);	
	} 
	int max = a[0];
	 for(int i=1; i<n; i++){
	 	if(a[i] > max){
	 		max = a[i]; 
		 } 
	 }
	 printf("So lon nhat: %d\n", max);
	 return 0; 
} 
