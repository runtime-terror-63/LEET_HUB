class DisjointSet
{
  vector<int> parent, size;

public:
  DisjointSet(int n)
  {
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int findUPar(int node)
  {
    if (parent[node] == node)
      return parent[node];
    return parent[node] = findUPar(parent[node]);
  }

  void unionBySize(int u, int v)
  {
    int root_u = findUPar(u);
    int root_v = findUPar(v);
    if(root_u==root_v) return ;
    if (size[root_u] < size[root_v])
    {
      parent[root_u] = root_v;
      size[root_v] += size[root_u];
    }
    else
    {
      parent[root_v] = root_u;
      size[root_u] += size[root_v];
    }
  }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
          int n = accounts.size();
  unordered_map<string, int> emailAc;
  DisjointSet ds(n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j < accounts[i].size(); j++)
    {
      string email = accounts[i][j];
      if (emailAc.find(email) != emailAc.end())
      {
        ds.unionBySize(i, emailAc[email]);
      }
      else
        emailAc[email] = i;
    }
  }

  unordered_map<int, vector<string>> mergeAc;
  for (auto &[email, accInd] : emailAc)
  {
    int rooAc = ds.findUPar(accInd);
    mergeAc[rooAc].push_back(email);
  }

  vector<vector<string>> result;
  for (auto &[accInd, email] : mergeAc)
  {
    vector<string> mergeAccount;
    mergeAccount.push_back(accounts[accInd][0]);
    sort(email.begin(), email.end());
    mergeAccount.insert(mergeAccount.end(), email.begin(), email.end());
    result.push_back(mergeAccount);
  }
  return result;
    }
};