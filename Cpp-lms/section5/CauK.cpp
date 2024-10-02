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
void nhap(sinhvien *&p, int &n, int &cot1, int &cot2, int &cot3, int &cot4)
{
    cout << "Nhap so sinh vien: ";
    cin >> n;
    p = new sinhvien[n];
    for (int i=0 ; i<n ; i++)
    {
        cout << "\t\tNhap thong tin sinh vien thu " << i+1 << ": " << endl << "Ma Sinh Vien: ";
        fflush(stdin);
        getline(cin,p[i].msv);
        if(p[i].msv.size() > cot1)
            cot1 = p[i].msv.size();

        cout << "Ho va Ten: ";
        getline(cin, p[i].hoten);
        if( p[i].hoten.size() > cot2)
            cot2 = p[i].hoten.size();
        
        cout << "Lop: ";
        getline(cin,p[i].lop);
        if( p[i].lop.size() > cot3) 
            cot3 = p[i].lop.size();

        cout << "Diem: ";
        cin >> p[i].diem;
    }
}
void xuat(sinhvien *p, int n, int cot1, int cot2, int cot3, int cot4)
{
    cout << "\t\tDanh sach sinh vien da nhap la: " << endl;
    cout << left << setw(cot1+3) << "Ma Sinh Vien" << left << setw(cot2+3) << "Ho va Ten" << left << setw(cot3+3) << "Lop" << left << setw(cot4+3) << "Diem" << endl;
    for(int i=0 ; i<n ; i++)
        cout << left << setw(cot1+3) << p[i].msv << left << setw(cot2+3) << p[i].hoten << left << setw(cot3+3) << p[i].lop << left << setw(cot4+3) << p[i].diem << endl;
}

void sort(sinhvien *&p, int n, int cot1,int cot2, int cot3, int cot4)
{
    
    for(int i=0 ; i<n-1 ; i++)
    {
        int max = p[i].diem;
        int index = i;
        for (int j=i+1 ; j<n ; j++)
        {
            if(p[j].diem > max)
            {
                max = p[j].diem;
                index = j;
            }
        }
        sinhvien tmp = p[i];
        p[i] = p[index];
        p[index] = tmp;  
    }
    cout << "\t\tDanh sach sinh vien sau khi da sap xep theo chieu giam dan cua diem la: " << endl;
    for (int i=0 ; i<n ; i++)
        cout << left << setw(cot1+3) << p[i].msv << left << setw(cot2+3) << p[i].hoten << left << setw(cot3+3) << p[i].lop << left << setw(cot4+3) << p[i].diem << endl;
}

int main()
{
    int n,cot1 = 12, cot2 = 9, cot3 = 3, cot4 = 4;
    sinhvien *p;
    nhap(p,n,cot1,cot2,cot3,cot4);
    xuat(p,n,cot1,cot2,cot3,cot4);
    sort(p,n,cot1,cot2,cot3,cot4);
    return 0;
}