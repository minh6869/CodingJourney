#include <iostream>
using namespace std;
struct Node
{
    double data;
    Node *next;
};
Node *createNode (double x)
{
    Node *node = new Node;
    node->data = x;
    node->next = NULL;
    return node;
}
void pushBack(Node **head, double x)
{
    Node *node = createNode(x);
    if(*head == NULL)
        *head = node;
    else
    {
        Node *tmp = *head;
        while(tmp->next != NULL)
            tmp=tmp->next;
        tmp->next = node;
    }
}
void input(Node *&head, double n)
{
    double x;
    for(double i=1 ; i<=n ; i++)
    {
        cout << "Phan tu thu " << i << ": ";
        cin >> x;
        pushBack(&head,x);
    }
}

void output(Node *head)
{
    cout << "Danh sach:";
    for(Node*i=head ; i!=NULL ; i=i->next)
        cout << ' ' << i->data;
    cout << endl;
}
int main()
{
    int n;
    while(1)
    {
        cout << "Cho N = ";
        cin >> n;
        if(0<=n && n<100)
            break;
    }
    Node *head = NULL;
    input(head,n);
    output(head);
    cout << "Cho x = ";
    double x; cin >> x;
    pushBack(&head,x);
    output(head);
    return 0;
}