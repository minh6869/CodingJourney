#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

struct sinhvien
{
    string msv;
    string hoten;
    string lop;
    int diem;
};

void nhap(sinhvien *&p, int &n, int &cot1, int &cot2, int &cot3, int &cot4)
{

    cout << "Nhap so sinh vien: ";
    cin >> n;
    p = new sinhvien[n];
    for(int i=0 ; i<n ; i++)
    {
        cout << "Nhap thong tin sinh vien thu "<< i+1 << endl;
        cout << "Ma sinh vien: ";
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
        fflush(stdin);
    }
}
void xuat(sinhvien *p, int n, int cot1, int cot2, int cot3, int cot4)
{
    cout << "Danh sach sinh vien da nhap la: \n";
    cout << left << setw(cot1+3) << "Ma Sinh Vien" << left << setw(cot2 + 3) << "Ho va Ten" << left << setw(cot3+3) << "Lop" << left << setw(cot4+3) << "Diem" << endl;
    for (int i=0 ; i<n ; i++)
        cout << left << setw(cot1+3) << p[i].msv << left << setw(cot2+3) << p[i].hoten << left << setw(cot3+3) << p[i].lop << left << setw(cot4+3) << p[i].diem << endl;
}

void add_sinh_vien(sinhvien *&p, int &n, int &cot1, int &cot2, int &cot3, int &cot4)
{
    int k;
    cout << "Nhap vi tri k: ";
    cin >> k;
    sinhvien *tmp;
    tmp = new sinhvien[1];
    cout << "Nhap thong tin sinh vien moi:" << endl;
    cout << "Ma sinh vien: ";
    fflush(stdin);
    getline(cin,tmp[0].msv);
    if(tmp[0].msv.size() > cot1)
        cot1 = tmp[0].msv.size();

    cout << "Ho va Ten: ";
    getline(cin,tmp[0].hoten);
    if( tmp[0].hoten.size() > cot2)
        cot2 = tmp[0].hoten.size();
    
    cout << "Lop: ";
    getline(cin,tmp[0].lop);
    if(tmp[0].lop.size() > cot3)
        cot3 = tmp[0].lop.size();
    cout << "Diem: ";
    cin >> tmp[0].diem;
    
    sinhvien *new_p = new sinhvien[n + 1];
    for(int i=0 ; i<k ; i++)
        new_p[i] = p[i];
    new_p[k] = tmp[0];
    for(int i=k ; i<n ; i++)
        new_p[i+1] = p[i];
    
    delete[] p;
    p = new_p;
    n++;
     xuat(p,n,cot1,cot2,cot3,cot4);
}


int main()
{
    int n, cot1 = 12, cot2 = 9, cot3 = 3, cot4 = 4;
    sinhvien *p;
    nhap(p,n,cot1,cot2,cot3,cot4);
    xuat(p,n,cot1,cot2,cot3,cot4);
    add_sinh_vien(p,n,cot1,cot2,cot3,cot4);
    // xuat(p,n,cot1,cot2,cot3,cot4);
    

}