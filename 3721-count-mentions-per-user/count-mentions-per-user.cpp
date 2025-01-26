class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [] (auto e1, auto e2) { 
            if(stoi(e1[1]) == stoi(e2[1]))
            return e1[0][0] > e2[0][0];   
            
            return stoi(e1[1]) < stoi(e2[1]);  
             
        }); 
        vector<int>offlineId(numberOfUsers,-1);
        vector<int>methods(numberOfUsers,0);
        for(auto& it : events){
        string type = it[0];
        int timeStrap = stoi(it[1]);
        string methodId = it[2];

        if(type=="OFFLINE"){
        int id = stoi(methodId);
        offlineId[id] = 60 + timeStrap;
        }

        if(type=="MESSAGE"){

        if(methodId=="HERE"){
            for(int i=0; i<numberOfUsers; i++){
            if(offlineId[i]<=timeStrap) methods[i]++;
            }
        }else if(methodId=="ALL"){
            for(int i=0; i<numberOfUsers; i++) methods[i]++;
        }else {
            stringstream ss(methodId);
            string temp;
            while(getline(ss, temp, ' ')){
            int id = stoi(temp.substr(2));
            methods[id]++;
            }
        }
        }

    }
    return methods;
        
    }
};