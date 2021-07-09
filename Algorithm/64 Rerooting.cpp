
/**

Re-rooting technique
====================

Reference problem : CF 1092 F
-----------------------------

s(u) = v(u) + Summation all s(child)
dp(u) = Summation all [ dp(child) + s(child) ]

**/

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

#define int long long

struct Graph
{
    int n;
    bool dir;
    vector<vector<int>>adj;

    vector<int>ara;
    vector<int>s;
    vector<int>dp;

    int ans = 0;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);

        ara = vector<int>(len);
        s = vector<int>(len);
        dp = vector<int>(len);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void init_s(int u,int p=-1)
    {
        s[u] = ara[u];

        for(int v:adj[u])
        {
            if(v!=p)
            {
                init_s(v,u);

                s[u] += s[v];
            }
        }
    }

    void init_dfs(int u,int p=-1)
    {
        dp[u] = 0;

        for(int v:adj[u])
        {
            if(v!=p)
            {
                init_dfs(v,u);

                dp[u] += dp[v];
                dp[u] += s[v];
            }
        }
    }

    void change_root(int old_root,int new_root)
    {
        /// removing new root's contribution
        s[old_root] -= s[new_root];
        dp[old_root] -= s[new_root];
        dp[old_root] -= dp[new_root];

        /// adding old root as a child of new root
        s[new_root] += s[old_root];
        dp[new_root] += s[old_root];
        dp[new_root] += dp[old_root];
    }

    void dfs(int u,int p=-1)
    {
        ans = max(ans,dp[u]);

        for(int v:adj[u])
        {
            if(v!=p)
            {
                change_root(u,v);

                dfs(v,u);

                change_root(v,u);
            }
        }
    }

    void solve()
    {
        init_s(1);
        init_dfs(1);
        dfs(1);
        cout<<ans<<endl;
    }
};

void solveTC()
{
    int n;
    cin>>n;

    Graph g(n,false);

    for(int i=1;i<=n;i++) cin>>g.ara[i];

    int m = n-1;

    while(m--)
    {
        int a,b;
        cin>>a>>b;

        g.add_edge(a,b);
    }

    g.solve();

}

int32_t main()
{
    optimizeIO();

    int tc = 1;
//    cin>>tc;

    while(tc--)
    {
        solveTC();
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

