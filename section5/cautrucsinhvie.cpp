#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct sinhvien
{
    string id;
    string name;
    string sub;
    int diem;
};
void nhap(sinhvien sv[], int &n, int & diemmaxall, int &cot1, int &cot2, int &cot3, int&cot4, int &cot5)
{ 

    for (int i = 0; i < n ;i++)
    {
        cout << "Nhap sinh vien thu " << i+1 << " : " << endl;
        cout << "ID: "; 
        fflush(stdin);
        getline(cin,sv[i].id);
        if(sv[i].id.size() > cot2)
            cot2 = sv[i].id.size();


        cout << "Name: ";
        fflush(stdin);
        getline(cin,sv[i].name);
        if(sv[i].name.size() > cot3)
            cot3 = sv[i].name.size();
        
        cout << "Subject: ";
        fflush(stdin);
        getline(cin,sv[i].sub);

        if(sv[i].sub.size() > cot4)
            cot4 = sv[i].sub.size();
        cout << "Mark: ";
        cin >> sv[i].diem;
        if(sv[i].diem > diemmaxall)
            diemmaxall = sv[i].diem;
    }
}
void xuat(sinhvien sv[], int n, int cot1, int cot2, int cot3, int cot4, int cot5)
{
    cout << left << setw(cot1+3) << "Index" << left << setw(cot2+3) << "Id" << left << setw(cot3+3) << "Name" << left << setw(cot4+3) << "Subject" << left << setw(cot5+3) << "Mark" << endl ;
    for (int i = 0; i < n; i++)
        cout << left << setw(cot1+3) << i + 1 << left << setw(cot2+3) << sv[i].id << left << setw(cot3+3) << sv[i].name << left << setw(cot4+3) << sv[i].sub << left << setw(cot5+3) << sv[i].diem << endl;
}

void xuatid(sinhvien sv[], int n, string index, int cot1, int cot2, int cot3, int cot4, int cot5)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if(dem!=0 && index==sv[i].id)
        {
            cout << left << setw(cot1+3) << i + 1 << left << setw(cot2+3) << sv[i].id << left << setw(cot3+3) << sv[i].name << left << setw(cot4+3) << sv[i].sub << left << setw(cot5+3) << sv[i].diem << endl;
            continue;
        }
        if (index == sv[i].id)
        {
            cout << left << setw(cot1+3) << "Index" << left << setw(cot2+3) << "Id" << left << setw(cot3+3) << "Name" << left << setw(cot4+3) << "Subject" << left << setw(cot5+3) << "Mark" << endl ;
            cout << left << setw(cot1+3) << i + 1 << left << setw(cot2+3) << sv[i].id << left << setw(cot3+3) << sv[i].name << left << setw(cot4+3) << sv[i].sub << left << setw(cot5+3) << sv[i].diem << endl;
            dem++;
        }
    }
    if(dem == 0)
        cout << "Khong co sinh vien nao co id nhu vay\n";
}

void danhsachmaxdiem(sinhvien sv[], int n, int & max, int cot1, int cot2, int cot3, int cot4, int cot5)
{
    cout << "Danh sach hoc sinh co diem cao nhat la: " << endl;
    
    for (int i=0 ; i<n ; i++)
    {
        if (sv[i].diem == max)
            cout << left << setw(cot1+3) << i + 1 << left << setw(cot2+3) << sv[i].id << left << setw(cot3+3) << sv[i].name << left << setw(cot4+3) << sv[i].sub << left << setw(cot5+3) << sv[i].diem << endl;


    }
}

void diem_bo_mon_max(sinhvien sv[], int n , string mon, int cot1, int cot2, int cot3, int cot4, int cot5)
{
    int dem = 0;
    int max = sv[0].diem;
    
    for (int i=0 ; i<n ; i++)
    {
        if (sv[i].sub == mon)
        {
            if(sv[i].diem > max)
                max = sv[i].diem;
            dem++;
        }
    }

    if(dem)
    {
        cout << "Danh sach hoc sinh co diem cao nhat cua mon " << mon << " la: " << endl;
        for (int i=0 ; i<n ; i++)
        {
            if(sv[i].sub == mon)
            {
                if(sv[i].diem == max)
                    cout << left << setw(cot1+3) << i + 1 << left << setw(cot2+3) << sv[i].id << left << setw(cot3+3) << sv[i].name << left << setw(cot4+3) << sv[i].sub << left << setw(cot5+3) << sv[i].diem << endl;

            }
        }
    }
    else
        cout << "Khong co du lieu cua mon " << mon << "\n";
}

int main()
{   
    int n,diemmaxall=0,cot1 = 5,cot2 = 2, cot3 = 4, cot4 = 7, cot5 = 4;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    sinhvien sv[n];
    nhap(sv,n,diemmaxall,cot1,cot2,cot3,cot4,cot5);
    xuat(sv,n,cot1,cot2,cot3,cot4,cot5);
    string id;
    cout << "Nhap so id: ";
    fflush(stdin);
    getline(cin,id);
    xuatid(sv,n,id,cot1,cot2,cot3,cot4,cot5);
    danhsachmaxdiem(sv,n,diemmaxall,cot1,cot2,cot3,cot4,cot5);
    string nhapmon;
    cout << "Nhap mon muon lay danh sach hoc sinh co diem cao nhat: ";
    fflush(stdin);
    getline(cin,nhapmon);
    diem_bo_mon_max(sv,n,nhapmon,cot1,cot2,cot3,cot4,cot5);
// Index   Id                    Name                        Subject        Mark
//   1     2       nghieng nghieng nghieng nghieng            toan           2
//   2     3               hoang hoa tham                     van            3
//   3     4                   luu ly                        my thuat        9

}




