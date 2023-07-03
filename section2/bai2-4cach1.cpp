#include <iostream>
#include <cmath>
using namespace std;
// cho tổng chạy từ 1 + x + x^2 + ... + x^n
int n;
float x;
float tong(int i)
{
	if(i > n)
		return 0;
	return pow(x,i) + tong(i+1);

}
int main()
{
	cout << "Nhập n = ";
	cin >> n;
	cout << "Nhập x = ";
	cin >> x;
	cout << tong(0);
	return 0;
}
