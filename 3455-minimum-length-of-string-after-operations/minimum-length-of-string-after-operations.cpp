class Solution {
public:
    int minimumLength(string s) {
         unordered_map<char,int>mp;
     int ans=s.length();
     for(int i=0;i<s.length();i++){
        mp[s[i]]++;
        if(mp[s[i]]>2){
            mp[s[i]]=1;
            ans-=2;
}
     }
     return ans;
    }
};