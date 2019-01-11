 #include<iostream> 
#include<cstring> 
#include<cstdlib> 
#include <fstream>
#include <bits/stdc++.h> 
using namespace std; 
string str;
void docfile()
{
  ifstream myfile1("input1.txt");
  if (myfile1.is_open())
  {
    while ( getline (myfile1,str))
    {
      cout << str << "\n";
    }
    myfile1.close();
  }
}
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
string longestRepeatedSubSeq(string str) 
{
	int n = str.length(); 
	int dp[n+1][n+1]; 
	for (int i=0; i<=n; i++) 
		for (int j=0; j<=n; j++) 
			dp[i][j] = 0; 
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) 
			if (str[i-1] == str[j-1] && i != j) 
				dp[i][j] = 1 + dp[i-1][j-1]; 
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
	string res = ""; 
	int i = n, j = n; 
	while (i > 0 && j > 0) 
	{ 
		if (dp[i][j] == dp[i-1][j-1] + 1) 
		{ 
		res = res + str[i-1]; 
		i--; 
		j--; 
		}
		else if (dp[i][j] == dp[i-1][j]) 
			i--; 
		else
			j--; 
	}  
	reverse(res.begin(), res.end()); 

	return res; 
} 
int findLongestRepeatingSubSeq(string str) 
{ 
    int n = str.length(); 
  
    // Create and initialize DP table 
    int dp[n+1][n+1]; 
    for (int i=0; i<=n; i++) 
        for (int j=0; j<=n; j++) 
            dp[i][j] = 0; 
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=n; j++) 
        { 
            // If characters match and indexes are  
            // not same 
            if (str[i-1] == str[j-1] && i != j) 
                dp[i][j] =  1 + dp[i-1][j-1];           
                       
            // If characters do not match 
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
        } 
    } 
    return dp[n][n]; 
}
// Driver Program 
int main() 
{ 
	docfile();
	cout <<"Chuoi tim duoc la: "<< longestRepeatedSubSeq(str)<<endl;
	cout <<"Chuoi lap lai dai nhat :" << findLongestRepeatingSubSeq(str); 
	return 0; 
} 

