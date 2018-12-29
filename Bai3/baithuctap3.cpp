#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
 
 using namespace std;
 
 struct NhanVien{
 	int MaNhanVien;
 	string HoLot;
 	string Ten;
 	int Luong;
 }
 NVFind, NVMax;
 
 class DSNhanVien{
 	private:
 		int n;
 	public:
 	vector<NhanVien> ds;
 	void NhapDS();
 	void XuatDS();
 	NhanVien TimNV();
    NhanVien LuongMax();
 	void SapXep();
 };
 
 int chon;
 DSNhanVien DSNV;
 int TroVe;
 
void ShowMenu();
void LuaChon();
void NhapDS();
void XuatDS();
void LuuVaoFile(DSNhanVien DSNV);
void SapXep();
void LuuKQFile(NhanVien NVFind, NhanVien NVMax, DSNhanVien DSNV);
bool TroVeMenu();

int main() {
    ShowMenu();
    LuaChon();
}

 void ShowMenu(){
 	cout<< "1.nhap ma nhan vien"<< endl;
 	cout<< "2.tim nhan vien"<< endl;
 	cout<< "3.nhan vien co luong cao nhat va thap nhat"<< endl;
 	cout<< "4.xap sep nhan vien"<< endl;
 	cout<< "5. luu ket qua"<< endl;
 	cout<< "6.exit "<<endl;
 }
 
 void LuaChon(){
 	cout<< "hay nhan chon yeu cau"<< endl;
 	cin>> chon;
 	switch(chon){
 		case 1:
 			system("cls");
 			DSNV.NhapDS();
 			 LuuVaoFile(DSNV);
 			 if(TroVeMenu())
			   {
                system("cls");
                ShowMenu();
                LuaChon();
            	}
			else
			   {
           	    cout << "Exited" << endl;
       			}
            break;
 		case 2:
            system("cls");
            NVFind = DSNV.TimNV();
            if(NVFind.MaNhanVien) {
                cout << "======================" << endl;
                cout << "\nma nhan vien: " << NVFind.MaNhanVien;
                cout << "\nHo Lot    : " << NVFind.HoLot << endl;
                cout << "\nTen       : " << NVFind.Ten << endl;
                cout << "\nLuong     : " << NVFind.Luong << endl;
                cout << "======================" << endl;
            } else {
                cout << "======================" << endl;
                cout << "ko tim thay" << endl;
            }
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 3:
            system("cls");
            NVMax = DSNV.LuongMax();
            if(NVMax.MaNhanVien) {
                // block empty list
                cout << "======================" << endl;
                cout << "Ma Nhan Vien: " << NVMax.MaNhanVien;
                cout << "\nHo Lot	 : " << NVMax.HoLot << endl;
                cout << "\nTen       : " << NVMax.Ten << endl;
                cout << "\nLuong     : " << NVMax.Luong << endl;
                cout << "======================" << endl;
            } else {
                cout << "======================" << endl;
                cout << "ko tim thay" << endl;
            }
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 4:
            	system("cls");
            	DSNV.SapXep();
            cout << "sau khi sap xep" << endl;
            DSNV.XuatDS();
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 5:
            LuuKQFile(NVFind, NVMax, DSNV);
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 6:
            	cout << "\t\t\t\t  Exited" << endl;
            	break;
	 }
 }
 
 void DSNhanVien::NhapDS(){
 	cout<< "nhap so luong nhan vien:  "; cin>>n;
 	ds.resize(n);
 	for(int i = 0; i < n; i++){
 		cout<< "--------------------"<< endl;
 		fflush(stdin);
 		cout<< "nhap ma nhan vien: ";
		 fflush(stdin); cin>>ds[i].MaNhanVien;
 		cout<< "nhap ho Lot: ";
		 fflush(stdin); getline(cin, ds[i].HoLot);
 		cout<< "nhap ten nhan vien: "; 
		 fflush(stdin); getline(cin, ds[i].Ten);
		cout<< "nhap luong nhan vien: "; 
		 cin>> ds[i].Luong; 
	 }
 }
 
 void DSNhanVien::XuatDS(){
 	for(int i=0; i < n; i++)
	 {	cout<<"------nhan vien thu: "<< i;
 		cout<<"\n "<< ds[i].MaNhanVien;
 		cout<<"\n "<< ds[i].HoLot;
 		cout<<"\n "<< ds[i].Ten;
 		cout<<"\n "<< ds[i].Luong<< endl;
 	}
 }
 
 NhanVien DSNhanVien::TimNV() {
    int MaNhanVien;
    cout << "Nhap ma nv can find: > "; cin >> MaNhanVien;

    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(ds[i].MaNhanVien == MaNhanVien) {
            return ds[i];
        }
    }
    return NVFind;
}

NhanVien DSNhanVien::LuongMax(){
    if(ds.size()) {
        int Max = ds[0].Luong;
        int key = 0;
        for(int i = 1; i < n; i++) {
            if(ds[i].Luong > Max) {
                Max = ds[i].Luong;
                key = i;
            }
        }
        return ds[key];
    } else {
        return NVMax;
    } 
} 

void DSNhanVien::SapXep() {
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) {
            if(ds[i].Ten.compare(ds[j].Ten) > 0) {
                NhanVien tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }
}

void LuuVaoFile(DSNhanVien DSNV) {
    ofstream fileDSNV;
    fileDSNV.open("dsnv.txt");
    int len = DSNV.ds.size();
    for(int i = 0; i < len; i++) {
        fileDSNV << "======================" << endl;
        fileDSNV << "MaNhanVien: " << DSNV.ds[i].MaNhanVien << endl;
        fileDSNV << "Ho Ten: " << DSNV.ds[i].HoLot << endl;
        fileDSNV << "Ten: " << DSNV.ds[i].Ten << endl;
        fileDSNV << "Luong: " << DSNV.ds[i].Luong << endl;
    }
    fileDSNV.close();
    cout << "\nWrited to dsnv.txt\n\n";
}

void LuuKQFile(NhanVien NVFind, NhanVien NVMax, DSNhanVien DSNV) {
    fstream file;
    file.open("output3.txt", ios::app);

    file << "Find employees result: " << endl;
    if(NVFind.MaNhanVien) {
        file << "Employee code: " << NVFind.MaNhanVien;
        file << "\nFirst name: " << NVFind.Ten << endl;
        file << "\nLast name: " << NVFind.HoLot << endl;
        file << "\nSalary: " << NVFind.Luong << endl;
        file << "======================" << endl;
    } else {
        file << "Not found\n\n";
    }

    file << "Max of salary result: " << endl;
    if(NVMax.MaNhanVien) {
        // block empty list
        file << "Employee code: " << NVMax.MaNhanVien;
        file << "\nFirst name: " << NVMax.Ten << endl;
        file << "\nLast name: " << NVMax.HoLot << endl;
        file << "\nSalary: " << NVMax.Luong << endl;
        file << "======================" << endl;
    } else {
        file << "Employees is empty\n\n";
    }
    file << "Employees after sorted: " << endl;
    int tmp = DSNV.ds.size();
    if(tmp) {
        for(int i = 0; i < tmp; i++) {
            file << "======================" << endl;
            file << "Employee code: " << DSNV.ds[i].MaNhanVien;
            file << "\nFirst name: " << DSNV.ds[i].Ten << endl;
            file << "\nLast name: " << DSNV.ds[i].HoLot << endl;
            file << "\nSalary: " << DSNV.ds[i].Luong << endl;
        }
    } else {
        file << "Employees is empty\n\n";
    }

    file.close();
    cout << "\nWrited to output1.txt\n\n";
}

bool TroVeMenu() {
    cout << "Enter 1 de tro ve menu:> "; cin >> TroVe;

    if(TroVe == 1) {
        return true;
    } return false;
}
