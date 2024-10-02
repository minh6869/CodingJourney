#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct sinhvien
{
    string msv;
    string hoten;
    string lop;
    int diem;

};

sinhvien *nhap(sinhvien *p, int &n, int &cot1, int &cot2, int &cot3, int &cot4)
{
    cout << "Nhap so sinh vien: ";
    cin >> n;
    p = new sinhvien[n];
    for( int i=0; i<n ; i++)
    {   
        cout  << "\t\t\t\tNhap thong tin sinh vien thu " << i+1 << ": \n";
        cout << "Ma sinh vien: ";
        fflush(stdin);
        getline(cin,p[i].msv);
        if(p[i].msv.size() > cot1)
            cot1 = p[i].msv.size();
        cout << "Ho va ten: ";
        getline(cin,p[i].hoten);
        if(p[i].hoten.size() > cot2)
            cot2 = p[i].hoten.size();
        cout << "Lop: ";
        getline(cin,p[i].lop);
        if(p[i].lop.size() > cot3)
            cot3 = p[i].lop.size();
        cout << "Diem: ";
        cin >> p[i].diem;
    }
    return p;
}

void xuat(sinhvien *p, int n, int &cot1, int &cot2, int &cot3, int &cot4)
{
    cout << "Danh sach sinh vien la: " << endl;
    cout <<  left << setw(cot1+3)   <<  "Ma sinh vien" << left << setw(cot2+3)  << "Ho va Ten" << left << setw(cot3+3)  << "Lop" << left << setw(cot4+3)  << "Diem" << endl;
    for( int i=0 ; i<n ; i++)
        cout << left << setw(cot1+3)   << p[i].msv << left << setw(cot2+3)  << p[i].hoten << left << setw(cot3+3)  << p[i].lop << left << setw(cot4+3)  << p[i].diem << endl;
    
}

int main()
{
    int n,cot1 = 12, cot2 = 9, cot3 = 3, cot4 = 4;
    sinhvien *p;
    p = nhap(p,n,cot1,cot2,cot3,cot4);
    xuat(p,n,cot1,cot2,cot3,cot4);
    return 0;




// Ma Sinh Vien               Ho va Ten               Lop     Diem
//      1         nghieng nghieng nghieng nghieng   64cntt1    2
//      2                  hoang hoa tham           64cntt1    3
//      3                    luu ly                 64cntt1    9
}