#include <string>
#include <vector>
using namespace std;

int solution(string arrangement) {
    vector<int> sticks;
    int bar=0;
    string a;
    int sum=0;
    for(int i=0; i<arrangement.length()-1; i++){
        a=arrangement[i];
        a+=arrangement[i+1];
        if(a=="(("){
            sticks.push_back(1);
            bar++;
        }else if(a=="()"&&!sticks.empty()){
            for(int j=0; j<bar; j++){
                sticks[j]++;
            }
        }else if(a=="))"){
            bar--;
        }
    }
    for( auto i :  sticks){sum+=i;}
    return sum;
}
