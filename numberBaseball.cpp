#include <string>
#include <vector>

using namespace std;

int isStrike(string a, string b){
    int strike=0;
    for(int i=0; i<3; i++){
        if(a[i]==b[i])strike++;
    }
    return strike;
}

int isBall(string a, string b){
    int ball=0;
    for(int i=0; i<3; i++){
        if(a[i]==b[i]||a[(i+1)%3]==b[i]||a[(i+2)%3]==b[i])ball++;
    }
    return ball;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int i=123; i<=987; i++){
        string tmp=to_string(i);
        if(tmp[0]=='0'||tmp[1]=='0'||tmp[2]=='0')continue; // zero
        else if(tmp[0]==tmp[1]||tmp[0]==tmp[2]||tmp[1]==tmp[2])continue; //duplication
        for(int j=0; j<baseball.size(); j++){
            string a = to_string(i);
            string b = to_string(baseball[j][0]);
            if(baseball[j][1]!=isStrike(a,b)){break;}
            else if(baseball[j][1]+baseball[j][2]!=isBall(a,b)){break;}
            if(j==baseball.size()-1){answer++;}
        }
    }
    return answer;
}
