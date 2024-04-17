#include<iostream>
#include<stack>
using namespace std;

class Node
{
    public:
    Node*left,*right;
    int data;
    Node()
    {
        left=right=NULL;
        data=0;
    }
    Node(int a)
    {
        left=right=NULL;
        data=a;
    }
};
class BST
{
    Node*root;
    public:
    BST()
    {
        root=NULL;
    }
    void create();
    Node*getroot(){return root;}
    Node*insert(Node*,int);
    void preorder();
};
Node* BST::insert(Node*T,int x)
{
    if(T==NULL)
    {
        return new Node(x);
    }
    if(x<T->data)
    {
        T->left=insert(T->left,x);
        return T;
    }
    else if (x>T->data)
    {
        T->right=insert(T->right,x);
        return T;
    }
return T;
}
void BST::create()
{
    int x;
    while(1)
    {
        cout<<"enter data- ";
        cin>>x;
        if(x==0)
        {
            break;
        }
        root=insert(root,x);
    }
}
void preorder(Node*T)
{
    if(T==NULL){return;}
    cout<<T->data;
    preorder(T->left);
    preorder(T->right);
}
void inorder(Node*T)
{
    if(T==NULL){return;}
    
    inorder(T->left);
    cout<<T->data;
    inorder(T->right);
}
void BST:: preorder()
{
    Node *T=root;
    stack<Node*>stk;
    while(T!=NULL)
    {
        cout<<T->data;
        stk.push(T);
        T=T->left;
    }
    while(!stk.empty())
    {
        T=stk.top();
        stk.pop();
        T=T->right;
        while(T!=NULL)
        {
            cout<<T->data;
            stk.push(T);
            T=T->left;
        }
    }
}
int main()
{   
//   BST b1;
//   b1.create();
//   b1.preorder();
//   cout<<endl<<b1.getroot()->data;
//   preorder(b1.getroot());
//   cout<<endl;
//   inorder(b1.getroot());
    int n,sum=0,num;
    cin>>n;
    num=n;
    for(int i=1;i*i<=n;i++)
    {
        if(num%i==0){
            if(n/i==i)
            {
                sum+=i;
            }
            else
            {
                sum+=i+n/i;
            }
            n=n/i;
        }
    }
    if(n!=1)
    {
        sum+=n;
    }
    sum=sum-num;
    if(sum==num)
    {
        cout<<"YES"<<sum;
    }
    else{
        cout<<"NO"<<sum;
    }
}