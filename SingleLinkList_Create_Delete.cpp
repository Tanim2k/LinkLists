#include<bits/stdc++.h>

using namespace std;

class Node
{
  public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data=data;
    next=NULL;
  }
};

Node *head;
Node *tail;

void create(int x)
{
  Node *node=new Node(x);

  if(head==NULL)
  {
    head=node;
    tail=node;
  }
  tail->next=node;
  tail=node;
}

void print()
{
  Node *temp=head;

  while(temp->next!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<temp->data<<endl;
}

void Delete(int x)
{
  Node *temp=head;
  Node *pre=head;

  if(head->data==x)
    head=head->next;
  while(temp->data!=x)
  {
    pre=temp;
    temp=temp->next;

  }
  if(temp->data!=x)
    return ;
  pre->next=temp->next;

}

int main()
{
     int n;
     cin>>n;

     for(int i=0;i<n;i++)
     {
      int x;
      cin>>x;
      create(x);
     }
     print();
     Delete(1);
     print();
}