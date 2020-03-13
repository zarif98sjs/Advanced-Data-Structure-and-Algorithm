
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


struct edge
{
    int a,b,w;
};

int n,m;
vector<edge>e;

void bellman_ford(int s)
{
    vector<int>dist(nmax,INF);
    bool is_negcycle;

    dist[s] = 0;

    for(int i=0; i<n; i++) /** n-1 + 1 times , last 1 time is to check if there is a negative weight cycles **/
    {
        is_negcycle = false;

        for(int j=0; j<m; j++)
        {
            if(dist[e[j].a]<INF)
            {
                if(dist[e[j].a] + e[j].w < dist[e[j].b])
                {
                    dist[e[j].b] = max(-INF, dist[e[j].a] + e[j].w);
                    is_negcycle = true; /** if there is a relaxation in nth iteration this will become true **/
                }
            }
        }
    }

    if(is_negcycle)
    {
        cout<<"Negative Cycle Exists"<<endl;
    }

    for(int i=1; i<=n; i++)
        cout<<i<<" -> "<<dist[i]<<endl;
}

int main()
{
    optimizeIO();

    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        e.push_back({a,b,w}); /** Directed **/
        //e.push_back({b,a,w});
    }

    while(true)
    {
        int v;
        cin>>v;
        bellman_ford(v);
    }



    return 0;
}


