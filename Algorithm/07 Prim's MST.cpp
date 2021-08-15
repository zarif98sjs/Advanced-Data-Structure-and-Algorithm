
/**

Complexity : O(ElogV)

Works fine with negative edges.

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

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e3+7;
const LL LINF = 1e17;

int nodes,edges;

vector<PII>adj[nmax];

LL MinST(int src = 1) /** n vertices , 1 based indexing **/
{
    priority_queue< PII,vector<PII>,greater <PII> >PQ;
    vector<bool>inMinST(nmax, false);
    vector<PII>parent(nmax,{-1,0});
    vector<int>min_d(nmax,INF); /** For maximum spanning tree , USE max_d(nmax,0) **/

    min_d[src] = 0;
    PQ.push({0,src});

    while(!PQ.empty())
    {
        int now=PQ.top().S;
        PQ.pop();

        inMinST[now] = true;

        for(auto x:adj[now])
        {
            int next = x.F;
            int weight = x.S;

            if(inMinST[next] == false && weight < min_d[next]) /** For maximum spanning tree ,  weight>max_d[next] **/
            {
                min_d[next] = weight;
                PQ.push(MP(min_d[next],next));
                parent[next] = MP(now,min_d[next]);
            }
        }
    }

    LL min_ans=0;

    for(int i=1;i<=nodes;i++)
        min_ans+=parent[i].S;

    return min_ans;
}


int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    cin>>nodes>>edges;

    for(int i=1;i<=edges;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    LL mininum_spanning_tree_value = MinST();

    cout<<mininum_spanning_tree_value<<endl;

    return 0;
}


