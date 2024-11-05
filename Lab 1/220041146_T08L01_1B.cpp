#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

bool flag=1;

void checkParen(string s){
    stack<char>Stack;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            Stack.push(s[i]);
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(Stack.empty()){
                flag=0;
                break;
            }
            else{
                char top=Stack.top();
                Stack.pop();
                if((s[i]==')' && top!='(') || (s[i]=='}' && top!='{') || (s[i]==']' && top!='[')){
                flag=0;
                break;
            }
            }
        }
    }
    if(!Stack.empty()){
        flag=0;
    }
}

int main(){
    int N;
    string st;
    string code="";
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++){
        getline(cin,st);
        code+=st;
    }

    checkParen(code);

    if(flag==1){
        cout<<"No Errors"<<endl;
    }
    else{
        cout<<"Error"<<endl;
    }
}