
/**

Cycle check (Directed Graph)
===========

Here the idea is to use TOP SORT .
After top sort , let the topological order be like this

A -> B -> C -> D

if there is an edge from A to D (i.e from lower position to higher position in topological order) , it won't create a cycle .
BUT if there is an edge from D to A (i.e from higher position to lower position in topological order) , it WILL create a cycle .

This is the core idea behind cycle checking here .

Idea
====

For each edge we check if it connects from higher position to lower position in topological order .
If we find one like this , there is a cycle

Complexity : O(V+E)

**/

/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

vector<vector<int>>adj;

vector<bool>vis;
vector<int>stk;
vector<int>pos;

void dfs(int u)
{
    vis[u] = true;

    for(int v:adj[u])
    {
        if(vis[v])
            continue;

        dfs(v);
    }

    stk.push_back(u);
}

bool hasCycle(int n,const vector<PII> &dir_edges)
{
    fill(ALL(vis),0);

    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);

    int cnt = 0;

    while(!stk.empty())
    {
        int now = stk.back();
        stk.pop_back();
        pos[now] = ++cnt;
    }

    for(auto e:dir_edges)
    {
        int u = e.F , v = e.S;

        if(pos[u]>pos[v]) /** edge is from RIGHT to LEFT in the topological order and that's why creating cycle **/
            return true;
    }

    return false;
}

void RESIZE(int n)
{
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    pos = vector<int>(n);
    stk.clear();
}

int main()
{
    optimizeIO();

    int n,m;
    cin>>n>>m;

    RESIZE(n+1);

    vector<PII>dir_ed;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        dir_ed.push_back({a,b});
    }

    bool cycle = hasCycle(n,dir_ed);

    if(cycle) cout<<"Has Cycle"<<endl;
    else cout<<"No Cycle"<<endl;

    return 0;
}


