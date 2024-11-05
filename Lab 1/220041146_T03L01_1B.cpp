#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    vector<int>input;
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
    int range;
    cin>>range;
    int firstNum=1;
    int i=0;
    while(i<input.size()){
        if(input[i]==firstNum){
            Stack.push(firstNum);
            cout<<"Push ";
            firstNum++;
            i++;
        }
        else{
            Stack.push(firstNum);
            Stack.pop();
            cout<<"Push Pop ";
            firstNum++;
        }
    }
}