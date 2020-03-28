#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> check;

int check_prime(vector<int> v){
    int ret = 0;
    sort(v.begin(),v.end());
    do{
        int j = 1, prime = 0;
        for(int i=v.size()-1;i>=0;i--){
            prime += (v[i] * j);
            j*=10;
        }
        if(check[prime] != 0 || prime <2) {continue;}
        check[prime]++;
        bool sw = false;
        for(int i=2;i<prime;i++){
            if(prime%i == 0) {sw = true; break;}
        }
        if(sw == false) ret++;
    }while(next_permutation(v.begin(),v.end()));
    return ret;
}
int solution(string numbers) {
    int answer = 0;
    vector<int> v,mask;
    for(int i=0;i<numbers.length();i++)
        v.push_back(numbers[i]-48);
    mask.assign(v.size(),0);

    for(int i=0;i<v.size();i++){
        mask[i] = 1;
        do{
            vector<int> temp;
            for(int i=0;i<mask.size();i++){
                if(mask[i] == 1) temp.push_back(v[i]);
            }
            answer += check_prime(temp);
        }while(prev_permutation(mask.begin(),mask.end()));
    }
    return answer;
}
