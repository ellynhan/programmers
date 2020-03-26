#include <vector>
#include <string>
using namespace std;
void swap(string& a, string& b){ 
    string t=a; a=b; b=t;
}
void partition(string* A, int low, int high){
    if(low>=high) return;
    string& pivot=A[high]; 
    int i=low-1, j=low;
    for(; j<high; j++){
        if(pivot+A[j]>=A[j]+pivot){
            swap(A[++i],A[j]);
        }
    }
    swap(A[++i],pivot);
    partition(A, low, i-1);
    partition(A,i+1,high);
        
}
string solution(vector<int> numbers) {
    string answer="";
    string* str = new string[numbers.size()];
    for(int i=0; i<numbers.size(); i++){
        str[i]=to_string(numbers[i]);
    }
    partition(str,0,(int)(numbers.size()-1));
    for(int i=numbers.size()-1; i>-1; i--){
        answer+=str[i];
    }
    if(answer<"1")answer="0";
    return answer;
}
