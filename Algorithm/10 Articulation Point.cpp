
/**

Articulation Point

Complexity : O(N+M)

Resources:
1 ) http://www.shafaetsplanet.com/?p=2504
2 ) https://cp-algorithms.com/graph/cutpoints.html

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

const int nmax = 2e4+7;
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
vector<bool>visited;

vector<int> discov; /** Discovery time in DFS **/
vector<int> low; /** min(all discovery time of subtree of a vertex u including the back-edge ancestors) **/
vector<bool> isArticulationPoint;
int timer;

void initialize()
{
    timer = 0;
    visited.assign(nmax,false);
    discov.assign(nmax,-1);
    low.assign(nmax,-1);
    isArticulationPoint.assign(nmax,false);

    for(int i=0;i<nmax;i++)
        adj[i].clear();
}

void dfs(int v,int p)
{
    visited[v] = true;
    discov[v] = low[v] = timer++;
    int child = 0;

    for(int next:adj[v])
    {
        child++;

        if(next==p)
            continue;
        if(visited[next])
            low[v] = min(low[v],discov[next]);
        else
        {
            dfs(next,v);
            low[v] = min(low[v],low[next]);

            if(child>1 && p==-1) isArticulationPoint[v] = true; /** ROOT **/

            if(discov[v]<low[next] && p!=-1) isArticulationPoint[v] = true;
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    initialize();

    int n,m;
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
            dfs(i,-1);
    }

    int articulationPoint = 0;

    for(int i=1; i<=n; i++)
    {
        if(isArticulationPoint[i])
            articulationPoint++;
    }

    cout<<"Number of Articulation Point : "<<articulationPoint<<endl;

    return 0;
}


