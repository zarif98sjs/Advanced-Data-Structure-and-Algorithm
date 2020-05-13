
/**

Lowest Common Ancestor

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e4+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

vector<int>adj[nmax];
map<PII,int>cost;
int parent[nmax];
int L[nmax];
int dist[nmax];
int sptable[nmax][15]; /** adjust 15 according to log of nmax **/

void dfs(int u,int par,int lvl)
{
    parent[u] = par;
    L[u] = lvl;

    if(par!=-1)
        dist[u] = dist[par] + cost[{par,u}];

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

int main()
{
    //freopen("OUT.txt","w",stdout);

    int n;
    cin>>n;

    for(int i=0; i<=n; i++)
    {
        adj[i].clear();
        dist[i] = 0;
    }

    for(int i=1; i<n; i++)
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

    int node_a , node_b;
    cin>>node_a>>node_b;

    int lca = lca_query(node_a,node_b); /** finding LCA **/
    cout<<"LCA : "<<lca<<endl;

    return 0;
}
