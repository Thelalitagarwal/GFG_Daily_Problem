class Solution{
public:
    unordered_map<string ,int>mp;
    int ans;
    string solve(Node *root){
        if(root==NULL)return "";
        string temp="";
        for(auto it:root->children){
            temp=temp + solve(it);
        }
        temp+=to_string(root->data);
        temp =temp+"#";
        mp[temp]++;
        //cout<<temp<<endl;
        return temp;
        
    }
    int duplicateSubtreeNaryTree(Node *root){
        // Code here
        ans=0;
        mp.clear();
        solve(root);
        for(it:mp){
            if(it.second!=1)
            ans++;
            //cout<<it.second<<" ";
        }
        return ans;

}
};