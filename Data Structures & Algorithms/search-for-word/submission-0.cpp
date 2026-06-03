#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool backtrack(int r, int c, int wordidx, vector<vector<char>>& board, string& word) {
        // Base Case 1: If we matched every letter in the word, we win!
        if (wordidx == word.length()) return true;

        // Base Case 2: Boundary check & character mismatch check
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[wordidx]) {
            return false;
        }

        // Save and hide the current character
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 directions (Right, Down, Up, Left)
        bool found = backtrack(r, c + 1, wordidx + 1, board, word) || 
                     backtrack(r + 1, c, wordidx + 1, board, word) ||
                     backtrack(r - 1, c, wordidx + 1, board, word) || 
                     backtrack(r, c - 1, wordidx + 1, board, word);

        // Backtrack: Restore the original character
        board[r][c] = temp;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // Fixed the loop variables here (changed i to r)
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // If we find the starting letter, kick off the DFS
                if (board[r][c] == word[0]) {
                    if (backtrack(r, c, 0, board, word)) return true;
                }
            }
        }
        return false;
    }
};