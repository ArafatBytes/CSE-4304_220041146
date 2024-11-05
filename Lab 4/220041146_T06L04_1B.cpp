#include<iostream>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

void printList(node*& head, node*& tail){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void Push(node*& head, node*& tail,int key,int& count,int n){
    if(count<n){
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
        count++;
        printList(head,tail);
    }
    else{
        cout<<"Overflow!"<<endl;
    }
}

void Pop(node*& head, node*& tail,int& count){
    node* temp=tail;
    if(count>0){
        tail=temp->prev;
        tail->next=nullptr;
        delete temp;
        count--;
        printList(head,tail);
    }
    else{
        cout<<"Underflow"<<endl;
    }
}

bool isEmpty(int count){
    return count==0;
}

bool isFull(int count,int n){
    return count==n;
}

int Size(int count){
    return count;
}

int top(node*& tail){
    return tail->data;
}

int main(){
    node* head=nullptr;
    node* tail=nullptr;
    int count=0;
    int N;
    cin>>N;
    while(true){
        int a;
        cin>>a;
        if(a==-1){
            return 0;
        }
        else{
            switch(a){
                case 1:
                    int b;
                    cin>>b;
                    Push(head,tail,b,count,N);
                    break;
                case 2:
                    Pop(head,tail,count);
                    break;
                case 3:
                    if(isEmpty(count)){
                        cout<<"True"<<endl;
                    }
                    else{
                        cout<<"False"<<endl;
                    }
                    break;
                case 4:
                    if(isFull(count,N)){
                        cout<<"True"<<endl;
                    }
                    else{
                        cout<<"False"<<endl;
                    }
                    break;
                case 5:
                    cout<<Size(count)<<endl;
                    break;
                case 6:
                    cout<<top(tail)<<endl;
                    break;
                default:
                    cout<<"Invalid Operation"<<endl;
            }
        }
    }
}