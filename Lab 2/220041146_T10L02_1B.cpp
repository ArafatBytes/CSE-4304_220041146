#include<iostream>
using namespace std;

int si=0,front=-1,rear=-1;
int Deque[5];

bool isEmpty(){
    return (si==0);
}

bool isFull(){
    return (si==5);
}

void push_front(int val, int &f, int &r, int &s){
    if(isEmpty()){
        f=0;
        r=0;
    }
    else{
        f=(f-1+5)%5;
    }
    Deque[f]=val;
    s++;
    int i=f,temp=s;
    while(temp--){
        cout<<Deque[(i++)%5]<<" ";
    }
    cout<<endl;
}

void push_back(int val,int &f, int &r, int &s){
    if(isEmpty()){
        f=0;
        r=0;
    }
    else{
        r=(r+1)%5;
    }
    Deque[r]=val;
    s++;
    int i=f,temp=s;
    while(temp--){
        cout<<Deque[(i++)%5]<<" ";
    }
    cout<<endl;
}

int pop_front(int &f,int &r, int &s){
    if(isEmpty()){
        cout<<"Deque is empty"<<endl;
        return -1;
    }
    else{
        if(f==r){
            f=-1;
            r=-1;
        }
        else{
            f=(f+1)%5;
        }
        s--;
    }
    int i=f,temp=s;
    while(temp--){
        cout<<Deque[(i++)%5]<<" ";
    }
    cout<<endl;
}

int pop_back(int &f, int &r, int &s){
    if(isEmpty()){
        cout<<"Deque is empty"<<endl;
        return -1;
    }
    else{
        if(f==r){
            f=-1;
            r=-1;
        }
        else{
            r=(r-1+5)%5;
        }
        s--;
    }
    int i=f,temp=s;
    while(temp--){
        cout<<Deque[(i++)%5]<<" ";
    }
    cout<<endl;
}

int Size(int &s){
    cout<<s<<endl;
}

int main(){
    int op=0;
    while(op!=6){
        cin>>op;
        switch(op){
            case 1:
                int a;
                cin>>a;
                push_front(a,front,rear,si);
                break;
            case 2:
                int b;
                cin>>b;
                push_back(b,front,rear, si);
                break;
            case 3:
                pop_front(front, rear, si);
                break;
            case 4:
                pop_back(front, rear, si);
                break;
            case 5:
                Size(si);
                break;
            default:
                cout<<"Invalid operation"<<endl;
                break;
        }
    }
    return 0;
}