#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

void checkParen(string s){
    bool flag=1;
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
            char top=Stack.top();
            Stack.pop();
            if((s[i]==')' && top!='(') || (s[i]=='}' && top!='{') || (s[i]==']' && top!='[')){
                flag=0;
                break;
            }
        }
    }
    if(flag==0 || !Stack.empty()){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}

int main(){
    string st;
    int N;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++){
        getline(cin,st);
        checkParen(st);
    }
}