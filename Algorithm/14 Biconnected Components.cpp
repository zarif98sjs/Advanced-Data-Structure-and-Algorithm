
/**

Biconnected Component

Complexity : O(N+M)

Resources:
1 ) https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/
2 ) https://www.geeksforgeeks.org/biconnected-components/

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
int timer;

stack<PII>stk;

void initialize()
{
    timer = 0;
    visited.assign(nmax,false);
    discov.assign(nmax,-1);
    low.assign(nmax,-1);

    for(int i=0; i<nmax; i++)
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
        {
            low[v] = min(low[v],discov[next]);

            if(discov[next]<discov[v]) /** IMP **/
                stk.push({v,next});
        }
        else
        {
//            cout<<v<<"..."<<next<<endl;
            stk.push({v,next}); /** pushing in stack **/
            dfs(next,v);
            low[v] = min(low[v],low[next]);

            if((child>1 && p==-1) || (discov[v]<=low[next] && p!=-1)) /** v is an Articulation Point **/
            {
                while(stk.top().F !=v || stk.top().S !=next) /** Until I get the {v-next} edge**/
                {
                    cout<<stk.top().F<<"-"<<stk.top().S<<" ";
                    stk.pop();
                }

                cout<<stk.top().F<<"-"<<stk.top().S<<endl;
                stk.pop();
            }
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

    for(int i=0; i<n; i++)
    {
        cout<<endl;

        if(!visited[i])
            dfs(i,-1);

        while(!stk.empty())
        {
            cout<<stk.top().F<<"-"<<stk.top().S<<" ";
            stk.pop();
        }
        cout<<endl;

    }

    return 0;
}

/**
6 6
0 3
3 2
2 5
4 2
4 5
4 1
**/



