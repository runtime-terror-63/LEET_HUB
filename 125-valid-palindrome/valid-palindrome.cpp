class Solution {
    private:
bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    return 0;
}

    
char tolower(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
    
    
bool palindrome(string str)
{
    int s = 0;
    int e = str.length()-1;
    while (s <= e)
    {
        if (str[s] != str[e])
        {

            return 0;
        }
        else
        {
            s++;
            e--;
        
        }
    }
    return 1;
}
public:
    bool isPalindrome(string s) {
          //int i = 0;
    string temp = "";
    for (int j = 0; j < s.length(); j++)
    {
        if (valid(s[j]))
        {
           temp.push_back(s[j]);
           // temp[i] = s[j];
        }
    }

    for (int j = 0; j < temp.length(); j++)
    {
        temp[j] = tolower(temp[j]);
    }
    return palindrome(temp);
    }
};
