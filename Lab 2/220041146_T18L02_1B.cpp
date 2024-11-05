#include<iostream>
using namespace std;

int si=0,front=-1,rear=-1;

bool isEmpty(){
    return (si==0);
}

bool isFull(int n){
    return (si==n);
}

void push_front(int Deque[], int val, int &f, int &r, int &s, int n){
    if(isEmpty()){
        f=0;
        r=0;
    }
    else{
        f=(f-1+n)%n;
    }
    Deque[f]=val;
    s++;
    int i=f,temp=s;
    while(temp--){
        cout<<Deque[(i++)%n]<<" ";
    }
    cout<<endl;
}

void push_back(int Deque[],int val,int &f, int &r, int &s, int n){
    if(isEmpty()){
        f=0;
        r=0;
    }
    else{
        r=(r+1)%n;
    }
    Deque[r]=val;
    s++;
    int i=f,temp=s;
    while(temp--){
        cout<<Deque[(i++)%n]<<" ";
    }
    cout<<endl;
}

int pop_front(int Deque[],int &f,int &r, int &s, int n){
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
            f=(f+1)%n;
        }
        s--;
    }
    int i=f,temp=s;
    while(temp--){
        cout<<Deque[(i++)%n]<<" ";
    }
    cout<<endl;
}

int pop_back(int Deque[],int &f, int &r, int &s, int n){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return -1;
    }
    else{
        if(f==r){
            f=-1;
            r=-1;
        }
        else{
            r=(r-1+n)%n;
        }
        s--;
    }
    int i=f,temp=s;
    while(temp--){
        cout<<Deque[(i++)%n]<<" ";
    }
    cout<<endl;
}

int Size(int &s){
    cout<<s<<endl;
}

int main(){
    int n;
    cin>>n;
    int Deque[n];
    string op="";
    while(true){
        cin>>op;
        if(op=="E"){
            return 0;
        }
        if(op=="PF"){
            int a;
            cin>>a;
            push_front(Deque,a,front,rear,si,n);
        }
        else if(op=="PB"){
            int b;
            cin>>b;
            push_back(Deque,b,front,rear, si,n);
        }
        else if(op=="DF"){
            pop_front(Deque,front, rear, si,n);
        }
        else if(op=="DB"){
            pop_back(Deque,front, rear, si,n);
        }
        else if(op=="S"){
            Size(si);
        }
        else if(op=="F"){
            cout<<front<<endl;
        }
        else if(op=="R"){
            cout<<rear<<endl;
        }
        else if(op=="STAT"){
            if(isFull(n)){
                cout<<"FULL"<<endl;
            }
            else if(isEmpty()){
                cout<<"EMPTY"<<endl;
            }
            else{
                cout<<"NONE"<<endl;
            }
        }
        else{
            cout<<"Invalid Operation!"<<endl;
        }
    }
}