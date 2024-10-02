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
// void xuat(sinhvien *p, int n, int cot1, int cot2, int cot3,  int cot4)
// {
//     cout << "Danh sach sinh vien da nhap la: " << endl;
//        cout << left << setw(cot1+3) << "Ma Sinh Vien" << left << setw(cot2+3) << "Ho va Ten" << left << setw(cot3+3) << "Lop" << left << setw(cot4 + 3) << "Diem" << endl;
//     for (int i=0 ; i<n ; i++)
//         cout << left << setw(cot1+3) << p[i].msv << left << setw(cot2+3) << p[i].hoten << left << setw(cot3 + 3) << p[i].lop << left << setw(cot4 + 3) << p[i].diem << endl;

// }

void danh_sach_sv_mot_lop_co_diem_lon_hon_5(sinhvien *p, int n, int cot1, int cot2, int cot3, int cot4)
{
    string lop;
    int dem = 0;
    int demdiem = 0;
    fflush(stdin);
    cout << "Nhap lop: ";
    getline(cin,lop);
    for (int i=0 ; i<n ; i++)
    {
        if(demdiem !=0 && lop == p[i].lop && p[i].diem > 5)
        {
            cout << left << setw(cot1+3) << p[i].msv << left << setw(cot2+3) << p[i].hoten << left << setw(cot3+3) << p[i].lop << left << setw(cot4+3) << p[i].diem << endl;
            continue;
        }
        if(lop == p[i].lop)
            dem++;

        if(lop == p[i].lop && p[i].diem > 5)
        {
            cout << "Danh sach sinh vien cua lop " << lop << " co diem lon hon 5 la: \n";
            cout << left << setw(cot1+3) << p[i].msv << left << setw(cot2+3) << p[i].hoten << left << setw(cot3+3) << p[i].lop << left << setw(cot4+3) << p[i].diem << endl;
            demdiem++;
        }
        if(dem == 0)
            cout << "Khong co du lieu sinh vien cua lop " << lop << endl;
        if(demdiem == 0)
            cout << "Trong lop " << lop << " khong co sinh vien nao duoc hon 5 diem\n";
    }
}

int main()
{
    int n, cot1 = 12, cot2 = 9, cot3 = 3, cot4 = 4;
    sinhvien *p;
    nhap(p,n,cot1,cot2,cot3,cot4);
    xuat(p,n,cot1,cot2,cot3,cot4);
    danh_sach_sv_mot_lop_co_diem_lon_hon_5(p,n,cot1,cot2,cot3,cot4);

}




