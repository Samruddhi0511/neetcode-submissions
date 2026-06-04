class WordDictionary {
private:
    struct trie{
        trie* children[26];
        bool isend;

        trie(){
            for(int i=0; i<26 ; i++){
                children[i]=nullptr;
            }
            isend=false;
        }
    };
    trie* root;
public:
    bool dfs(int idx, string&word, trie* curr){
        //uve reached the end of the branch
        if(curr==nullptr) return false;
        if(idx==word.length()) return curr->isend;
        char ch=word[idx];

        if(ch=='.'){
            for(int i=0; i<26; i++){
                if(curr->children[i]){
                    if(dfs(idx+1, word, curr->children[i])) return true;
                }

            }
            return false; //none of the branches r marked yet
        }
        else {
            int index= ch-'a';
            return dfs(idx+1, word, curr->children[index]);
        }

    }
    WordDictionary() {
        root=new trie();
    }
    
    void addWord(string word) {
        trie* curr=root;
        for(char ch : word){
            int idx=ch-'a';
            if(curr->children[idx]==nullptr) curr->children[idx]=new trie();
            
            curr=curr->children[idx];
        }
        curr->isend=true;
    }
    
    bool search(string word) {
       return dfs(0, word, root);
    }
};
