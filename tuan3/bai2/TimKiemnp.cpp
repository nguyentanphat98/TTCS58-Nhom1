#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 20
FILE *x;
int n;
int a[MAX];
void docfile()
{
	x=fopen("D:/input13.txt","r");
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
int binarySearch(int a[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2; // Tuong duong (l+r)/2 nhung uu diem tránh tràn so khi l,r ln
    // Neu arr[mid] = x, tra ve chi so và k?t thúc.
    if (a[mid] == x)
      return mid;
    // Neu arr[mid] > x, thuc hien tìm kiem nua trái cua mang
    if (a[mid] > x)
      return binarySearch(a, l, mid - 1, x);
 
    // Neu arr[mid] < x, thuc hien tìm kiem nua phai cua mang
    return binarySearch(a, mid + 1, r, x);
  }
  // Neu không tìm th?y
  return -1;
}
int maximumSubArray(int a[])
{
    int currentSum=0, maxSum=0;
    for(int i=0;i<MAX;i++)
    {
        currentSum+=a[i];
        if(currentSum > maxSum)
        {
            maxSum = currentSum;
        }else if(currentSum < 0)
        {
            currentSum= 0;
        }
    }
    return maxSum;
}
int main()
{  
  docfile();
	//nhap(a, n);
	xuat(a, n);
	int x=-2;
  int result = binarySearch(a, 0, n - 1, x);
  if (result == -1)
    printf("\n%d xuat hien tai chi so %d", x, result);
  else
    printf("\n%d xuat hien tai chi so %d", x, result);
    int maxSum=maximumSubArray(a);
    printf("\n tong lon nhat cua day la = %d", maxSum);
	getch();
	return 0;
}
