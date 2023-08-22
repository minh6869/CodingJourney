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
void pushBack(Node *& head, double x)
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
void pushFront(Node *&head , double x)
{
    Node *node = createNode(x);
    if(head == NULL )
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
        cout << "Cho so phan tu n = ";
        cin >> n;
        if(n>4)
            break;
    }
    for(int i=1 ; i<=n ; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        double x; cin >> x;
        pushBack(head,x);
    }
    cout << endl;
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
int demdodai(Node *head)
{
    int i = 0;
    while(head!=NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}

void output(Node *head)
{
    cout << "Hien thi danh sach:";
    for(Node *i = head ; i!=NULL ; i=i->next)
        cout << ' ' << i->data;
    cout << endl;
}
int main()
{
    Node *head = NULL;
    input(head);
    output(head);
    double x;
    cout << "Cho x = ";
    cin >> x;
    cout << "Hay them x vao dau va cuoi danh sach." << endl;
    pushBack(head,x);
    pushFront(head,x);
    output(head);
    cout << "Hay xoa o cuoi danh sach:" << endl;
    xoacuoi(head);
    output(head);
    cout << "Do dai cua DS = " << demdodai(head);

}