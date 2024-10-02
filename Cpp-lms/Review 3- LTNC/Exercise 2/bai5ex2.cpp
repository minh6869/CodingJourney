#include <iostream>
#include <string>
using namespace std;
struct Sinhvien
{
	string name;
	double diem;
};
struct Node
{
	Sinhvien data;
	Node *next;
};
Sinhvien createSV()
{
	Sinhvien sv;
	cout << "Ho va ten: ";
	getline(cin,sv.name);
	while(1)
	{
		cout << "Diem: ";
		cin >> sv.diem;
		cin.ignore();
		if(0<=sv.diem && sv.diem <=10)
			break;
		else
			cout << "Nhap lai diem thi!" << endl;
	}
	return sv;
}
Node *createNode(Sinhvien sv)
{
	Node *node = new Node;
	node->data = sv;
	node->next = NULL;
	return node;
}
void pushBack(Node *&head, Sinhvien sv)
{
	Node *node = createNode(sv);
	if(head == NULL)
		head = node;
	else
	{
		Node *tmp = head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
}
void input(Node *&head)
{
	int n;
	while(1)
	{
		cout << "Cho N = ";
		cin >> n;
		cin.ignore();
		if(0<n && n<100)
			break;
	}
	for(int i=1 ; i<=n ; i++)
	{
		Sinhvien sv = createSV();
		pushBack(head,sv);
	}
}
void output(Node *head)
{
	cout << "In lai danh sach:" << endl;
	for(Node *i=head ; i!=NULL ; i=i->next)
		cout << i->data.name << "\t" << i->data.diem << endl;
	
}
int main()
{
	Node *head = NULL;
	input(head);
	cout << "Thong tin sinh vien them vao DS:" << endl;
	Sinhvien sv;
	cout << "Ho va Ten: ";
	getline(cin,sv.name);
	while(1)
	{
		cout << "Diem thi: ";
		cin >> sv.diem;
		cin.ignore();
		if(0<=sv.diem && sv.diem <=10)
			break;
		else
			cout << "Nhap lai diem thi!" << endl;
	}
	pushBack(head,sv);
	output(head);
	return 0;
}









