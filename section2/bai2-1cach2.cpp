#include <iostream>
using namespace std;
// cho tổng cộng dồn từ 1/n + 1/(n-1) + ... + 1/2 + 1
float y1(int n)
{
	if(n==1)
		return 1.0;
	else 
		return 1.0/n + y1(n-1);
}
int main()
{
	int n;
	cout << "Nhap n = ";
	cin >>n;
	cout << y1(n);
	return 0;
}
