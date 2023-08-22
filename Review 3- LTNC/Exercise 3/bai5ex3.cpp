#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node *next;
};
Node *createNode(int x)
{
    Node *node = new Node;
    node->data = x;
    node->next = NULL;
    return node;
}
void pushBack(Node *&head, int x)
{
    Node *node = createNode(x);
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
void pushFront(Node *&head, int x)
{
    Node *node = createNode(x);
    if(head == NULL)
        head = node;
    else
    {
        node->next = head;
        head = node;
    }
}
void input(Node *&head, int &tong)
{
    int n;
    while(1)
    {
        cout << "Cho n = ";
        cin >> n;
        if(n>=20)
            break;
    }
    for(int i = 2; i<= n ; i+=2)
    {
        pushBack(head,i);
        tong += i;
    }
}

void output(Node *head)
{
    cout << "Hien thi danh sach:";
    for (Node *i = head; i != NULL ; i=i->next)
        cout << ' ' << i->data;
    cout << endl;
}
int main()
{
    Node *head = NULL;
    int tong = 0;
    input(head, tong);
    output(head);
    cout << "Cho so nguyen x = ";
    int x ; cin >> x;
    
    if(x%2)
    {
        cout << "Them x vao cuoi danh sach!" << endl;
        pushBack(head,x);
    }
    else
    {
        cout << "Them x vao dau danh sach!" << endl;
        pushFront(head,x);
    }
    output(head);
    cout << "Tong cac phan tu: " << tong+x;
    return 0;
}