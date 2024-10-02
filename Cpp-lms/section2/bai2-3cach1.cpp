#include <iostream>
using namespace std;
// cho tổng cộng dồn từ 2 + 4 + 6 + ... + 2n
int n;
int tong(int i)
{
	if(i > 2*n)
		return 0;
	return i + tong(i+2);
}
int main()
{
	cout << "Nhập n = ";
	cin >> n;
	cout << "Tổng từ 2 đến 2n là: " << tong(2);
	return 0;
}
