#include <iostream> 
#include<string> 
#include<stdlib.h>
#include<fstream> 
#include<vector> 
#include <bits/stdc++.h> 
using namespace std; 
ifstream f("D:/Downloads/sinhvien.txt"); 
ofstream g("D:/Downloads/output.txt" , ios::app);
class NhanVien {
  int msnv;   
  string hoten; 
  int namsinh; 
  int ngay;
public:   
  void Nhap();
  void Xuat();  
  int tinhtien();
  friend class DSNV;
};
class DSNV {  
  int n; 
  vector<NhanVien> ds; 
  public: 
 	void NhapDS();
	void XuatDS();
	void Sort();
	int timkiem();
	int them();
	int xoa();
	int capnhapthongtin();
	void ghifile();
};
void NhanVien::Nhap(){ 
    string  s;         
    getline(f, s); msnv =atoi(s.c_str());
    getline(f, s); hoten = s; 
    getline(f, s); namsinh = atoi(s.c_str()); //chuyen chuoi thanh so nguyen
    getline(f, s); ngay = atoi(s.c_str());
  } 
void NhanVien::Xuat() { 
    cout << msnv <<"\t"<< hoten <<"\t"<< namsinh <<"\t\t"<< ngay <<"\t\t"<< tinhtien()<<endl;     
}
int NhanVien::tinhtien()
{
	return float(ngay*300000);
}
void DSNV::NhapDS() {  
	if (f.fail())    
		cout << "Failed to open this file!" << endl;   
	else {       
		string s;    
		getline(f, s); n = atoi(s.c_str());   //doc so n tu file  
		ds.resize(n); cout << n << endl;     
		for (int i = 0; i < n; i++) 
		     ds[i].Nhap();    
	}   
	f.close();          
}  
//void HoanVi(string &a, string &b)
//{
//	string temp = a;
//	a = b;
//	b = temp;
//}
//void HoanVi(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
void DSNV::Sort()
{
	int n = ds.size();
	for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				if(ds[i].ngay > ds[j].ngay)
				{
				 swap( ds[i], ds[j]);
				}
			}
		}
}
int DSNV::timkiem(){
	int maso;
	cout<<"\nnhap ma so nhan vien can tim : ";
	cin>>maso;
	int dem=0;
	int n = ds.size();
	for(int i = 0; i < n; i++)
	{
		if(ds[i].msnv==maso)
		{
			ds[i].Xuat();
			dem++;
		}
	}
	if(dem==0) cout<<"Khong co nhan vien can tim"<<endl;
}
int DSNV::them(){
			int x,g=0;
			cout<<"Nhap so luong nhan vien can them : ";
			cin>>x;
			int n=ds.size();
		 	int a=n;// cap nhap lai bo nho cho ve
			ds.resize(n+x);// thiet lap lai do dai cua vec to (n + x);doituong
			n=ds.size();
			for(int i=n-1;i>=a;i--)
			{
				cout<<"Nhap Ma Nhan Vien : ";
				cin>>ds[i].msnv;
			do{
				if(ds[i].msnv==ds[g].msnv)
				{
				cout<<"nhap lai : ";
				cin>>ds[i].msnv;
				g=0;
				}else g++;
			}while(g<a);
			fflush(stdin);
			cout<<"Nhap Ho va Ten : "; 
			getline(cin,ds[i].hoten);
			cout<<"Nhap Nam sinh Nhan Vien : ";
			cin>>ds[i].namsinh;
			cout<<"Nhap ngay lam Nhan Vien : ";
			cin>>ds[i].ngay;
			}	
}
int DSNV::xoa(){
			int n = ds.size();
			int x;
			cout<<"nhap ma nhan vien can xoa : ";
			cin>>x;
			for(int i=0;i<n;i++)
			{
				if(ds[i].msnv==x) 
				ds.erase(ds.begin()+i);
			}
}
int DSNV::capnhapthongtin()
{
		    int n = ds.size();
		    int masocapnhap;
			cout<<"Nhap ma nhan vien can cap nhat : ";cin>>masocapnhap;
			for(int i=0;i<n;i++)
			{
				if(ds[i].msnv==masocapnhap) 
				{
					int k;
					cout<<"Nhap so de thuc hien cap nhat voi so : \n1.Thay doi ten nhan vien \n2.Thay doi nam sinh nhan vien \n3.Thay doi ngay cong nhan vien \n4.Ket thuc\n";
					cin>>k ;
					while(k==1||k==2||k==3)
					{
						if(k==1)
						{
							fflush(stdin);
							cout<<"nhap lai ten nhan vien : ";
							getline(cin,ds[i].hoten);
							cout<<"ban can cap nhat gi them ? chon so : \n1.Thay doi ten nhan vien \n2.Thay doi nam sinh nhan vien \n3.Thay doi ngay cong nhan vien \n4.Ket thuc\n";
							cin>>k;
						}else
						if(k==2)
						{
							cout<<"nhap lai tuoi nhan vien : ";
							cin>>ds[i].namsinh;
							cout<<"ban can cap nhat gi them ? chon so : \n1.Thay doi ten nhan vien \n2.Thay doi tuoi nhan vien \n3.Thay doi luong nhan vien \n4.Ket thuc\n";
							cin>>k;
						}else
						if(k==3)
						{
							cout<<"nhap lai luong nhan vien : ";
							cin>>ds[i].ngay;
							cout<<"ban can cap nhat gi them ? chon so : \n1.Thay doi ten nhan vien \n2.Thay doi tuoi nhan vien \n3.Thay doi luong nhan vien \n4.Ket thuc\n";
							cin>>k;
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				ds[i].Xuat();
			}
			
}
void DSNV::XuatDS() { 
    cout << "MSNV:         " << "   hoten     " << "    nam sinh   "<< "    ngay       "<< "tien luong(vnd) " <<endl; 
	n = ds.size() ;
	for (int i = 0; i < n; i++) 
	    ds[i].Xuat();   
}
void DSNV::ghifile()
{
			//xoa toan bo du lieu trong file va ghi lai tu dau
			ofstream k("D:/Downloads/output1.txt");
			int n;
			n = ds.size();
			k<<n<<endl;
			for(int i=0;i<n;i++)
			{
				k<<ds[i].msnv<<endl;
				k<<ds[i].hoten<<endl;
				k<<ds[i].namsinh<<endl;
				k<<ds[i].ngay<<endl;	
				k<<ds[i].ngay*300000 << endl;
			}
}
int main(){
	//NhanVien nv;
  	DSNV ds;
  	int k;
	ds.NhapDS();
	cout<<endl;
	cout<<"			 			1. Add Record"<<endl;
	cout<<"			 			2. List Record"<<endl;
	cout<<"			 			3. Modify Record"<<endl;
	cout<<"			 			4. Delete Record"<<endl;
	cout<<"			 			5. Exit"<<endl;
	cout<<"			 			Your Choice : ";cin>>k;
	
	while(k==1||k==2||k==3||k==4||k==5)
	{
		if(k==1)
		{
			ds.them();
			ds.ghifile();
			system("cls");
		}else
		if(k==2)
		{
			system("cls");
			ds.XuatDS();
		}else
		if(k==3)
		{
			ds.capnhapthongtin();
			ds.XuatDS();
			ds.ghifile();
			system("cls");
		}else
		if(k==4)
		{
			ds.xoa();
			ds.ghifile();
			system("cls");
		}
		if(k==5)
		{
			ds.Sort();
		  ds.XuatDS();
			}
		cout<<endl;
		cout<<"						Another choice ?"<<endl;
		cout<<endl;
		cout<<"			 			1. Add Record"<<endl;
		cout<<"			 			2. List Record"<<endl;
		cout<<"			 			3. Modify Record"<<endl;
		cout<<"			 			4. Delete Record"<<endl;
		cout<<"			 	  		5. sort Record"<<endl;
		cout<<"			 			6. Exit"<<endl;
		cout<<"			 			Your Choice : ";cin>>k;
	}	
	system("pause");
}
