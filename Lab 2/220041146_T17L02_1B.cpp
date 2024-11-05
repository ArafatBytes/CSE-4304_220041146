#include<iostream>
#include<queue>
using namespace std;

queue<int>q1,q2,q3;

void push(int val, int s){
    if(q1.size()<s){
        q1.push(val);
        q3=q1;
        while(!q3.empty()){
            cout<<q3.front()<<" ";
            q3.pop();
        }
        cout<<endl;
    }
    else{
        cout<<"Overflow!"<<endl;
        q3=q1;
        while(!q3.empty()){
            cout<<q3.front()<<" ";
            q3.pop();
        }
        cout<<endl;
    }
    
}

void pop(){
    if(q1.empty()){
        cout<<"Underflow!"<<endl;
    }
    else{
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q3=q1;
        while(!q3.empty()){
            cout<<q3.front()<<" ";
            q3.pop();
        }
        cout<<endl;
    }
}

int main(){
    int n,x=1;
    string s;
    cin>>n;
    while(true){
        cin>>x;
        if(x==-1){
            return 0;
        }
        else{
            cin>>s;
            if(s=="push"){
                int a;
                cin>>a;
                push(a,n);
            }
            else if(s=="pop"){
                pop();
            }
            else{
                cout<<"Invalid operation!"<<endl;
            }
        }
    }
}