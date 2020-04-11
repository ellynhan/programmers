#include <string>
#include <stack>
using namespace std;
bool isright(string& u){
    stack<char> tmp; // ()(())
    for(int i=0; i<u.length(); i++){
        if(!tmp.empty()&&tmp.top()=='('&&u[i]==')'){
            tmp.pop();
        }else{
         tmp.push(u[i]);
        }
    }
    if(tmp.empty()) return true;
    else return false;
}

string process(string& p){
    if(isright(p))return p;
    int nums[2]={0,0};
    int i=0;
    string u,v;
    do{
        if(p[i]=='('){
            nums[0]++;
        }else{
            nums[1]++;
        }
        i++;
    }while(nums[0]!=nums[1]&&i<p.length());
    u=p.substr(0,i);
    v=p.substr(i,p.length()-i);
    if(isright(u)){
        u+=process(v);
        return u;
    }else{
        string tmp = "(";
        tmp += process(v);
        tmp += ")";
        u=u.substr(1,u.length()-2);
        for(int j=0; j<u.length(); j++){
            if(u[j]=='('){
                u[j]=')';
            }else{
                u[j]='(';
            }
        }
        tmp+=u;
        return tmp;
    }
}
string solution(string p) {
    string answer = "";
    answer = process(p);
    return answer;
}
