
/**

Diameter of a Tree (using BFS)

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#endif

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;

vector<int>adj[nmax];

PII bfs(int s,int n)
{
    vector<bool>vis(n+1,false);
    vector<int>d(n+1,0);

    queue<int>q;
    vis[s] = true;
    d[s] = 0;
    q.push(s);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(int next:adj[now])
        {
            if(!vis[next])
            {
                vis[next] = true;
                d[next] = d[now] + 1;
                q.push(next);
            }
        }
    }

    int mx = 0 , mx_id = -1;

    for(int i=1;i<=n;i++)
    {
        if(d[i]>mx)
        {
            mx = d[i];
            mx_id = i;
        }
    }

    return {mx,mx_id};
}

int diameter(int n)
{
    PII a  = bfs(1,n);
    PII b  = bfs(a.S,n);

    return b.F;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    cout<<diameter(n)<<endl;


    return 0;
}

/**

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


