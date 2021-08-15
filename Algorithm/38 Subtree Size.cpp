
/**

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

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

vector<int>adj[nmax];
int sub[nmax]; /** subtree size **/

void dfs(int u,int p)
{
    sub[u] = 1;

    for(int next:adj[u])
    {
        if(next==p)
            continue;

        dfs(next,u);

        sub[u] += sub[next];
    }
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

    while(true)
    {
        int v;
        cin>>v; /** root **/

        memset(sub,0,sizeof sub);

        dfs(v);
    }

    return 0;
}


