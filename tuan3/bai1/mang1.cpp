#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 20
FILE *x;
int n;
int a[MAX];
void docfile()
{
	x=fopen("D:/mm.txt","r");
	if(!x)
	{
		 printf("\n file khong ton tai");
		 getch();
	}
	fscanf(x,"%d",&n);
	for(int i=0;i < n;i++)
	{		
		fscanf(x,"%d",&a[i]);
	}
	fclose(x);
}
void xuat(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%3d", a[i]);
	}
}
bool TimKiem(int a[], int n, int y)
{
	for(int i = 0; i < n; i++)
	{
		// Liên t?c ki?m tra.
		if(a[i] == y)
		{
			return true; // Tìm thay x.
		}
	}
	return false; 
}
void HoanVi(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SapXepTangDan(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}

/*
Cho chqy tu cu v? d?u, neu thay so nào lon hon x thì cho nó dich ve sau 1 vi trí.
*/
void ChenXVaoMangTang(int a[], int &n, int x)
{
	int i, j;
	
	for(i = 0; i < n; i++)
	{
		
			if(x < a[i] )
			{
				int temp = x;
				for(j = n; j > i; j--)
				{
					// lun sau 1 phan tu
					a[j] = a[j - 1];
				}
				a[i] = temp;
				break;
			}
	}
	n++;
}
// ham dich chuyen phan tu x len 1 vi tri .
void Xoa1PhanTu(int a[], int &n, int ViTriXoa)
{
	for(int i = ViTriXoa; i < n; i++)
	{
		//dich chuyen tu sau len truoc 
		a[i] = a[i + 1];
	}
	n--;
}
void XoaCacPhanTuTrungVoiX(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if((a[i]) == x)
		{
			Xoa1PhanTu(a, n, i);
			i--;
		}
	}
}
void XoaCacPhanTuTrungNhau(int a[], int &n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] == a[j])
			{
				Xoa1PhanTu(a, n, j);
				j--;
			}
		}
	}
}
int main()
{
//	nhap(a, n);
  	docfile();
	xuat(a, n);
	int y;
	printf("\n nhap so can tim kiem : ");
	scanf("%d",&y);
	bool Check = TimKiem(a,n,y); // G?i l?i hàm tìm ki?m.
	// Ki?m tra - so sánh k?t qu?.
	if(Check == true)
	{
	    printf("phan tu ton tai trong mang");
	}
	else
	{
		printf("phan tu khong ton tai ");
	}
	int ViTriXoa,x;
	printf("\nNhap x: ");
	scanf("%d", &x);
	SapXepTangDan(a, n);
	int PhanTuThem;
	printf("\nNhap vao phan tu can them: ");
	scanf("%d", &PhanTuThem);
	ChenXVaoMangTang(a, n, PhanTuThem);
	printf("\nMang sau khi them:\n");
	xuat(a, n);
	// xoa vi tri x;
	XoaCacPhanTuTrungVoiX(a, n, x);
	printf("\nMang sau khi xoa tat cac cac gia tri trung voi %d: ", x);
	xuat(a, n);
	// xoa trung
	XoaCacPhanTuTrungNhau(a, n);
	printf("\nMang sau khi xoa tat cac cac gia tri trung nhau: ");
	xuat(a, n);
	getch();
	return 0;
}
