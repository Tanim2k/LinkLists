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

void createLast(int x)
{
  Node * node=new Node(x);

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

void createFirst(int x)
{
    Node *temp=new Node(x);
     if(head==NULL)
  {
    head=temp;
    return ;
  }
  temp->next=head;
  head->prev=temp;
  head=temp;

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
   Node *temp=head;

   while(temp->next!=NULL)
   {
    temp=temp->next;
   }
   tail=temp;
 cout<<"Reverse -> ";
   while(tail->prev!=NULL)
   {
    cout<<tail->data<<" ";
    tail=tail->prev;
   }
   cout<<tail->data<<endl;
}

void convertingCircular()
{
  Node *temp=head;

  while(temp->next!=NULL)
    temp=temp->next;

  temp->next=head;
  head->prev=temp;
}

int main()
{
     createLast(5);
     createLast(6);
     createFirst(4);
     createFirst(3);
     createFirst(2);
     createFirst(1);
     print();
     printreverse();
     convertingCircular();
     print();
     
}