class TrieNode{
public:
    TrieNode *children[26];
};
TrieNode *getNode(){
    TrieNode *pNode =  new TrieNode();
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
    return pNode;
}
void insert(TrieNode *root, string key){
    TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
}

bool search(TrieNode *root, string key){
    TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return true;
}
class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        TrieNode *root = getNode();
        for(auto str:s1){
            insert(root,str);
            reverse(str.begin(),str.end());
            insert(root,str);
        }
        int ans=0;
        for(auto str:s2){
            string rev=str;
            reverse(rev.begin(),rev.end());
            if(search(root,str) or search(root,rev)){
                ans++;
            }
        }
        return ans;
    }
};