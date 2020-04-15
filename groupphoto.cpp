#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

inline int normalize_alphabet(char c)
{
    assert(c >= 'A' && c <= 'Z');
    return c - 'A';
}

inline int normalize_digit(char c)
{
    assert(c >= '0' && c <= '9');
    return c - '0';
}

inline int abs(int n)
{
    return n < 0 ? -n : n;
}

inline void get_indexes(int (*index)[26], const char* str)
{   
    for (int i = 0; str[i] != '\0'; i++)
    {
        (*index)[normalize_alphabet(str[i])] = i;
    }   
}

int solution(int n, vector<string> data)
{
    char str[] = "ACFJMNRT";
    int index[26] = { 0, };
    get_indexes(&index, str);

    int perm[] = {0,1,2,3,4,5,6,7};

    int answer = 0;
    do
    {
        bool flag = true;

        for (string& cond : data)
        {
            const int name1 = normalize_alphabet(cond[0]);
            const int name2 = normalize_alphabet(cond[2]);
            const int num = normalize_digit(cond[4]);
            const char op = cond[3];

            const int dist = abs(perm[index[name1]] - perm[index[name2]]) - 1;

            if (op == '>' && !(dist > num)) flag = false;
            if (op == '=' && !(dist == num)) flag = false;
            if (op == '<' && !(dist < num)) flag = false;

            if (flag == false)
            {
                break;
            }
        }
        if (flag)
        {
            answer++;
        }
    } while (next_permutation(perm, perm + 8));

    return answer;
}
//    int answer=0;
//    char characters[8]={'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
//    do{
//        int cnt=0;
//        for(; cnt<data.size(); cnt++){
//            int locA=-1,locB=-1;
//            for(int cnt2=0; cnt2<8; cnt2++){
//                if(characters[cnt2]==data[cnt][0])locA=cnt2;
//                if(characters[cnt2]==data[cnt][2])locB=cnt2;
//            }
//            if(data[cnt][3]=='='){
//                if(int(abs(locA-locB))!=1)break;
//            }else if(data[cnt][3]=='>'){
//                if(int(abs(locA-locB))-1<=int(data[cnt][4])-48)break;
//            }else{
//                if(int(abs(locA-locB))-1>=int(data[cnt][4])-48)break;
//            }
//        }
//        if(cnt==data.size())answer++;
//    }while(next_permutation(characters,characters+8));
//    cout<<answer;
