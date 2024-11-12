class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
unordered_set<string> st(wordList.begin(), wordList.end());
  queue<pair<string, int>> q;
  q.push({beginWord, 1});
  st.erase(beginWord);

  while (!q.empty())
  {
    string word = q.front().first;
    int step = q.front().second;
    q.pop();
    for (int i = 0; i < word.size(); i++)
    {
      char orignal = word[i];
      for (char ch = 'a'; ch <= 'z'; ch++)
      {
        word[i] = ch;

        if (st.find(word) != st.end())
        {
          st.erase(word);
          q.push({word, step + 1});
        }
      }
      word[i] = orignal;
    }

    if (word == endWord)
      return step;
  }
  return 0;
    }
};