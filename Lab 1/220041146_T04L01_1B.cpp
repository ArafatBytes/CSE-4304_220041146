#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int>input;
    vector<int>output;
    stack<int>Stack;
    int n;
    while(true){
        cin>>n;
        if(n==-1){
            break;
        }
        else{
            input.push_back(n);
        }
    }
    for(int i=input.size()-1;i>=0;i--){
        if(i==input.size()-1){
            Stack.push(input[i]);
            output.push_back(-1);
        }
        else{
            while(!Stack.empty() && input[i]>=Stack.top() ){
                Stack.pop();
            }
            if(Stack.empty()){
                output.push_back(-1);
                Stack.push(input[i]);
            }
            else if(input[i]<Stack.top()){
                output.push_back(Stack.top());
                Stack.push(input[i]);
            }
        }
    }
    for(int i=output.size()-1;i>=0;i--){
        cout<<output[i]<<" ";
    }
}