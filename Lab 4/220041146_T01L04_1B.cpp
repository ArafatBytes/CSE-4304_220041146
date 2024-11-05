#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void insert_front(node*& head,node*& tail,int key){
    node* newNode=new node();
    newNode->data=key;
    newNode->next=head;
    head=newNode;
    if(tail==nullptr){
        tail=newNode;
    }
}

void insert_back(node*& head,node*& tail,int key){
    node* newNode=new node();
    newNode->data=key;
    newNode->next=nullptr;
    if(head==nullptr){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}

void insert_after_node(node*& head,node*& tail,int key,int v){
    node* newNode=new node();
    newNode->data=key;
    node* temp=head;
    while(temp->data!=v && temp!=nullptr){
        temp=temp->next;
    }
    if(temp==nullptr){
        cout<<"Value Not found"<<endl;
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    if(newNode->next==nullptr){
        tail=newNode;
    }
}

void update_node(node*& head,node*& tail,int key,int v){
    node* temp=head;
    while(temp!=nullptr && temp->data!=v){
        temp=temp->next;
    }
    if(temp==nullptr){
        cout<<"Value Not found"<<endl;
        return;
    }
    temp->data=key;
}

void remove_head(node*& head,node*& tail){
    if(head==nullptr){
        cout<<"Underflow!"<<endl;
        return;
    }
    node* temp=head;
    head=head->next;
    if(head==nullptr){
        tail=nullptr;
    }
    delete temp;
}

void remove_end(node*& head,node*& tail){
    if(head==nullptr){
        cout<<"Underflow!"<<endl;
        return;
    }
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        tail=nullptr;
        return;
    }
    node* temp=head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    delete tail;
    tail=temp;
    tail->next=nullptr;
}

void remove_element(node*& head,node*& tail,int key){
    if(head==nullptr){
        cout<<"Underflow!"<<endl;
        return;
    }
    node* temp=head;
    node* iterate=temp;
    while(temp!=nullptr){
        if(temp->data==key){
            break;
        }
        iterate=temp;
        temp=temp->next;
    }
    if(temp==nullptr){
        cout<<"Value Not found"<<endl;
        return;
    }
    node* toDelete=temp;
    iterate->next=temp->next;
    if(toDelete==tail){
        tail=temp;
    }
    delete toDelete;
}

void printList(node*& head,node*& tail){
    if(head==nullptr && tail==nullptr){
        cout<<"Head=Null, Tail=Null, Empty"<<endl;
        return;
    }
    cout<<"Head= "<<head->data<<", Tail= "<<tail->data<<", ";
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=nullptr;
    node* tail=nullptr;
    while(true){
        int n;
        cin>>n;
        switch(n){
            int val;
            int v;
            case 1:
                cin>>val;
                insert_front(head,tail,val);
                printList(head,tail);
                break;
            case 2:
                cin>>val;
                insert_back(head,tail,val);
                printList(head,tail);
                break;
            case 3:
                cin>>val;
                cin>>v;
                insert_after_node(head,tail,val,v);
                printList(head,tail);
                break;
            case 4:
                cin>>val;
                cin>>v;
                update_node(head,tail,val,v);
                printList(head,tail);
                break;
            case 5:
                remove_head(head,tail);
                printList(head,tail);
                break;
            case 6:
                cin>>val;
                remove_element(head,tail,val);
                printList(head,tail);
                break;
            case 7:
                remove_end(head,tail);
                printList(head,tail);
                break;
            case 8:
                return 0;
                break;
            default:
                cout<<"Invalid operations!"<<endl;
        }
    }
}