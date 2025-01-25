class Solution {
public:
vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies){
  unordered_map<string, int> uniq_id;
  int id = 0;
  for (auto &it : favoriteCompanies)
  {
    for (auto &val : it)
    {
      if (uniq_id.find(val) == uniq_id.end())
        uniq_id[val] = id++;
    }
  }

  vector<set<int>> companyInteger;
  for (auto &it : favoriteCompanies)
  {
    set<int> integer;
    for (auto &val : it)
    {
      integer.insert(uniq_id[val]);
    }
    companyInteger.push_back(integer);
  }
//    for (auto it : companyInteger)
//    {
//      cout << "[ ";
//      for (auto val : it)
//        cout << val << " ";
//      cout << "]";
//    }
//    cout << endl;
  vector<int> ans;
  // sort(companyInteger.begin(), companyInteger.end());
  for (int i = 0; i < companyInteger.size(); i++){
    bool f = false;
    for (int j = 0; j < companyInteger.size(); j++){
      if (i != j && includes(companyInteger[j].begin(), companyInteger[j].end(), companyInteger[i].begin(), companyInteger[i].end())){
        f = true;
        break;
      }
    }
    if (!f)
      ans.push_back(i);
  }
 return ans;
}
};