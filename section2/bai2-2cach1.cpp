#include <iostream>
using namespace std;
// cho tổng cộng dồn từ 1 + 3 + 6 + ... + 3n 
int n;
int tong(int i)
{
    if(i > 3*n)
        return 0;
    return i + tong(i+3);
}

int main()
{
    cout << "Nhap n = ";
    cin >> n;
    cout << "Tong tu 1 den 3n la: " << tong(2) + 1;
    return 0;
}
