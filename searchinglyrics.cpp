#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Trie{
public:
    Trie *children[26];
    int cnt=0;
    bool isTerminal=false;
    Trie() : isTerminal(false) {
           memset(children, NULL, sizeof(children));
    }
    ~Trie() {
        for (int i = 0; i < 26; i++){
            if (children[i])
                delete children[i];
        }
    }
    void insert(string key)
    {
        Trie *p = this;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!p->children[index])
                p->children[index] = new Trie();
            p->cnt++;
            p = p->children[index];
        }
        p->isTerminal = true;
    }
    int search(string key)
    {
        Trie *p = this;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!p->children[index])
                return 0;
            
            p = p->children[index];
        }

        return p->cnt;
    }
};
Trie *proot[10000]; // preffix
Trie *sroot[10000]; // suffix

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int>answer(queries.size());
    for(int i=0; i<words.size(); i++){
        int len = int(words[i].size());
        if(proot[len]==NULL)proot[len]=new Trie();
        if(sroot[len]==NULL)sroot[len]=new Trie();
        proot[len]->insert(words[i]);
        reverse(words[i].begin(),words[i].end());
        sroot[len]->insert(words[i]);
    }
    
    for(int i=0; i<queries.size(); i++){
        int len = int(queries[i].length());
        if(proot[len]==NULL||sroot[len]==NULL){
            answer[i]=0;
            continue;
        }
        string tmp;
        int cnt=0;
        if(queries[i][0]=='?'){
            while(queries[i][cnt]=='?'){cnt++;}
            tmp = queries[i].substr(cnt,len-cnt);
            reverse(tmp.begin(),tmp.end());
            answer[i]=sroot[len]->search(tmp);
        }else{
            while(queries[i][len-cnt-1]=='?'){cnt++;}
            tmp = queries[i].substr(0,len-cnt);
            answer[i]=proot[len]->search(tmp);
        }
    }
    return answer;
}
