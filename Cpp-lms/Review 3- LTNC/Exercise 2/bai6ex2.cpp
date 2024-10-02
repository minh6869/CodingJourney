#include <iostream>
#include <string>
using namespace std;
struct Sinhvien
{
	string msv;
	string ten;
	int namsinh;
};
struct Node
{
	Sinhvien data;
	Node *next;
};
Node *createNode(Sinhvien sv)
{
	Node *node = new Node;
	node->data = sv;
	node->next = NULL;
	return node;
}
void pushBack(Node *&head,Sinhvien sv)
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
void pushFront(Node *&head, Sinhvien sv)
{
	Node *node = createNode(sv);
	if(head == NULL)
		head = node;
	else 
	{
		node->next = head;
		head = node;
	}
}
void input(Node *&head)
{
	while(1)
	{
		Sinhvien sv;
		cout << "Nhap MaSV: ";
		getline(cin,sv.msv);
		if(sv.msv=="")
			break;
		cout << "Nhap ten: ";
		getline(cin,sv.ten);
		cout << "Nam sinh: ";
		cin >> sv.namsinh;
		cin.ignore();
		pushBack(head,sv);	
	}
}
void output(Node *head)
{
	cout << "Hien thi danh sach:" << endl;
	for(Node *i = head; i!=NULL ; i=i->next)
		cout << i->data.msv  << "\t" << i->data.ten << "\t" << i->data.namsinh << endl;
}
int main()
{
	Node *head = NULL;
	input(head);
	output(head);
	cout << "Cho SV can them vao dau DS:" << endl;
	Sinhvien sv;
	cout << "MaSV: ";
	getline(cin,sv.msv);
	cout << "Ten: ";
	getline(cin,sv.ten);
	cout << "Nam sinh: ";
	cin >> sv.namsinh;
	cin.ignore();
	pushFront(head,sv);
	output(head);
	return 0;
	
}
