#include<stdio.h>
#include<conio.h>

FILE *x;
FILE *y;
int n;// so vat 
int w[100];
int dem=0;
int b[100];// gia tri cua vat
int pmax;// trong luong toi da
void docfile()
{
	int i,j;
	x=fopen("input4.txt","r");
	fscanf(x,"%d",&n);
	fscanf(x,"%d",&pmax);
	for(i=1;i<=n;i++)
	{		
		fscanf(x,"%d",&w[i]);
	}
	fclose(x);
}
void inketqua()
{
	int s=0;
	int j;
	for(j=1;j<=n;j++)
	{
		s=s+b[j]*w[j];	
	}
	// neu bang trong luong cua cai  p thi in ra 
	if(s==pmax)
	{ 	
	
		for(j=1;j<=n;j++)
	{
		fprintf(y,"%d ",b[j]);
		// xuat ra gia tri
	}
	fprintf(y,"\n----\n");
	}
}
void inkqdem()
{
	int s=0;
	int j;
	for(j=1;j<=n;j++)
	{
		s=s+b[j]*w[j];	
	}
	if(s==pmax)
	{ 	
		dem++;
	}
}
void quaylui(int i)
{
	int j;
	for(j=0;j<=1;j++)
	{
		b[i]=j;
		if(i<n) {
		quaylui(i+1);
		}
		else
		 inketqua();
	}
}
void quayluidem(int i)
{
	int j;
	for(j=0;j<=1;j++)
	{
		b[i]=j;
		if(i<n) {
		quayluidem(i+1);
		}
		else
		 inkqdem();
	}
}
void ghifile()
{
	y = fopen("output7.txt","w");
	quayluidem(1);
	if(dem==0)
	{
		fprintf(y,"khong chon duoc");
	}else 
	fprintf(y,"%d\n",dem);
	// thu lan thu 1 ;
	quaylui(1);	
}
int main()
{
	docfile();
	ghifile();
	getch();
}
