#include <iostream>
using namespace std;
struct SoPhuc 
{
	double thuc;
	double ao;
};
SoPhuc tinhtong(SoPhuc x, SoPhuc y)
{
	SoPhuc tong;
	tong.thuc = x.thuc + y.thuc;
	tong.ao = x.ao + y.ao;
	return tong;
}
SoPhuc tinhtich(SoPhuc x, SoPhuc y)
{
	SoPhuc tich;
	tich.thuc = x.thuc*y.thuc - x.ao*y.ao;
	tich.ao = x.thuc*y.ao + x.ao*y.thuc;
	return tich;
}
int main()
{
	SoPhuc x,y;
	cout << "Cho so phuc z1:" << endl << "Phan thuc: ";
	cin >> x.thuc;
	cout << "Phan ao: ";
	cin >> x.ao;
	cout << "Cho so phuc z2:" << endl << "Phan thuc: ";
	cin >> y.thuc;
	cout << "Phan ao: ";
	cin >> y.ao;
	SoPhuc tong = tinhtong(x,y);
	SoPhuc tich = tinhtich(x,y);
	cout << "z1 + z2 = " << tong.thuc << " + " << tong.ao << "i" << endl;
	cout << "z1 * z2 = " << tich.thuc << " + " << tich.ao << "i";
	return 0;
}

