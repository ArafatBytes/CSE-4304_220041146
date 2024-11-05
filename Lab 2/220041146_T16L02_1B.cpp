#include<iostream>
using namespace std;

int front=-1,rear=-1, count=0;

bool full(int c,int sz){
    if(c==sz){
        return true;
    }
    else{
        return false;
    }
}

bool empty(int c){
    if(c==0){
        return true;
    }
    else{
        return false;
    }
}

void EnQue(int arr[],int s, int &f, int &r,int &c, int val){
    if(f==-1 && r==-1){
        f=r=0;
        arr[f]=val;
        c++;
        cout<<"Current size: "<<c<<endl;
        cout<<"Full? : NO"<<endl;
        cout<<"Empty? : NO"<<endl;
        cout<<"Front element: "<<arr[f]<<endl;
        cout<<"Front Index: "<<f<<endl;
        cout<<"Rear element: "<<arr[r]<<endl;
        cout<<"Rear index: "<<r<<endl;
        cout<<"Queue elements: "<<arr[f]<<endl;
        return;
    }
    else{
        if(full(c,s)){
            cout<<"Overflow!"<<endl;
            cout<<"Current size: "<<c<<endl;
            cout<<"Full? : "<< full(c,s)<<endl;
            cout<<"Empty? : "<< empty(c)<<endl;
            cout<<"Front element: "<<arr[f]<<endl;
            cout<<"Front Index: "<<f<<endl;
            cout<<"Rear element: "<<arr[r]<<endl;
            cout<<"Rear index: "<<r<<endl;
            cout<<"Queue elements: ";
            for(int i=f;i<=r;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else{
            r=(r+1)%s;
            arr[r]=val;
            c++;
            int temp1=c;
            int temp2=f;
            cout<<"Current size: "<<c<<endl;
            cout<<"Full? : "<< full(c,s)<<endl;
            cout<<"Empty? : "<< empty(c)<<endl;
            cout<<"Front element: "<<arr[f]<<endl;
            cout<<"Front Index: "<<f<<endl;
            cout<<"Rear element: "<<arr[r]<<endl;
            cout<<"Rear index: "<<r<<endl;
            cout<<"Queue elements: ";
            while(temp1--){
                cout<<arr[(temp2++)%s]<<" ";
            }
            cout<<endl;
        }
    }
}

void DeQue(int arr[],int s, int &f, int &r,int &c){
    if(empty(c)){
        cout<<"Underflow!"<<endl;
        cout<<"Current size: "<<c<<endl;
        cout<<"Full? : "<< full(c,s)<<endl;
        cout<<"Empty? : "<< empty(c)<<endl;
        cout<<"Front element: "<<endl;
        cout<<"Front Index: 0"<<endl;
        cout<<"Rear element: "<<endl;
        cout<<"Rear index: 0"<<endl;
        cout<<"Queue elements: "<<endl;
    }
    else{
        f=(f+1)%s;
        c--;
        int temp1=c;
        int temp2=f;
        cout<<"Current size: "<<c<<endl;
        cout<<"Full? : "<< full(c,s)<<endl;
        cout<<"Empty? : "<< empty(c)<<endl;
        cout<<"Front element: "<<arr[f]<<endl;
        cout<<"Front Index: "<<f<<endl;
        cout<<"Rear element: "<<arr[r]<<endl;
        cout<<"Rear index: "<<r<<endl;
        cout<<"Queue elements: ";
        while(temp1--){
            cout<<arr[(temp2++)%s]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int x=1;
    int sz;
    char op;
    cin>>sz;
    int arr[sz];
    while(true){
        cin>>x;
        if(x==-1){
            return 0;
        }
        if(x==1){
            cin>>op;
            if(op=='E'){
                int a;
                cin>>a;
                EnQue(arr,sz,front,rear,count,a);
            }
            else if(op=='D'){
                DeQue(arr,sz,front,rear,count);
            }
            else{
                cout<<"Invalid operation!"<<endl;
        }
        }
    }
}