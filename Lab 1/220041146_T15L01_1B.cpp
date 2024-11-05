#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int>output;

void push(int a, int stsize){
    int s=output.size();
    if(s==stsize){
        cout<<"Overflow !!!"<<endl;
    }
    if(s<stsize){
        output.push_back(a);
    }
    cout<<"Size: "<<output.size()<<endl;
    cout<<"Stack elements: ";
    for(int i=0;i<output.size();i++){
        cout<<" "<<output[i];
    }
    cout<<endl;
    cout<<"Top Element: "<<output[output.size()-1]<<endl;
    s=output.size();
    if(s==stsize){
        cout<<"isFull : True"<<endl;
    }
    else{
        cout<<"isFull : False"<<endl;
    }
    if(s==0){
        cout<<"isEmpty : True"<<endl;
    }
    else{
        cout<<"isEmpty : False"<<endl;
    }
}

void pop(int stsize){
    output.pop_back();
    int s=output.size();
    cout<<"Size : "<<s<<endl;
    cout<<"Stack elements : ";
    for(int i=0;i<s;i++){
        cout<<" "<<output[i];
    }
    cout<<endl;
    cout<<"Top Element : "<<output[s-1]<<endl;
    if(s==stsize){
        cout<<"isFull : True"<<endl;
    }
    else{
        cout<<"isFull : False"<<endl;
    }
    if(s==0){
        cout<<"isEmpty : True"<<endl;
    }
    else{
        cout<<"isEmpty : False"<<endl;
    }
}

int main(){
    int N;
    cin>>N;
    cin.ignore();
    char op='a';
    int inp;
    while(op!='/'){
        cin>>op;
        if(op=='+'){
            cin>>inp;
        }
        switch(op){
            case '+':
                push(inp,N);
                break;
            case '-':
                pop(N);
                break;
            default:
                cout<<"Invalid operand"<<endl;
                break;
        }
    }
}