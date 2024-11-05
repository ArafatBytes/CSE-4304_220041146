#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string st;
    vector<char>output;
    stack<char>Stack;
    cin>>st;
    for(int i=0;i<st.length();i++){
        if(Stack.empty()){
            Stack.push(st[i]);
        }
        else{
            if(Stack.top()==st[i]){
                Stack.pop();
            }
            else{
                Stack.push(st[i]);
            }
        }
    }
    while(!Stack.empty()){
        output.push_back(Stack.top());
        Stack.pop();
    }
    reverse(output.begin(),output.end());
    for(int i=0;i<output.size();i++){
        cout<<output[i];
    }
    if(output.empty()){
        cout<<"NULL"<<endl;
    }
    cout<<endl;
}