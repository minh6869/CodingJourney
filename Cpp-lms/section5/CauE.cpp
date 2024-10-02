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
void nhap(sinhvien *&p, int &n, int &cot1, int &cot2, int &cot3, int &cot4, int &diemmax)
{
    cout << "Nhap so sinh vien: ";
    cin >> n;
    p = new sinhvien[n];
    for(int i=0 ; i<n ; i++)
    {
    cout << "\t\tNhap thong tin sinh vien thu " << i+1 << ": " << endl << "Ma Sinh Vien: ";
    fflush(stdin);
    getline(cin,p[i].msv);
    if(p[i].msv.size() > cot1)
        cot1 = p[i].msv.size();

    cout << "Ho va Ten: ";
    getline(cin,p[i].hoten);
    if(p[i].hoten.size() > cot2)
        cot2 = p[i].hoten.size();

    cout << "Lop: ";
    getline(cin,p[i].lop);
    if(p[i].lop.size() > cot3)
        cot3 = p[i].lop.size();

    cout << "Diem: ";
    cin >> p[i].diem;
    if (p[i].diem > diemmax)
        diemmax = p[i].diem;
    }
}

void xuat(sinhvien *p, int n, int cot1, int cot2, int cot3, int cot4)
{
    cout << "\t\tDanh sach sinh vien da nhap la: " << endl;
    cout << left << setw(cot1+3) << "Ma Sinh Vien" << left << setw(cot2+3) << "Ho va Ten" << left << setw(cot3+3) << "Lop" << left << setw(cot4+3) << "Diem" << endl;
    for (int i=0 ; i<n ; i++)
        cout << left << setw(cot1+3) << p[i].msv << left << setw(cot2+3) << p[i].hoten << left << setw(cot3+3) << p[i].lop << left << setw(cot4+3) << p[i].diem << endl;
}

void danh_sach_sinh_vien_co_diem_max(sinhvien *p, int n, int cot1, int cot2, int cot3, int cot4,int diemmax)
{
    cout << "\t\tDanh sach sinh vien co diem cao nhat la: " << endl;
    for(int i=0 ; i<n ; i++)
    {
        if(p[i].diem == diemmax)
            cout << left << setw(cot1+3) << p[i].msv << left << setw(cot2+3) << p[i].hoten << left << setw(cot3+3) << p[i].lop << left << setw(cot4+3) << p[i].diem << endl;
    }
    
}

int main()
{
    int n,cot1 = 12, cot2 = 9, cot3 = 3, cot4 = 4, diemmax = 0;
    sinhvien *p;
    nhap(p,n,cot1,cot2,cot3,cot4,diemmax);
    xuat(p,n,cot1,cot2,cot3,cot4);
    danh_sach_sinh_vien_co_diem_max(p,n,cot1,cot2,cot3,cot4,diemmax);

    return 0;
}