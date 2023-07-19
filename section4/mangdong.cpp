#include <iostream>
using namespace std;
int *nhap(int *p, int &n)
{   
    cout << "Nhap n = ";
    cin >> n;
    p = new int[n];
    for (int i = 0; i<n; i++ )
    {
        cout << "a[" << i << "] = ";
        cin >> p[i];
    }
    return p;
}
void xuat(int *p,int n)
{
    for (int i = 0; i < n; i++)
            cout << p[i]  << " ";
    cout << endl;
    return;  
}
int find_min(int *p, int &n)
{
    int min = p[0];
    for (int i=0; i<n ; i++)
    {
        if(p[i] < min)
            min = p[i];
    }
    return min;
}
int find_max(int *p, int &n)
{
    int max = p[0];
    for (int i=0; i<n ; i++)
    {
        if(p[i] > max)
            max = p[i];
    }
    return max;
}
void xoaphantuk(int *p, int &n,int k)
{
    for (int i=k; i< n; i++)
    {
        p[i] = p[i+1];
    }
    n--;
    xuat(p,n);
}
void themphantu(int *p,int &n)
{
    int k,x;
    cout << "Nhap chi so muon chen vao: ";
    cin >> k;
    cout << "Nhap gia tri muon them vao: ";
    cin >> x;
    for (int i = n; i>=k+1; i--)
    {
        p[i] = p[i-1];
    }
    p[k] = x;
    n++;
    xuat(p,n);
}
void xoamax(int *p, int &n)
{
    cout << "Mang sau khi da xoa cac phan tu lon nhat la: ";
    int max = find_max(p,n);
    for(int i = 0; i<n ; i++)
    {
        if(p[i] == max)
        {    xoaphantuk(p,n,i);
            i--;
        }       
    }
}
void swapp(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}


void sortbubble(int *p, int &n)
{   
        for(int i = 0; i < n-1 ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                if (p[j] > p[i])
                {
                    // int a = p[j];
                    // p[j] = p[i];
                    // p[i] = a;
                    swapp(p[j],p[i]);
                }
            }
        }
    cout << "Mang sau khi sap xep giam dan la: ";
    xuat(p,n);
}

void sortselec(int *p, int &n)
{
    int max = p[0];
    int index = 0;
    for(int i = 0; i<n-1 ; i++)
    {
        max = p[i];
        index = i;
        for(int j=i+1; j < n; j++)
        {
            if(p[j] > max)
            {
                max = p[j];
                index = j;
            }
        }
        // int a = p[index];
        // p[index] = p[i];
        // p[i] = a;
        swap(p[index],p[i]);
    }
    cout << "Mang sau khi sap xep giam dan la: ";
    xuat(p,n);
}
int main()
{
    int n,*p;
    p = nhap(p,n);
    xuat(p,n);
    cout << "Min cua mang dong la: " << find_min(p,n) << endl;
    int k;
    cout << "Nhap chi so k: ";
    cin >> k;
    cout << "Mang dong sau khi xoa phan tu co chi so " << k << " la: ";
    xoaphantuk(p,n,k);
    themphantu(p,n);
    //sortbubble(p,n);
    sortselec(p,n);
    xoamax(p,n);
    return 0;
}