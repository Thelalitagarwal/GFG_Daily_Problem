class Solution
{
    public:
    char nonrepeatingCharacter(string S)
    {
      
      unordered_map<char,int>mp;
      for( auto c: S) mp[c]++;
   
      for(auto c: S){
          if(mp[c]==1) return c;
      }
      
      return '$';
       
    }

};