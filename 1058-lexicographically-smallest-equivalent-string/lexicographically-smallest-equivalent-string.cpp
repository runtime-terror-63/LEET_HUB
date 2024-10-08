#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1); // Initialize size to 1 for all nodes
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int x, int y) {
        int rootX = findUPar(x);
        int rootY = findUPar(y);

        if (rootX != rootY) {
            // Union by size
            if (size[rootX] > size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY]; // Update size
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX]; // Update size
            }
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26); 

        
        for (int i = 0; i < s1.size(); i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a'; 
            ds.unionBySize(u, v);
        }

       
        vector<char> smallest(26);
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int root = ds.findUPar(ch - 'a');
            
            if (smallest[root] == 0 || ch < smallest[root]) {
                smallest[root] = ch;
            }
        } 

       
        string result = "";
        for (char c : baseStr) {
            int root = ds.findUPar(c - 'a');
            result += smallest[root]; 
        }

        return result;
    }
};