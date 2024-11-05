#include <iostream>
#include <vector>
using namespace std; 

vector<int>stack;

void push(int n,int val,int size){
    size=stack.size();
    if(size<n){
        stack.push_back(val);
        size=stack.size();
        for(int i=0;i<size;i++){
            cout<<stack[i]<<" ";
        }
        cout<<"True"<<endl;
    }
    else{
        cout<<"Overflow"<<endl;
    }
}

void pop(int n, int size){
    size=stack.size();
    if(size > 0){
        stack.pop_back();
        size=stack.size();
        for(int i=0;i<size;i++){
            cout<<stack[i]<<" ";
        }
    }
    else{
        cout<<"Underflow"<<endl;
    }
}

bool isEmpty(int size){
    size=stack.size();
    if(size==0){
        return true;
    }
}

bool isFull(int size, int n){
    size=stack.size();
    if(size == n ){
        return true;
    }
}

void sizeOfStack(int size){
    size=stack.size();
    cout<<size<<endl;
}

void top(int size){
    size=stack.size();
    cout<<stack[size-1]<<endl;
}

int main(){
    int N;
    cin>>N;
    int a=0;
    int size=stack.size();
    cin>>a;
    while(a!=-1){
        cin >> a;
        switch(a){
            case 1:
            int b;
            cin>>b;
            push(N,b,size);
            break;
            
            case 2:
            pop(N,size);
            break;

            case 3:
            if(isEmpty(size)){
                cout<<"True"<<endl;
            }
            else{
                cout<<"False"<<endl;
            }
            break;

            case 4:
                if(isFull(size,N)){
                    cout<<"True"<<endl;
                }
                else{
                    cout<<"False"<<endl;
                }
            break;

            case 5:
            sizeOfStack(size);
            break;

            case 6:
            top(size);
            break;
        }
    }
}