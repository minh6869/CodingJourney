#include <iostream>
using namespace std;
// cho tổng cộng dồn từ 1 + 1/2 + ... + 1/(n-1) + 1/n
int N;
float y1(int n)
{
	if(n==N)
		return 1.0/N;
	else
		return 1.0/n + y1(n+1);
}
int main()
{
	cout << "Nhap n = ";
	cin >> N;
	cout << y1(1);
	return 0;

}
