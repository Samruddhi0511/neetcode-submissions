class PrefixTree {

private:
    struct trie{
        trie* children[26];
        bool isend;

        trie(){
            isend=false;
            for(int i=0; i<26; i++){
                children[i]=nullptr;
            }
        }
    };
    trie* root;
public:
    PrefixTree() {
        root=new trie();
    }
    
    void insert(string word) {
        trie* curr=root;
        for(char ch : word){
            int index=ch-'a';
            if(curr->children[index]==nullptr){
                curr->children[index]=new trie();
            }

            curr=curr->children[index];
        }
        curr->isend=true;

    }
    
    bool search(string word) {
        trie* curr=root;

        for(char ch : word){
            int idx=ch-'a';
            if(curr->children[idx]==nullptr) return false;
            curr=curr->children[idx];
        }
        return curr->isend;
    }
    
    bool startsWith(string prefix) {
        trie* curr= root;
        for(char ch : prefix){
            int idx=ch-'a';
            if(curr->children[idx]==nullptr) return false;
            curr=curr->children[idx];
        }
        return true;
    }
};
