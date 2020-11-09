
/**
 * Tree Flattening
 * ---------------
 * The subtree of v can be found in the range st[v] ...  en[v]
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

    void tree_flatten(int u,int p)
    {
        st[u] = ++timer;

        for(int v:adj[u])
        {
            if(v==p) continue;

            tree_flatten(v,u);
        }

        en[u] = timer;
    }

    void pre()
    {
        tree_flatten(1,-1);

        // update the data structure data from the flattened tree
        // build
    }
};
