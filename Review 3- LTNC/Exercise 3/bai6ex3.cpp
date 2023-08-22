#include <iostream>
#include <cmath>
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
void pushBack(Node *&head,int x)
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
int check(int x)
{
    for (int i=2 ; i*i <= x ; i++)
    {
        if(x%i == 0)
            return 0;
    }
    return 1;
}
void input(Node *&head)
{
    int n;
    while(1)
    {
        cout << "Cho n = ";
        cin >> n;
        if(10<=n && n<=100)
            break;
    }
    for(int i=2 ; i<= n ; i++)
    {
        if(check(i))
            pushBack(head,i);
    }
}
void output(Node *head)
{
    cout << "Hien thi lai danh sach:";
    for(Node *i = head ; i!=NULL ; i=i->next)
        cout << ' ' << i->data;
    cout << endl;
}


int main()
{
    Node *head = NULL;
    input(head);
    output(head);
    cout << "Cho so nguyen x = ";
    int x; cin >> x;
    if(check(x) && x!=1)
    {
        cout << "x la so nguyen to. Hay them x vao dau danh sach." << endl;
        pushFront(head,x);
        output(head);
    }
    else
    {
        cout << "x khong phai la so nguyen to!" << endl;
        output(head);
    }
    return 0;
}
