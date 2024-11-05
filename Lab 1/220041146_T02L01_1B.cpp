#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int main(){
    int n;
    stack<string>Stack;
    string st;
    vector<string>input;
    cin>>n;
    cin.ignore();

    for(int i=0;i<n;i++){
        getline(cin,st);
        input.push_back(st);
    }
    int i=0;
    for(i=0;i<n;i++){
        for(int j=0;j<input[i].size();j++){
            if(input[i][j]=='<'){
                bool closing=0;
                if(input[i][j+1]=='/'){
                    closing=1;
                    j+=2;
                }
                else{
                    j++;
                }
                string s="";
                while(input[i][j]!='>'){
                    s+=input[i][j++];
                } 
                if(closing ==0){
                    Stack.push(s);
                }
                else{
                    if(Stack.top()!=s){
                        cout<<"Error at line: "<<i+1<<endl;
                        exit(0);
                    }
                    else{
                        Stack.pop();
                    }
                }

            }
        }
    }
    if(!Stack.empty()){
      cout<<"Error at line ::"<<i+1<<endl;
      exit(0);  
    }
    else{
       cout<<"NO Error"<<endl; 
    }
}