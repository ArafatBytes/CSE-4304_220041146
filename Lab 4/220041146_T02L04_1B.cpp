#include <iostream>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

void insert_front(node*& head,node*& tail,int key){
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

void insert_after_node(node*& head,node*& tail,int key,int v){
    node* newNode=new node();
    newNode->data=key;
    node* temp=head;
    while(temp!=nullptr && temp->data!=v){
        temp=temp->next;
    }
    if(temp==nullptr){
        cout<<"Value Not found"<<endl;
        return;
    }
    if(temp->next==nullptr){
        insert_back(head,tail,key);
        return;
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
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
        tail=nullptr;
        return;
    }
    node* temp=head;
    head=head->next;
    head->prev=nullptr;
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
    node* temp=tail;
    tail=tail->prev;
    tail->next=nullptr;
    delete temp;
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
    temp->next->prev=iterate;
    if(toDelete==tail){
        tail=iterate;
        tail->next=nullptr;
    }
    delete toDelete;
}

void printList(node*& head,node*& tail){
    if(head==nullptr && tail==nullptr){
        cout<<"Head=Null, Tail=Null, Empty"<<endl;
        return;
    }
    cout<<"Head= "<<head->data<<", Tail= "<<tail->data<<endl;
    node* start=head;
    while(start!=nullptr){
        cout<<start->data<<" ";
        start=start->next;
    }
    cout<<endl;
    node* back=tail;
    while(back!=nullptr){
        cout<<back->data<<" ";
        back=back->prev;
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