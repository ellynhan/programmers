#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    vector<string> slot(10);
    for(int i=0; i<phone_book.size();i++){
        int hash=phone_book[i][0]%10;
        if(slot[hash]==""){ //등록 안 되어있다
            slot[hash]=phone_book[i];
        }else{ // 등록 되어있다
            string tmp= slot[hash].length()<phone_book[i].length()?slot[hash]:phone_book[i];
            int j=1;
            for(;j<tmp.length();j++){
                if(slot[hash][j]!=phone_book[i][j])break;
            }
            if(j==tmp.length())return false;
        }
    }return true;
}
