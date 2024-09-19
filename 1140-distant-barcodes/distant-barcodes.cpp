class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
         vector<int>ans;
         if(barcodes.size() == 0 || barcodes.size() == 1)
        return barcodes;
        unordered_map<int, int>mpp;
        for(auto it : barcodes) mpp[it]++;

        priority_queue<pair<int, int>>pq;
        for(auto it : mpp) pq.push({it.second, it.first});

       
        while(pq.top().first > 0) {
            pair<int, int> first = pq.top();
            pq.pop();
            int node = first.second;

            ans.push_back(node);
            first.first--;

            pair<int, int> sec = pq.top();
            pq.pop();
            if(sec.first > 0){
                ans.push_back(sec.second);
                sec.first--;
            }
            pq.push(first);
            pq.push(sec);
        }
return ans;
       

    }
};