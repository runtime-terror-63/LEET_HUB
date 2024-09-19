class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>result;
        int len = expression.size();
        char c;
        for(int i = 0; i<len; i++){
            c = expression[i];


            
            //take  and rec call
            if(c=='+' || c=='-' || c=='*'){

            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int>right = diffWaysToCompute(expression.substr(i+1));


                for(auto l : left){
                    for(auto r : right){
                        if(c=='+') result.push_back(l+r);
                        else if(c=='-') result.push_back(l-r);
                        else if(c=='*') result.push_back(l*r);
                    }
                }
            }
        }

        //not take is all are numbers and there is no any expression 
        if(result.empty()) result.push_back(stoi(expression));

        return result;
    }
};