#include <iostream>
using namespace std;
struct Node 
{
    double data;
    Node *next;
};
Node *createNode(double x)
{
    Node *node = new Node;
    node->data = x;
    node->next = NULL;
    return node;
}
void pushBack(Node *&head,double x)
{
    Node *node = createNode(x);
    if(head == NULL)
        head = node;
    else
    {
        Node *tmp = head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp -> next = node;
    }
}
void pushFront(Node *&head, double x)
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
void input(Node *&head)
{
    int n;
    while(1)
    {
        cout << "Cho n = ";
        cin >> n;
        if(5<=n && n<100)
            break;
    }
    for(double i=1 ; i<=n ; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        double x; cin >> x;
        pushBack(head,x);
    }
}

void xoadau(Node *&head)
{
    Node *old = head;
    head = head->next;
    delete old;
}
void xoacuoi(Node *&head)
{
    Node *tmp = head;
    while(tmp!=NULL)
    {
        if(tmp->next->next == NULL)
        {
            tmp->next = NULL;
            break;
        }   
        tmp = tmp->next;
    }
}
void output(Node *head)
{
    cout << "Hien thi danh sach:";
    for(Node *i = head ; i!= NULL ; i=i->next)
            cout << ' ' << i->data;
    cout << endl;
}
void tinhtong(Node *head, double &tong)
{
    while(head!=NULL)
    {
        tong+=head->data;
        head=head->next;
    }
}
int main()
{
    Node *head = NULL;
    double tong = 0;
    input(head);
    output(head);
    cout << "Hay xoa phan tu o dau va cuoi danh sach!" << endl;
    xoacuoi(head);
    xoadau(head);
    output(head);
    double x;
    cout << "Cho x = ";
    cin >> x;
    cout << endl << "Hay them x vao dau va cuoi danh sach!" << endl;
    pushBack(head,x);
    pushFront(head,x);
    output(head);
    tinhtong(head,tong);
    cout << "Tong cac phan tu: " << tong;
}