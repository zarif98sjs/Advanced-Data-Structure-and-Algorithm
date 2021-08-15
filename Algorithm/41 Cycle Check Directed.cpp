
/**

Cycle check (Directed Graph)
===========

White : Not visited yet
Grey  : Visited , but not done with all neighbors
Black : Done

A directed graph has cycle if it visits a grey node

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
vector<int>col(nmax,0);

bool hasCycle(int u)
{
    col[u] = 1; /** grey **/

    for(int next:adj[u])
    {
        if(col[next]==0)
        {
            if(hasCycle(next))
                return true;
        }
        else if(col[next]==1)
            return true;
    }

    col[u] = 2; /** black **/

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
    }

    bool ok = false;

    for(int i=1;i<=n;i++)
    {
        if(col[i]==0)
        {
            if(hasCycle(i))
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


