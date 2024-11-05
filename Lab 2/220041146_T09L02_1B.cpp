#include<iostream>
#include<stack>
#include<vector>
using namespace std;

stack<int>Stack1;
stack<int>Stack2;

vector<int>Vector1;
vector<int>Vector2;

void push(int val, int size){
    if(Stack1.empty() && Stack2.empty()){
        Stack1.push(val);
        cout<<"Size: "<<Stack1.size()<<endl;
        cout<<"Elements: "<<Stack1.top()<<endl;
        return;
    }
    if(Stack1.size()==size){
        cout<<"Size: "<<size<<endl;
        cout<<"Overflow!"<<endl;
        return;
    }
    if(Stack1.empty() && !Stack2.empty()){
        while(!Stack2.empty()){
            Stack1.push(Stack2.top());
            Stack2.pop();
        }
        Stack1.push(val);
        cout<<"Size: "<<Stack1.size()<<endl;
        cout<<"Elements: ";
        while(!Stack1.empty()){
            Vector1.push_back(Stack1.top());
            Stack1.pop();
        }
        for(int i=Vector1.size()-1;i>=0;i--){
            cout<<Vector1[i]<<" ";
        }
        cout<<endl;
        for(int i=Vector1.size()-1;i>=0;i--){
            Stack1.push(Vector1[i]);
        }
        Vector1.clear();
    }
    else{
        Stack1.push(val);
        cout<<"Size: "<<Stack1.size()<<endl;
        cout<<"Elements: ";
        while(!Stack1.empty()){
            Vector1.push_back(Stack1.top());
            Stack1.pop();
        }
        for(int i=Vector1.size()-1;i>=0;i--){
            cout<<Vector1[i]<<" ";
        }
        cout<<endl;
        for(int i=Vector1.size()-1;i>=0;i--){
            Stack1.push(Vector1[i]);
        }
        Vector1.clear();
    }
}

void pop(){
    if(Stack1.empty() && Stack2.empty()){
        cout<<"Underflow"<<endl;
        return;
    }
    if(Stack2.empty() && !Stack1.empty()){
        while(!Stack1.empty()){
            Stack2.push(Stack1.top());
            Stack1.pop();
        }
        Stack2.pop();
        cout<<"Size: "<<Stack2.size()<<endl;
        cout<<"Elements: ";
        while(!Stack2.empty()){
            Vector2.push_back(Stack2.top());
            Stack2.pop();
        }
        for(int i=0;i<Vector2.size();i++){
            cout<<Vector2[i]<<" ";
        }
        cout<<endl;
        for(int i=Vector2.size()-1;i>=0;i--){
            Stack2.push(Vector2[i]);
        }
        Vector2.clear();
    }
    else{
        Stack2.pop();
        cout<<"Size: "<<Stack2.size()<<endl;
        cout<<"Elements: ";
        while(!Stack2.empty()){
            Vector2.push_back(Stack2.top());
            Stack2.pop();
        }
        for(int i=Vector2.size()-1;i>=0;i--){
            cout<<Vector2[i]<<" ";
        }
        cout<<endl;
        for(int i=Vector2.size()-1;i>=0;i--){
            Stack2.push(Vector2[i]);
        }
        Vector2.clear();
    }
}

int main(){
    int N,q;
    cin>>N>>q;
    while(q--){
        int a;
        cin>>a;
        switch(a){
            case 1:
                int b;
                cin>>b;
                push(b,N);
                break;
            case 2:
                pop();
                break;
            default:
                cout<<"Invalid operation"<<endl;
                break;
        }
    }
    return 0;
}