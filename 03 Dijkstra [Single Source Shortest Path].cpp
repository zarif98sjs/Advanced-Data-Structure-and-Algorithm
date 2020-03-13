
/**

Complexity : O(ElogV)

Note : No guarantee of working with negative weight , does not work with negative cycle either

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
const int INF = 1e9;
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

int n,m;

vector<PII>adj[nmax];
vector<int>dist(nmax,INF);
vector<int>par(nmax,-1);

void dijkstra(int s)
{
    priority_queue< PII,vector<PII>,greater<PII> >PQ;
    dist[s] = 0;
    PQ.push({0,s});

    while(!PQ.empty())
    {
        int now = PQ.top().S;
        PQ.pop();

        for(auto x:adj[now])
        {
            int next = x.F;
            int ed = x.S;

            if(dist[now] + ed < dist[next])
            {
                dist[next] = dist[now] + ed;
                par[next] = now;
                PQ.push({dist[next],next});
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout<<i<<" -> "<<dist[i]<<endl;

}

void get_sp(int s,int t)
{
    vector<int>path;
    path.push_back(t);

    while(par[t]!=-1)
    {
        path.push_back(par[t]);
        t = par[t];
    }

    reverse(ALL(path));

    for(int x:path)
        cout<<x<<" ";
    cout<<endl;
}

int main()
{
    optimizeIO();

    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        adj[a].push_back({b,w});  /** Directed **/
        //adj[b].push_back({a,w});
    }

    while(true)
    {
        int v;
        cin>>v;
        dijkstra(v);
        get_sp(v,n);

    }



    return 0;
}


