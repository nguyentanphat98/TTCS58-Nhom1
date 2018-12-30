#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
string s,f,a,b;
int c;
void menu();
void chonmenu();
void nhap_chuoi();
void luufile(string s);
string  xoaKhoangTrang();
string  In_Hoa_Ki_Tu_Dau_Moi_Tu();
int dem();
void luudata();
int main()
{
  menu();
  chonmenu();	
  system("pause");;
}
void menu()
{   cout<<"\n\n";
	cout<<"\t\t 1 nhap vao 1 chuoi"<< endl;
	cout<<"\t\t 2 bo khoang trang thua"<< endl;
	cout<<"\t\t 3 chuoi hoa chuoi"<< endl;
	cout<<"\t\t 4 thong ke chuoi"<< endl;
	cout<<"\t\t 5 ghi ket qua"<< endl;
}
void chonmenu()
{
	int select;
	cout << "Lua chon cua ban: ";
	cin >> select;
	switch (select)
	{
		case 1:
			system("cls");
			nhap_chuoi();
			chonmenu();
			break;
		case 2:
			if(s == "") {
                system("cls");
                menu();
                cout << "\t\t\t\t  String is null!" << endl;
                chonmenu();
            }
            else
            {
			xoaKhoangTrang();
			chonmenu();
			}
			break;
		case 3:
			if(s == "") {
                system("cls");
                menu();
                cout << "\t\t\t\t  String is null!" << endl;
                chonmenu();
            }
            else
            {
			In_Hoa_Ki_Tu_Dau_Moi_Tu();
			chonmenu();
			}
			break;
		case 4:
			if(s == "") {
                system("cls");
                menu();
                cout << "\t\t\t\t  String is null!" << endl;
                chonmenu();
            }
            else
            {
			dem();
			chonmenu();
			}	
			break;
		case 5:
				if(s == "") {
                system("cls");
                menu();
                cout << "\t\t\t\t  String is null!" << endl;
                chonmenu();
            }
            else
            {
			luudata();
			chonmenu();
			}
			break;
		case 6:
            cout << "\t\t\t\t  Exited" << endl;
            break;
        default:
            system("cls");
            menu();
            cout << "\t\t\t\t  Wrong Option!" << endl;
            chonmenu();
	}
}
void nhap_chuoi()
{
	fflush(stdin);
	cout<<"\n nhap mot chuoi :";
	getline(cin, s);
	cout<< s <<endl;
	f=s;
	luufile(s);
}
void luufile(string s)
{
	ofstream myfile;
	myfile.open("input9.txt");
	myfile << s;
	myfile.close();
	cout<<"done"<<endl;
}
string xoaKhoangTrang()
{

	int i = 0;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ' '&& s[i + 1] == ' ')
		{
			for (int j = i;j < n;j++)
			{
				s[j] = s[j + 1];
			}
			n--;
			i--;
		}
	}
	// xoa dau, a[i]=a[i+1]
	i = 0;
	if (s[i] == ' ') s.erase(s.begin() + i);
	//xoa cuoi
	//n--
	i = n;
	if (s[i] == ' ') s.erase(s.begin() + i);
	cout << s << endl << "Da xoa cac khoang trang thua!!!"<<endl;
	a = s;
}
string In_Hoa_Ki_Tu_Dau_Moi_Tu()
{
	int n = s.length();
	for (int i = 0; i <= n; i++)
	{
		// kiem tra neu truoc phan tu la khoan trang và tiep theo chuoi thi viet hoa
		if (s[i] == ' ' && isalpha(s[i + 1]))
			s[i + 1] = toupper(s[i + 1]);
	}
	// kiem tra chuoi dau la so hoac chu thi viet hoa
	if (isalpha(s[0]) || isdigit(s[0]))
		s[0] = toupper(s[0]);
	cout << "Chuoi sau khi chuan hoa." << endl;
	cout << s << endl;
	b=s;
}
int  dem()
{
	int dem=0;
	int dodai = s.length();
	for (int i = 0; i < dodai; i++)
	{
		if (isalpha(s[i]))
			dem++;
	}
	cout <<"So ki tu: " << dem <<endl;
	c=dem;
}
void luudata()
{
	ofstream ghifile;
	ghifile.open("output9.txt");
	ghifile << f << endl;
	ghifile << a << endl;
	ghifile << b<<endl;
	ghifile << c <<endl;
	ghifile.close();
	cout << "Da xuat ra file!" << endl;
}
