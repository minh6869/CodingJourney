#include <iostream>
#include <cmath>
using namespace std;
//cho tổng chạy từ x^n + x^(n-1) + ... + x + 1
float tong(int i, float x)
{
	if(i == 0)
		return 1;
	return pow(x,i) + tong(i-1,x);
}

int main()
{
	int n;
	float x;
	cout << "Nhập n = ";
	cin >> n;
	cout << "Nhập x = ";
	cin >> x;
	cout << tong(n,x);
	return 0;
}
