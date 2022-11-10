#include<iostream>
#include<stack>
using namespace std;
bool isOperator(char c)
{
    
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
string i2p(stack<char>s,string inn){
    string post;
    for(int i=0;i<inn.length();i++)
    {
        if((inn[i]>='a'&&inn[i]<='z')||(inn[i]>='A'&&inn[i]<='Z')){
            post+=inn[i];
        }
        else if(inn[i]=='('){
            s.push(inn[i]);
        }
        else if(inn[i] == ')'){
            while((s.top()!='(')&& (!s.empty())){
                char x = s.top();
                post+=x;
                s.pop();
            }
            if(s.top()=='(') 
                s.pop();
        }
        else if(isOperator(inn[i])){
            if(s.empty()){
                s.push(inn[i]);
            }
            else{
                if(precedence(inn[i]) > precedence(s.top())){
                    s.push(inn[i]);
                }
                else if((precedence(inn[i]) == precedence(s.top()) ) && inn[i] == '^' ){
                    s.push(inn[i]);
                }
                else{
                    while((!s.empty())&&(precedence(inn[i]) <= precedence(s.top()) )){
                        post+=s.top();
                        s.pop();
                    }
                    s.push(inn[i]);
                }
            }
        }
    }
    while(!s.empty()){
        post += s.top();
        s.pop();
    }
    return post;
}
int main(){
    string infix;
    cout<<"enter: "; cin>>infix;
    stack<char> st;
    cout<<endl<<"infix exp: "<<infix;
    cout<<endl<<"postfix exp: "<<i2p(st,infix);
    return 0;
}