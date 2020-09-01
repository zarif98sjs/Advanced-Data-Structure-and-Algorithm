
/**

Maximum Flow Edmonds Karp
=========================

Description
-----------
Given a directed network G = (V, E) with edge capacity c: E->R.
The algorithm finds a maximum flow.

Complexity
----------
O(V * E^2)

Verified
--------
SPOJ POTHOLE

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
#define endl "\n"
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

/**

Edmonds Karp

0 based indexing

**/

struct EdmondsKarp
{
    typedef long long flow_type;

    int n, source, sink;
    vector<vector<int>> adj;
    vector<vector<flow_type>> cap;
    vector<int>parent;

    EdmondsKarp(int n) : n(n) , adj(n) , cap(n,vector<flow_type>(n,0)) , parent(n) {}

    void add_edge(int src,int dst,flow_type capacity)
    {
        adj[src].push_back(dst);
        adj[dst].push_back(src); /// adding this edge for reverse graph
        cap[src][dst] += capacity; /// using += for being in safezone for duplicate edges
    }

    flow_type bfs(int u , flow_type amount)
    {
        fill(ALL(parent),-1);

        queue<pair<int,flow_type>>q;

        q.push({u,amount});

        while(!q.empty())
        {
            u = q.front().F;
            flow_type sent = q.front().S;

            q.pop();

            for(int v:adj[u])
            {
                if(parent[v] == -1 && cap[u][v]>0) /// not visited yet and available capacity
                {
                    parent[v] = u;
                    flow_type new_sent = min(sent,cap[u][v]);
                    q.push({v,new_sent});

                    if(v==sink) return new_sent;
                }
            }
        }

        return 0;
    }

    void update_path(flow_type sent)
    {
        int cur = sink;

        while(cur != source)
        {
            int prev = parent[cur];
            cap[prev][cur] -= sent;
            cap[cur][prev] += sent;

            cur = prev;
        }
    }

    flow_type max_flow(int source,int sink)
    {
        this->source = source;
        this->sink = sink;

        flow_type MAXFLOW = 0;
        flow_type sent = -1;

        while(sent != 0)
        {
            sent = bfs(source,LLONG_MAX);
            if(sent) update_path(sent);
            MAXFLOW += sent;
        }

        return MAXFLOW;

    }
};

int main()
{
    optimizeIO();

    int nodes;
    cin>>nodes;

    EdmondsKarp ek(nodes);

    int edges;
    cin>>edges;

    while(edges--)
    {
        int a,b;
        LL cap;
        cin>>a>>b>>cap;

        a-- , b--; /** making 0 based indexing **/

        ek.add_edge(a,b,cap);
    }

    LL MAXFLOW = ek.max_flow(0,nodes-1);
    cout<<MAXFLOW<<endl;

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
    for(T i:v)
    {
        os<<i<<" " ;
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
