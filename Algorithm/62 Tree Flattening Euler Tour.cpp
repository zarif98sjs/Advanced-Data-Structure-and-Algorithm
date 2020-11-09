
/**
 * Tree Flattening Euler Version
 * -----------------------------
 * Each node has 2 position in the newly built array : 1 in the starting time and 1 in the ending time
 *
 * This type of flattening is important when doing path queries in trees .
 * We can only do path queries for those operations only which can be done and undone like sum , XOR etc
 *
 * In the starting time index we do the operation
 * and in the ending time index we undo the operation
 */

#include<bits/stdc++.h>
using namespace std;

struct Graph
{
    int n;
    bool dir;
    vector<vector<int>>adj;

    // tree flatten
    vector<int>st,en;
    int timer = 0;

    //Queries

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);

        st = vector<int>(len);
        en = vector<int>(len);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void euler(int u,int p)
    {
        st[u] = ++timer;

        for(int v:adj[u])
        {
            if(v==p) continue;

            euler(v,u);
        }

        en[u] = ++timer;
    }

    void pre()
    {
        euler(1,-1);

        // update the data structure data from the flattened tree
        // build
    }
};
