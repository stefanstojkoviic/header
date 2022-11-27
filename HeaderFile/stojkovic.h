#include <stdio.h>
const int size =500;//Velicina matrice
//1D niz int
void unosNiz(int n,int a[]){//Unos 1d niza
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void ispisNiz(int n,int a[]){
	for(int i=0;i<n;i++){
		printf("a[%d]=%d\n",i,a[i]);
	}
}
//1D niz float
void unosNiz(float n,float a[]){
	for(int i=0;i<n;i++){
		scanf("%f",&a[i]);
	}
}
void ispisNiz(float n,float a[]){
	for(int i=0;i<n;i++){
		printf("a[%d]=%.2f\n",i,a[i]);
	}
}

//2D niz float
void unosMat(float r,float k,float b[][size]){//Unos matrice
	for(int i=0;i<r;i++)
		for(int j=0;j<k;j++){
			scanf("%f",&b[i][j]);
		}
}
void ispisMat(float r,float k,float b[][size]){
	for(int i=0;i<r;i++){
		for(int j=0;j<k;j++){
			printf("%5.2f",b[i][j]);
		}
		printf("\n");
	}	
}
//2D niz int
void unosMat(int r,int k,int b[][size]){//Unos matrice
	for(int i=0;i<r;i++)
		for(int j=0;j<k;j++){
			scanf("%d",&b[i][j]);
		}
}
void ispisMat(int r,int k,int b[][size]){
	for(int i=0;i<r;i++){
		for(int j=0;j<k;j++){
			printf("%5d",b[i][j]);
		}
		printf("\n");
	}	
}


//Operacije na 1D nizovima


//Sortiranja
//Celobrojna sortiranja
void izbor(int n,int a[]){
	int p;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			p= a[i];
			a[i]=a[j];
			a[j]=p;
		}
}
void umetanje(int n,int a[]){
	int p;
	for(int i=1;i<n;i++)
		for(int j=i-1;j>=0 && a[j]>a[i];j--){
			p=a[j];
			a[j]=a[j+1];
			a[j+1]=p;
		}
}
void umetanjeP(int n,int a[]){
	int p,j,i;
	for(i=1;i<n;i++){
		p=a[i];
		for(j=i-1;j>=0 && a[j]>p;j--)
			a[j+1]=a[j];
		a[j+1]=p;
	}
} 	
void zamenaSuseda(int n,int a[]){
	int dalje,i,j,p;
	for(dalje =1,i=0;i<n-1 && dalje;i++){
		for(dalje =0,j=n-1; j>i;j--){
			if(a[j-1]>a[j]){
				p=a[j-1];
				a[j-1]=a[j];
				a[j]=p;
				dalje =1;
			}
		}
	}
}
//Realna sortiranja
void izbor(float n,float a[]){
	float p;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			p= a[i];
			a[i]=a[j];
			a[j]=p;
		}
}
void umetanje(float n,float a[]){
	float p;
	for(int i=1;i<n;i++)
		for(int j=i-1;j>=0 && a[j]>a[i];j--){
			p=a[j];
			a[j]=a[j+1];
			a[j+1]=p;
		}
}
void umetanjeP(float n,float a[]){
	float p;
	int i,j;
	for(i=1;i<n;i++){
		p=a[i];
		for(j=i-1;j>=0 && a[j]>p;j--){
			a[j+1]=a[j];
		}
		a[j+1]=p;
	}
} 	
void zamenaSuseda(float n,float a[]){
	int dalje,i,j;
	float p;
	for(dalje =1,i=0;i<n-1 && dalje;i++){
		for(dalje =0,j=n-1; j>i;j--){
			if(a[j-1]>a[j]){
				p=a[j-1];
				a[j-1]=a[j];
				a[j]=p;
				dalje =1;
			}
		}
	}
}
//Pretrazivanje
int linearno(int n,int a[],int k){//Int
	int index =0;
	for(int i=0;i<n;i++){
		if(k==a[i]){
			index=i;
		}
	}
	return index;
}
float linearno(float n,float a[],float k){//Int
	int index =0;
	for(int i=0;i<n;i++){
		if(k==a[i]){
			index=i;
		}
	}
	return index;
}
int binarno(int n,int a[],int k){//int
	int index,poc,kraj,s;
	poc=0;
	index=-1;
	kraj=n-1;
	do{
		s=(poc+kraj)/2;
		if(a[s]==k){
			index=s;
		}
		else{
			if(a[s]<k)
				poc=s+1;
			else
				kraj=s-1;
		}
	}
	while(poc<=kraj && index<0);
}
float binarno(float n,float a[],float k){//float
	int index,poc,kraj,s;
	poc=0;
	index=-1;
	kraj=n-1;
	do{
		s=(poc+kraj)/2;
		if(a[s]==k){
			index=s;
		}
		else{
			if(a[s]<k)
				poc=s+1;
			else
				kraj=s-1;
		}
	}
	while(poc<=kraj && index<0);
	return index;
}
//Izbacivanje
void izbaci(int n,int a[],int x){
	int k=0;
	for(int i=0;i<n;i++){
		if(a[i]!=x)
			a[k++]=a[i];
	}
	n=k;
}
void izbaci(float n,float a[],float x){
	int k=0;
	for(int i=0;i<n;i++){
		if(a[i]!=x)
			a[k++]=a[i];
	}
	n=k;
}
//Prosirivanje
void prosiri(int n,int a[],int j,int x){
	for(int i=n;i>j-1;i--){
		a[i]=a[i-1];
	}
	a[j-1]=x;
}
void prosiri(int n,float a[],int j,float x){
	for(int i=n;i>j-1;i--){
		a[i]=a[i-1];
	}
	a[j-1]=x;
}
//Invertovanje
void invert(int n,int a[]){
	int i,j,b;
	for(i=0,j=n-1;i<j;i++,j--){
		b=a[i];
		a[i]=a[j];
		a[j]=b;
	}
}
void invert(float n,float a[]){
	int i,j;
	float b;
	for(i=0,j=n-1;i<j;i++,j--){
		b=a[i];
		a[i]=a[j];
		a[j]=b;
	}
}
//Rotiranje
void rotiranje(int n,int a[],int mesto){
	int temp;
	for(int i=0;i<mesto;i++){
		temp= a[0];
		for(int j=1;j<n;j++){
			a[j-1]=a[j];
		}
		a[n-1]=temp;
	}
}
void rotiranje(int n,float a[],int mesto){
	int temp;
	for(int i=0;i<mesto;i++){
		temp= a[0];
		for(int j=1;j<n;j++){
			a[j-1]=a[j];
		}
		a[n-1]=temp;
	}
}

//Operacije na 2D nizovima

//Zamena redova i kolona
void zamenaRiK(int n,int a[][size]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%5d",a[j][i]);
		}
		printf("\n");
	}
}
void zamenaRiK(float n,float a[][size]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%5.2f",a[j][i]);
		}
		printf("\n");
	}
}
//Diagonale
void glavna(int n,int a[][size],int b[]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				b[i]=a[i][j];
			}	
		}
	}
}
void glavna(float n,float a[][size],float b[]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				b[i]=a[i][j];
			}	
		}
	}
}
void sporedna(int n,int a[][size],int b[]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+j==n-1){
				b[i]=a[i][j];
			}	
		}
	}
}
void sporedna(float n,float a[][size],float b[]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+j==n-1){
				b[i]=a[i][j];
			}	
		}
	}
}

