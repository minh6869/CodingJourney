#include <iostream>
using namespace std;
// cho tổng chạy từ 2n + 2n-2 + ... + 4 + 2
int tong(int n)
{
	if(n == 2)
		return 2;
	return n + tong(n-2);
}
int main()
{
	int n;
	cout << "Nhập n = ";
	cin >> n;
	cout << "Tổng từ 2 đến 2n là: " << tong(2*n);
	return 0;
}
