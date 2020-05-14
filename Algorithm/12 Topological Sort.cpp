
/**

Topological Sort using DFS

Note : TopSort only works with DAG

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

const int nmax = 1e5+7;
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
bool visited[nmax];
stack<int>stk;

void dfs(int node)
{
    visited[node]=true;

    for(int next:adj[node])
    {
        if(!visited[next])
            dfs(next);
    }

    stk.push(node);
}

void init()
{
    for(int i=0; i<nmax; i++)
        adj[i].clear();

    fill(visited,visited+nmax,false);

    while(!stk.empty())
        stk.pop();

}

int main()
{
    //freopen("out.txt","w",stdout);

    init();

    int nodes,edges;
    scanf("%d %d",&nodes,&edges);

    for(int j=1; j<=edges; j++)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        adj[a].push_back(b); /** Directed Acyclic Graph (DAG) **/
    }

    for(int j=1; j<=nodes; j++)
        if(!visited[j])
            dfs(j);

    cout<<"Topsort : ";

    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }

    return 0;
}


