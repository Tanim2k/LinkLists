#include<bits/stdc++.h>

using namespace std;

class Node
{
  public:
  int data;
  Node *prev;
  Node *next;

  Node(int data)
  {
    this->data=data;
    next=NULL;
    prev=NULL;
  }
};

Node *head;
Node *temp;
Node *tail;

void create(int x)
{
  Node *node=new Node(x);

  if(head==NULL)
  {
    head=node;
    tail=node;
    return ;
  }
  tail->next=node;
  temp=tail;
  tail=node;
  tail->prev=temp;
  

}

void print()
{
  Node *temp=head;
  cout<<"Forward-->";
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

  if(head->data==x){
    head=head->next;
    head->prev=NULL;
    return ;
  }

  while(temp->data!=x)
  {
    pre=temp;
    temp=temp->next;

  }
  if(temp->data!=x)
    return ;
  pre->next=temp->next;
 
  temp->next->prev=pre;

}
void printreverse()
{
   Node *p1=tail;
  cout<<"Reverse--->";
  while(tail->prev!=NULL)
  {
      cout<<p1->data<<" ";
      p1=p1->prev;
  }
  cout<<p1->data<<endl;
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
     Delete(3);
     print();
     Delete(1);
     print();
     printreverse();
     
}