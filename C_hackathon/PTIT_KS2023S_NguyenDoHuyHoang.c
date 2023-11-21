#include<stdio.h>
#include<math.h>
#include<stdbool.h>
bool prime(int n){
	int i;
	if ( n < 2) {
		return false;
	} else 
	    if (n==2 || n==5 || n==7 || n==3 || n==11) {
	    	return true;
		} else 
		    if (n%2 == 0 || n%3 == 0 ) {
		    	return false;
			}
    i=-1;
    while (i < sqrt(n)) {
    	i += 6;
    	if ( n%i == 0 || n%(i+2) == 0) {
    		return false;
		}
	}
    return true;   	
}
bool odd(int n) {
	if (n%2 != 0) {
		return true;
	} else return false;
}
bool devide(int n) {
	if (n%5 == 0) {
		return true;
	} else return false;
}
int main() {
	int n,m,choice;
	int i,j,temp;
	int count,sum;
	int max,min;
	printf("nhap so hang ");
	scanf("%d", &n);
	printf("nhap so cot ");
	scanf("%d", &m);
	int a[n*n][m*m];
	int add_array[n];
	do {
		printf("************************MENU**************************\n");
		printf("1.nhap gia tri cua mang\n");
		printf("2.in ra mang theo ma tran\n");
		printf("3.tinh so luong cac phan tu le chia het cho 5\n");
		printf("4.in ra phan tu co gia tri lon nhat , nho nhat tren duong bien, cheo chinh , cheo phu\n");
		printf("5.sap xep giam dan theo dong\n");
		printf("6.tinh tong cac phan tu la so nguyen to trong mang\n");
		printf("7.sap xep duong cheo phu tang dan\n");
		printf("8.nhap mang 1 chieu, nhap chi so cot va chen vao mang 2 chieu\n");
		printf("9.thoat\n");
		printf("nhap lua chon cua ban \n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				for (i=0;i<n;i++) {
					for (j=0;j<m;j++) {
						printf("a[%d][%d]=",i,j);
						scanf("%d", &a[i][j]);
					}
				}
				break;
			case 2:
				for (i=0;i<n;i++) {
					for (j=0;j<m;j++) {
						printf("%d  ",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				break;
			case 3:
				count = 0;
				for (i=0;i<n;i++) {
					for (j=0;j<m;j++) {
						if (odd( a[i][j] ) && devide( a[i][j] )) 
							count++;
					}
				}
				printf("%d\n", count);
				break; 
		    case 4:
			    max = a[0][0];
			    min = a[0][0];
			    for (i=0;i<n;i++) {
			    	if (max < a[i][0]) max = a[i][0];
			    	if (min > a[i][0]) min = a[i][0];
				}
				printf("max va min tren duong bien trai lan luot la %d %d \n", max ,min);
				max = a[n-1][m-1];
			    min = a[n-1][m-1];
			    for (i=0;i<n;i++) {
			    	if (max < a[i][m-1]) max = a[i][m-1];
			    	if (min > a[i][m-1]) min = a[i][m-1];
				}
				printf("max va min tren duong bien phai lan luot la %d %d \n", max ,min);
				max = a[0][0];
			    min = a[0][0];
			    for (j=0;j<n;j++) {
			    	if (max < a[0][j]) max = a[0][j];
			    	if (min > a[0][j]) min = a[0][j];
				}
				printf("max va min tren duong bien tren lan luot la %d %d \n", max ,min);
				max = a[n-1][m-1];
			    min = a[n-1][m-1];
			    for (j=0;j<n;j++) {
			    	if (max < a[n-1][j]) max = a[n-1][j];
			    	if (min > a[n-1][j]) min = a[n-1][j];
				}
				printf("max va min tren duong bien duoi lan luot la %d %d \n", max ,min);
				if (m == n) {
					i = 1;
					j = 1;
					max = a[0][0];
					min = a[0][0];
					while (i<n) {
						if (max < a[i][j]) max = a[i][j];
			    		if (min > a[i][j]) min = a[i][j];
						i++;
						j++;
					}
					printf("max va min trong duong cheo chinh lan luot la %d %d \n",max ,min);
			    	i = 1;
			    	j = n-2;
			    	max = a[0][n-1];
			    	min = a[0][n-1];
						while (j>=0) {
							if (max < a[i][j]) max = a[i][j];
			    			if (min > a[i][j]) min = a[i][j];
							i++;
							j--;
						}
					printf("max va min trong duong cheo phu lan luot la %d %d \n",max ,min);
				} else printf("khong co duong cheo chinh va phu\n");
				break;
			case 5:
				for (i=0;i<n;i++) {
					for (j=0;j<m-1;j++) {
						for (int k = j+1;k<m;k++) {
							if (a[i][j] > a[i][k]) {
								temp = a[i][j];
								a[i][j] = a[i][k];
								a[i][k] = temp;
							}  
						}
					};
				}
				for (i=0;i<n;i++) {
					for (j=0;j<m;j++) {
						printf("%d  ", a[i][j]);
					}
					printf("\n");
				}
				break;
			case 6:
			    sum = 0;
				for (i=0;i<n;i++) {
					for (j=0;j<m;j++) {
						if (prime(a[i][j])) 
							sum += a[i][j]; 
					}
				}
				printf("tong cac phan tu la so nguyen to trong mang la %d \n",sum);
				break;
			case 7:
				if (m == n) {
					i = 1;
					j = n-2;
					while (j>=0) {
						temp = a[i][j];
						int run1 = i-1;
						int run2 = j+1;
						while ( run1 >=0 && a[run1][run2] < temp) {
							a[run1+1][run2-1] = a[run1][run2];
							run1--;
							run2++;
						}
						a[run1+1][run2-1] = temp;
						i++;
						j--;
					}
					for (i=0;i<n;i++) {
						for (j=0;j<m;j++) {
							printf("%d  ", a[i][j]);
						}
					printf("\n");
					}
				} else printf("khong co duong cheo phu\n");   
				break;
			case 8:
				printf("nhap mang 1 chieu can chen\n");
				for (i=0;i<n;i++) {
					printf("add_array[%d]=",i);
					scanf("%d",&add_array[i]);
				}
				int add_index;
				printf("nhap cot can chen ");
				scanf("%d",&add_index);
				if (add_index<m) {
					for (i=0;i<n;i++) {
						for (j=m+1;j>=add_index;j--) {
							a[i][j] = a[i][j-1];
							if (add_index == j) a[i][j] = add_array[i];
						}
					}
				for (i=0;i<n;i++) {
					for (j=0;j<m+1;j++) {
						printf("%d  ",a[i][j]);
					}
					printf("\n");
				}
				} else {
					for (i=0;i<n;i++) {
						for (j=add_index-1;j>=m;j--) {
							a[i][j] = 0;
							if (add_index-1 == j) a[i][j] = add_array[i];
						}
					}  
					for (i=0;i<n;i++) {
						for (j=0;j<add_index;j++) {
							printf("%d  ", a[i][j]);
						}
				    	printf("\n");
					}
			      }
				break;
			case 9:
				printf("thoat\n");
			default:
				printf("khong hop le\n");						
		}
	} while (choice != 9);
}
