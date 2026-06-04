class Solution {
private:
    struct trie{
        trie* children[26];
        string word;

        trie(){
            word="";
            for(int i=0; i<26 ; i++) children[i]=nullptr;
        }
    };

    trie* root;
    vector<string> ans;

    void insert(string word){
        trie* curr=root;
        for(char ch : word){
            int idx= ch-'a';
            if(curr->children[idx]==nullptr) curr->children[idx]=new trie();
            curr=curr->children[idx];
        }

        curr->word=word;
    }

    void dfs(int r, int c, vector<vector<char>> &board, trie* curr){
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size()) return;

        char ch=board[r][c];
        int idx=ch-'a';

        if(curr->children[idx]==nullptr || ch=='#') return;
        curr=curr->children[idx];
        //if its there
        if(!curr->word.empty()){
            ans.push_back(curr->word);
            curr->word="";
        }

        board[r][c]='#';
        dfs(r+1, c, board, curr);
        dfs(r-1, c, board, curr);
        dfs(r, c+1, board, curr);
        dfs(r, c-1, board, curr);

        board[r][c]=ch;

        }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new trie();
        for(string& w : words){
            insert(w);
        }

        int rows=board.size();
        int cols=board[0].size();

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                dfs(r,c,board, root);
            }
        }
        return ans;
    }
};
