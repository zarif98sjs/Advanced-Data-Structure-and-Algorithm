
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;

struct Graph
{
    int n,m;
    bool dir;
    vector<vector<int>>adj;
    vector<int>sz;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);
        sz = vector<int>(len);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void dfs(int u,int p,vector<int>&centroids)
    {
        bool isCentroid = true;

        sz[u] = 1;
        for(int v:adj[u])
        {
            if(v==p)
                continue;

            dfs(v,u,centroids);

            sz[u] += sz[v];

            if(sz[v] > n/2) isCentroid = false; /// considering all the component rooted at children
        }

        if(n-sz[u] > n/2) isCentroid = false; /// the one component rooted at the parent

        if(isCentroid) centroids.push_back(u);
    }

    vector<int> find_centroids()
    {
        vector<int>centroids;
        dfs(1,-1,centroids);

        return centroids;
    }
};

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;

        Graph g(n,false);

        int ed = n-1;
        while(ed--)
        {
            int a,b;
            cin>>a>>b;

            g.add_edge(a,b);
        }

        vector<int>centroids = g.find_centroids();
        DBG(centroids);
    }

    return 0;
}

/**

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}
