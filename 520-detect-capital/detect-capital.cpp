class Solution {
public:
    bool upper(string word){
        for(auto it : word){
            if(!isupper(it)) return false;
        }
      return true;
    }
    bool lower(string word){
        for(auto it : word){
            if(!islower(it)) return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(upper(word) || lower(word) || (isupper(word[0]) && lower(word.substr(1)))) return true;
        else return false;
    }
};