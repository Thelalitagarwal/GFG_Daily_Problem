class Solution {
  public:
#define ALPHABET_SIZE 26
    struct TrieNode {
        TrieNode* children[ALPHABET_SIZE];
        bool isLeaf;
        list<string> word;
    };
    vector<string> ans;
    TrieNode* getNewTrieNode(void) {
        TrieNode* pNode = new TrieNode;
        if (pNode) {
            pNode->isLeaf = false;
            for (int i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
        }
        return pNode;
    }
    void insert(TrieNode* root, string word) {
        int index;
        TrieNode* pCrawl = root;
        for (int level = 0; level < word.length(); level++) {
            if (islower(word[level])) continue;
            index = int(word[level]) - 'A';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNewTrieNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isLeaf = true;
        (pCrawl->word).push_back(word);
    }
    void printAllWords(TrieNode* root) {
        if (root->isLeaf) {
            for (string str : root->word) ans.push_back(str);
        }
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            TrieNode* child = root->children[i];
            if (child) printAllWords(child);
        }
    }
    void search(TrieNode* root, string pattern) {
        int index;
        TrieNode* pCrawl = root;

        for (int level = 0; level < pattern.length(); level++) {
            index = int(pattern[level]) - 'A';
            if (!pCrawl->children[index]) return;

            pCrawl = pCrawl->children[index];
        }
        printAllWords(pCrawl);
    }
    vector<string> CamelCase(int N, vector<string> dict, string pattern) {
        TrieNode* root = getNewTrieNode();
        for (string word : dict) insert(root, word);
        search(root, pattern);
        if(ans.empty()) ans.push_back("-1");
        return ans;
    }
};