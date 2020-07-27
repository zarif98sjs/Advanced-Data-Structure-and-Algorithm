
/**

Cycle check (Undirected Graph)
===========

White : Not visited yet
Grey  : Visited , but not done with all neighbors
Black : Done

An undirected graph has cycle if it visits a node twice (except it's parent)
(If it is visited more than once , then there is 2 paths to reach this vertex i.e cycle in undirected graph)

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

vector<int>adj[nmax];
vector<bool>vis(nmax,false);

bool hasCycle(int u,int p)
{
    vis[u] = true;

    for(int next:adj[u])
    {
        if(!vis[next])
        {
            if(hasCycle(next,u))
                return true;
        }
        else if(next!=p)
            return true;
    }

    return false;
}

int main()
{
    optimizeIO();

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool ok = false;

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(hasCycle(i,-1))
            {
                ok = true;
                break;
            }
        }
    }

    if(ok) cout<<"Has Cycle"<<endl;
    else cout<<"No Cycle"<<endl;

    return 0;
}


