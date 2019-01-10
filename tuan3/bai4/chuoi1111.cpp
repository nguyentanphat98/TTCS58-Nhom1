#include<iostream> 
#include<cstring> 
#include<cstdlib> 
#include <fstream>
#include <string>
using namespace std; 
int max(int a, int b);
string X;
string Y;
void docfile()
{
  ifstream myfile1("input1.txt");
  ifstream myfile2("input2.txt");
  if (myfile1.is_open())
  {
    while ( getline (myfile1,X))
    {
      cout << X << "\n";
    }
    myfile1.close();
  }
   if (myfile2.is_open())
  {
    while ( getline (myfile2,Y) )
    {
      cout << Y << "\n";
    }
    myfile2.close();
  }
}
int Lcs( string X, string Y, int m, int n ) 
{ 
   if (m == 0 || n == 0) 
     return 0; 
   if (X[m-1] == Y[n-1]) 
     return 1 + Lcs(X, Y, m-1, n-1); 
   else
     return max(Lcs(X, Y, m, n-1), Lcs(X, Y, m-1, n)); 
} 

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
}
void lcs( string X, string Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
   for (int i=0; i<=m; i++) 
   { 
     for (int j=0; j<=n; j++) 
     { 
     // luu tat ca phan tu dau bang 0 de cong tru cac duong cheo
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (X[i-1] == Y[j-1]) 
       // neu phan tu chung thi =1;// cheo +1
         L[i][j] = L[i-1][j-1] + 1; 
       else
       // 
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
   int index = L[m][n];  
   char lcs[index+1]; 
   lcs[index] =' '; 
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      if (X[i-1] == Y[j-1]) 
      { 
          lcs[index-1] = X[i-1]; 
          i--; j--; index--;
      } 
      else if (L[i-1][j] > L[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   // Print the lcs 
   cout << "LCS of " << X << " va " << Y << " la " << lcs<<endl;
} 
int main() 
{ 	 
  docfile();
  int m = X.length();
  int n = Y.length();
  int t = Lcs(X,Y,m,n); 
  cout<<"\nchieu dai lon nhat : "<<t;
  lcs(X, Y, m, n); 
  return 0; 
} 
