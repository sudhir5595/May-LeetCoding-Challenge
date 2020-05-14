#define CHAR_SIZE 126

class Trie {
public:
    /** Initialize your data structure here. */
    bool isLeaf;
    Trie* character[CHAR_SIZE];
    Trie() {
        this->isLeaf = false;
        for(int i = 0; i<CHAR_SIZE; i++){
            this->character[i] = NULL;
        }
    } 
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        for(int i=0;i<word.size();i++){
            if(curr->character[word[i]] == NULL){
                curr->character[word[i]] = new Trie();
            }
            curr = curr->character[word[i]];
        }
        // mark current node as leaf
	    curr->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(this == NULL){
            return false;
        }
        Trie* curr = this;
        for(int i = 0; i<word.size(); i++){
            curr = curr->character[word[i]];
            if(curr == NULL){
                return false;
            }
        }
        return curr->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(this == NULL){
            return false;
        }
        Trie* curr = this;
        for(int i = 0; i<prefix.size(); i++){
            curr = curr->character[prefix[i]];
            if(curr == NULL){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
