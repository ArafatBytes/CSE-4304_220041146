#include<iostream>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

void insert_front(node*& head, node*& tail, int key){
    node* newNode=new node();
    newNode->data=key;
    newNode->prev=nullptr;
    if(head!=nullptr){
        head->prev=newNode;
        newNode->next=head;
    }
    head=newNode;
    if(tail==nullptr){
        tail=newNode;
    }
}

void insert_back(node*& head, node*& tail, int key){
    node* newNode=new node();
    newNode->data=key;
    newNode->next=nullptr;
    if(tail!=nullptr){
        tail->next=newNode;
        newNode->prev=tail;
    }
    tail=newNode;
    if(head==nullptr){
        head=newNode;
    }
}

void printList(node*& head, node*& tail){
    node* temp=head;
    if(temp==nullptr){
        cout<<"Empty"<<endl;
        return;
    }
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void intersectList(node*& head1, node*& tail1, node*& head2, node*& tail2,node*& headAns,node*& tailAns){
    node* temp1=head1;
    node* temp2=head2;
    while(temp1!=nullptr){
        while(temp2!=nullptr){
            if(temp1->data==temp2->data){
                if(headAns==nullptr){
                    insert_back(headAns,tailAns,temp1->data);
                }
                else if(tailAns->data!=temp1->data){
                    insert_back(headAns,tailAns,temp1->data);
                }
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
        temp2=head2;
    }
}

int main(){
    node* head1=nullptr;
    node* tail1=nullptr;
    node* head2=nullptr;
    node* tail2=nullptr;
    node* headAns=nullptr;
    node* tailAns=nullptr;
    while(true){
        int n;
        cin>>n;
        if(n==-1){
            break;
        }
        else{
            insert_back(head1,tail1,n);
        }
    }
    while(true){
        int a;
        cin>>a;
        if(a==-1){
            break;
        }
        else{
            insert_back(head2,tail2,a);
        }
    }
    intersectList(head1,tail1,head2,tail2,headAns,tailAns);
    printList(headAns,tailAns);
}