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
    for(int i=1 ; i<=n ; i++)
    {
        int x;
        cout << "Nhap phan tu " << i << ": ";
        cin >> x;
        pushBack(head,x);
    }
}
void outPut(Node *head)
{
    int tong = 0;
    int x;
    cout << "Cho x = ";
    cin >> x;
    cout << "Hay them x vao dau danh sach!" << endl << "In danh sach: " << x;
    for(Node*i = head ; i!=NULL ; i = i->next)
    {
        cout << ' ' << i->data;
        if(i->data % 2 == 0)
            tong += i->data;
    }
    cout << endl;
    if(x%2 == 0)
        cout << "Tong cac so chan: " << tong+x;
    else
        cout << "Tong cac so chan: " << tong;

}
int main()
{
    Node *head = NULL;
    input(head);
    outPut(head);
    return 0;
}