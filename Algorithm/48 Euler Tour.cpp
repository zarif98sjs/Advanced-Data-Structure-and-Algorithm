
/**

Euler Circuit / Euler Cycle (Undirected graph)
===========================
All edges are traversed only once . Starting & Ending Point same.

Condition : All vertices will have EVEN degree .

Euler Path
==========
All edges are traversed only once . Starting & Ending Point different.

Condition : All vertices except the 2 endpoints will have EVEN degree .



Hierholzer's algorithm for finding Euler Circuit
=================================================
https://www.wikiwand.com/en/Eulerian_path#/Hierholzer.27s_algorithm

How to modify the same algorithm to find Euler Path ?
=> Add an edge between the 2 endpoints and find Euler Circuit

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

vector<set<int>>adj;
vector<int>deg;
vector<int>tour;

void eulerDFS(int u)
{
    while(!adj[u].empty())
    {
        int v = *adj[u].begin();

        adj[u].erase(v);
        adj[v].erase(u);

        eulerDFS(v);
    }

    tour.push_back(u);
}

bool check(int n) /// check if Euler Circuit Exists
{
    for(int i=1;i<=n;i++)
        if(deg[i]&1)
            return false;

   return true;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,m;
        cin>>n>>m;

        adj = vector<set<int>>(n+1);
        deg = vector<int>(n+1);
        tour.clear();

        while(m--)
        {
            int a , b;
            cin>>a>>b;

            adj[a].insert(b);
            adj[b].insert(a);

            deg[a]++;
            deg[b]++;
        }

        if(check(n)==false) cout<<"Euler Circuit doesn't exist"<<endl;
        else
        {
            eulerDFS(1);

            reverse(ALL(tour));
            cout<<"Euler Circuit : "<<tour<<endl;
        }
    }

    return 0;
}

/**
7 8
1 4
1 2
2 3
3 7
3 5
3 4
5 6
6 7
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


