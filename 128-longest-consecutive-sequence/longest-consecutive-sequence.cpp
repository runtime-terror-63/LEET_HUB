
const int M=1e5;
class Solution {
public:
    
    int rank[M],parent[M];
    void fun(int x,int y)
    {
        parent[x]=y;
    }
    int loge(int x)
    {
        if(x==parent[x])
            return 1;
        if(rank[x]!=1)
         return rank[x];
        
        return rank[x]=(1+loge(parent[x]));
    }
    int longestConsecutive(vector<int>& v) {
        int n=v.size();
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            rank[i]=1;
            parent[i]=i;
            mp[v[i]]=i;
        }
        for(auto num:v)
        {
            
            if(mp.count(num-1)!=0)
            {
                fun(mp[num],mp[num-1]);
                // rank[mp[num-1]]+=rank[mp[num]];
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,loge(i));
        }
        return  ans;
        
    }
};