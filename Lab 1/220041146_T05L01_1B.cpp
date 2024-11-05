#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int main(){
    vector<string>input;
    vector<string>output;
    stack<char>Stack;
    int N;
    string st;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>st;
        input.push_back(st);
    }
    for(int i=0;i<N;i++){
        string op="";
        for(int j=0;j<input[i].size();j++){
            Stack.push(input[i][j]);
        }
        for(int j=0;j<input[i].size();j++){
            op+=Stack.top();
            Stack.pop();
        }
        output.push_back(op);
    }
    for(int i=0;i<N;i++){
        cout<<output[i]<<endl;
    }
}