class Solution {
public:
    bool upper(string word){
        for(char c : word){
            if(!isupper(c)) return false;
        }
        return true;
    }

    bool lower(string word){
        for(char c : word){
            if(!islower(c)) return false;
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        if (upper(word) || lower(word) || (isupper(word[0]) && lower(word.substr(1))))
            return true;
        else
            return false;
    }
};
