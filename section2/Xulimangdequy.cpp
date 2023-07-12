#include <iostream>
using namespace std;
int a[100],n;
void Nhap(int a[], int index)
{
    if (index == n)
        return;
    cout << "Nhap phan tu a[" << index << "] = ";
    cin >> a[index];
    Nhap(a,index+1);
}


void xuat(int a[],int index)
{
    if (index == n)
        return;
    cout << a[index] << endl;
    xuat(a,index+1);
}


int tinh_tong(int a[],int index)
{
    if (index == n-1)
        return a[index];
    return a[index] + tinh_tong(a,index+1);
}

int dem_so_am(int a[],int index)
{
    if (index > n)
        return 0;
    if(a[index] < 0)
       return 1 + dem_so_am(a,index+1);
    return dem_so_am(a,index+1);
}
int tong_so_duong(int a[], int index)
{
    if(index > n)
        return 0;
    if(a[index]>0)
        return a[index] + tong_so_duong(a,index+1);
    return tong_so_duong(a,index+1);
}
int so_max(int index, int max)
{
    if(index > n)
        return max;
    if(a[index] > max)
        max = a[index];
    return so_max(index+1,max);
}
int so_min(int index, int min)
{
    if(index > n)
        return min;
    if(a[index] < min)
        min = a[index];
    return so_min(index+1,min);
}
int main()
{
    cout << "Nhap so phan tu cua mang: "; cin >> n;
    Nhap(a,0);
    xuat(a,0);
    cout << "tong la: " << tinh_tong(a,0) << endl;
    cout << "Co " << dem_so_am(a,0) << " so am trong mang ";
    cout << "\nTong so duong trong mang la: " << tong_so_duong(a,0);
    cout << "\nSo lon nhat trong mang la: " << so_max(0,a[0]);
    cout << "\nSo be nhat trong mang la: " << so_min(0,a[0]) << endl;
    return 0;

}