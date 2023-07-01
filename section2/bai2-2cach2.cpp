#include <iostream>
using namespace std;
//cho tổng cộng dồn từ 3n + 3n-3 + ... + 9 + 6 + 3 + 1
int tong(int n)
{
	if(n == 0 ) 
		return 1;
	return n + tong(n-3);
}	

int main()
{
	int n;
	cout << "Nhap n = "; cin >> n;
	cout << "tong tu 1 den 3n la: " << tong(3*n);
	return 0;
}
