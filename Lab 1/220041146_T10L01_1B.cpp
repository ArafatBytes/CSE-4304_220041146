#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int>input;
    stack<int>Stack;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        input.push_back(a);
    }
    int curNum=1,i=0;
    while(curNum<=n && i<=n){
        if(input[i]==curNum){
            curNum++;
            i++;
        }
        else if(!Stack.empty() && Stack.top()==curNum){
            Stack.pop();
            curNum++;
        }
        else{
            Stack.push(input[i]);
            i++;
        }
    }
    if(Stack.empty()){
        cout<<"Yes"<<endl;
    }
    else if(!Stack.empty()){
        cout<<"No"<<endl;
    }

}