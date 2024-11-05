#include<iostream>
#include<deque>
using namespace std;

deque<char>line;

string brokenText(string s){
    string output="";
    auto iter=line.begin();
    for(int i=0;i<s.length();i++){
        if(s[i]=='['){
            iter=line.begin();
        }
        else if(s[i]==']'){
            iter=line.end();
        }
        else{
            iter=line.insert(iter,s[i]);
            iter++;
        }
    }
    while(!line.empty()){
        output+=line.front();
        line.pop_front();
    }
    return output;
}

int main(){
    string s;
    cin>>s;
    cout<<brokenText(s)<<endl;
}