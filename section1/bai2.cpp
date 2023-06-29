#include <iostream>
#include <cmath>
using namespace std;

int n;
float A[1000];
int demscp;

void y2(float A[]) 
{
	cout << "Cac gia tri cua mang la:";
    	for (int i=0; i<n; i++)
        cout << " " << A[i];
}
float y3(float A[])
{
	float sum=0;
	for(int i=0;i<n;i++)
		sum+=A[i];
	return sum;
}
void y4(float A[])
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(A[i] < 0 )
			dem++;
	}
	if(dem)
		cout << "Trong mang co " << dem << " so am";
	else 
		cout << "Trong mang khong co so am nao";
}
int check(float i)
{
	if( (int)sqrt(i) * (int)sqrt(i) == (int)i)
		return 1;
	else return 0;
}
void y5(float A[])
{	
	for(int i=0; i<n ; i++)
	{
		if( check(A[i]) )
			cout << "So " << A[i] << " la so chinh phuong" << endl;
		else 
			cout << "So " << A[i] << " khong la so chinh phuong" << endl;
	}
}
void y6(float A[])
{
	float sum=0;
	demscp=0;
	for(int i =0 ; i<n ;i++)
	{
		if(check(A[i]))
		{
			sum+=A[i];
			demscp++;
		}
	}
	if(demscp)
		cout << "Trung binh cong cac so chinh phuong la: " << sum/demscp << endl;
	else 
		cout << "Trong mang khong co so chinh phuong nen khong co trung binh cong";
}
void y7(float A[])
{	
	for(int i =0 ; i<n ;i++)
	{
		if(check(A[i]))
			demscp++;
	}

	
	if(demscp)
	{
		cout << "Cac so chinh phuong co trong mang la: ";
		for(int i=0; i<n; i++)
		{
			if(check(A[i]))
				cout << A[i] << " ";
		}
	}	
	else 
		cout << "Khong co so chinh phuong nao";
}
float y8(float A[])
{
	float max=A[0];

	for(int i=1;i<n;i++)
	{
		if(A[i]> max)
			max = A[i];
	}
	return max;
}
float y9(float A[])
{
	float min=A[0];

	for(int i=1;i<n;i++)
	{
		if(A[i] < min)
			min = A[i];
	}
	return min;
}
void y10(float A[])
{
	float max=A[0],min=A[0];

	for(int i=1;i<n;i++)
	{
		if(A[i]> max)
			max = A[i];
		if(A[i] < min)
			min = A[i];
	}
	cout << "Cac so nam trong khoang tu (" << min << "," << max << ") la:";
	for(int i=0;i<n;i++)
	{
		if( A[i] > min && A[i] < max)
			cout << " " << A[i];
	}

}


int main() {
    cout << "Nhap n = ";
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> A[i];

    int k;
    cout << "Nhap y (2-10): ";
    cin >> k;

    switch(k) {
        case 2: y2(A); break;
	case 3: cout << "Tong cac phan tu cua mang la:" << y3(A);break;
	case 4: y4(A);break;
	case 5: y5(A);break;
	case 6: y6(A);break;
	case 7: y7(A);break;
	case 8: cout << "So lon nhat trong mang la: " << y8(A);break;
	case 9: cout << "So be nhat trong mang la: " << y9(A);break;
	case 10: y10(A);break;
        default: cout << "Bai 2 chi co 10 y ";
    }

    return 0;
}
