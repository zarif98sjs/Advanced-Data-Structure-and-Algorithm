
/**

Given 2 nodes per query : find the minimum & maximum weight in their path
Note :
1. Input is a tree
2. No update

Reference Problem : LightOj 1162

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

const int nmax = 1e5+7;

vector<vector<PII>>adj;

vector<PII>parent;
vector<int>L;

int sptable[nmax][17]; /** adjust 2nd dimension according to log of nmax **/
int minD_sptable[nmax][17]; /// this is to store the minimum values of all the paths
int maxD_sptable[nmax][17]; /// this is to store the minimum values of all the paths

void dfs(int u,int par,int lvl)
{
    parent[u].F = par;
    L[u] = lvl;

    for(PII next:adj[u])
    {
        int v = next.F;

        if(v!=par)
        {
            parent[v].S = next.S; /// the edge weight to parent
            dfs(v,u,lvl+1);
        }
    }
}

void lca_init(int n)
{
    memset(sptable,-1,sizeof sptable);

    for(int i=1; i<=n; i++)
        sptable[i][0] = parent[i].F; /// 2^0 th parent

    for(int j=1; (1<<j)<n; j++)
        for(int i=1; i<=n; i++)
            if(sptable[i][j-1]!=-1)
                sptable[i][j] = sptable[sptable[i][j-1]][j-1];

    memset(minD_sptable,-1,sizeof minD_sptable);

    for(int i=1; i<=n; i++)
        minD_sptable[i][0] = parent[i].S; /// 2^0 th parent's edge weight

    for(int j=1; (1<<j)<n; j++)
        for(int i=1; i<=n; i++)
            if(minD_sptable[i][j-1]!=-1)
                minD_sptable[i][j] = min(minD_sptable[i][j-1],minD_sptable[sptable[i][j-1]][j-1]);

    memset(maxD_sptable,-1,sizeof maxD_sptable);

    for(int i=1; i<=n; i++)
        maxD_sptable[i][0] = parent[i].S; /// 2^0 th parent's edge weight

    for(int j=1; (1<<j)<n; j++)
        for(int i=1; i<=n; i++)
            if(maxD_sptable[i][j-1]!=-1)
                maxD_sptable[i][j] = max(maxD_sptable[i][j-1],maxD_sptable[sptable[i][j-1]][j-1]);
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

    return parent[u].F;
}

int Distance(int a,int b)
{
    return L[a] + L[b] - 2*L[lca_query(a,b)];
}

PII Lift(int node,int level) /// lift the node up by this many level and query
{
    int log;
    for(log = 1; (1<<log)<=L[node]; log++);
    log--;

    int mn = INT_MAX;
    int mx = 0;

    for(int i=log; i>=0; i--)
        if(level&(1<<i))
        {
            mn = min(mn,minD_sptable[node][i]);
            mx = max(mx,maxD_sptable[node][i]);
            node = sptable[node][i];
        }


    return {mn,mx};
}

PII min_max_query(int u,int v)
{
    int lca = lca_query(u,v);

    int d_ul = Distance(u,lca);
    int d_vl = Distance(v,lca);

    PII p1 = Lift(u,d_ul);
    PII p2 = Lift(v,d_vl);

    return {min(p1.F,p2.F),max(p1.S,p2.S)};
}

void INIT(int len)
{
    adj = vector<vector<PII>>(len);
    parent = vector<PII>(len);
    L = vector<int>(len);
}

int main()
{
    optimizeIO();

    int tc;
    scanf("%d",&tc);

    int cs = 0;

    while(tc--)
    {
        printf("Case %d:\n",++cs);

        int n;
        scanf("%d",&n);

        INIT(n+1);

        int m = n-1;

        for(int i=1; i<=m; i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);

            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }

        /** PRE-WORK **/
        dfs(1,-1,0);
        lca_init(n);

        int q;
        scanf("%d",&q);

        while(q--)
        {
            int node_a, node_b;
            scanf("%d %d",&node_a,&node_b);

            PII ans = min_max_query(node_a,node_b);
            printf("%d %d\n",ans.F,ans.S);
        }
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
