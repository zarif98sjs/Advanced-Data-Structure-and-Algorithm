
/**

Given 2 nodes per query : find the minimum weight in their path

Note :
1. Input is a tree
2. No update

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

const int nmax = 3e5+7;

vector<vector<int>>adj;

vector<int>parent;
vector<int>L;
vector<int>dist;
map<PII,int>cost;

int sptable[nmax][20]; /** adjust 2nd dimension according to log of nmax **/
int D_sptable[nmax][20]; /// this is to store the minimum values of all the paths

void dfs(int u,int par,int lvl)
{
    parent[u] = par;
    L[u] = lvl;

    if(par!=-1) dist[u] = dist[par] + 1;

    for(int v:adj[u])
    {
        if(v!=par)
            dfs(v,u,lvl+1);
    }
}

void lca_init(int n)
{
    memset(sptable,-1,sizeof sptable);

    for(int i=1; i<=n; i++)
        sptable[i][0] = parent[i];

    for(int j=1; (1<<j)<n; j++)
        for(int i=1; i<=n; i++)
            if(sptable[i][j-1]!=-1)
                sptable[i][j] = sptable[sptable[i][j-1]][j-1];

    memset(D_sptable,-1,sizeof D_sptable);

    for(int i=1; i<=n; i++)
        D_sptable[i][0] =

    for(int j=1; (1<<j)<n; j++)
        for(int i=1; i<=n; i++)
            if(D_sptable[i][j-1]!=-1)
                D_sptable[i][j] = min(D_sptable[i][j-1],D_sptable[sptable[i][j-1]][j-1]);
}

int lca_query(int u,int v)
{
    if(L[u]<L[v])
        swap(u,v);

    int dis = L[u] - L[v];

    int log;
    for(log = 1; (1<<log)<=L[u]; log++);
    log--;

    ///making the levels same
    for(int i=log; i>=0; i--)
        if(dis &(1<<i))
            u = sptable[u][i];

    if(u==v)
        return u;

    for(int i=log; i>=0; i--)
        if(sptable[u][i]!=-1 && sptable[v][i]!=-1 && sptable[u][i]!=sptable[v][i])
        {
            u = sptable[u][i];
            v = sptable[v][i];
        }

    return parent[u];
}

int Distance(int a,int b)
{
    return dist[a] + dist[b] - 2*dist[lca_query(a,b)];
}

int Lift(int node,int level) /// lift the node up by this many level and query
{
    int log;
    for(log = 1; (1<<log)<=L[node]; log++);
    log--;

    int mn = INT_MAX;

    for(int i=log; i>=0; i--)
        if(level&(1<<i))
            mn = min(mn,D_sptable[node][i]) ,node = sptable[node][i];

    return mn;
}

int min_query(int u,int v)
{
    int lca = lca_query(u,v);

    int d_ul = Distance(u,lca);
    int d_vl = Distance(v,lca);

    int mn1 = Lift(u,d_ul);
    int mn2 = Lift(v,d_vl);

    return min(mn1,mn2);
}

void INIT(int len)
{
    adj = vector<vector<int>>(len);
    parent = vector<int>(len);
    L = vector<int>(len);
    dist = vector<int>(len);
}

int main()
{
    optimizeIO();

    int n,m;
    cin>>n>>m;

    INIT(n+1);

    for(int i=1; i<=m; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;

        adj[u].push_back(v);
        adj[v].push_back(u);

        cost[{u,v}] = c;
        cost[{v,u}] = c;
    }

    /** PRE-WORK **/
    dfs(1,-1,0);
    lca_init(n);

    int q;
    cin>>q;

    while(q--)
    {
        int node_a, node_b;
        cin>>node_a>>node_b;

        int ans = min_query(node_a,node_b);
        cout<<ans<<endl;
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
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
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
