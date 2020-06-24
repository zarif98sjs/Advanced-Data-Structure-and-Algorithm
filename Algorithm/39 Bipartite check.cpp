
/**

Bipartite / Bicolorable / Odd cycle existence chceck
====================================================

A graph is bipartite if
1. It is bicolorable
2. It doesn't contain any odd cycle

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

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

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

//bool cmp(const PII &A,const PII &B)
//{
//
//}

vector<int>adj[nmax];
vector<bool>vis(nmax,false);
vector<bool>col(nmax,0);

bool isBipartite(int u)
{
    vis[u] = true;

    for(int next:adj[u])
    {
        if(!vis[next])
        {
            col[next] = !col[u];

            if(isBipartite(next)==false)
                return false;
        }
        else if(col[next]==col[u])
            return false;
    }

    return true;
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


    int v;
    cin>>v; /** root **/
    cout<<"Is Bipartite ? : "<<isBipartite(v)<<endl;

    /**

    Here for the sake of simplicity , we considered 1 connected component .
    A graph is bipartite if all of the components are bipartite .

    **/

    return 0;
}


