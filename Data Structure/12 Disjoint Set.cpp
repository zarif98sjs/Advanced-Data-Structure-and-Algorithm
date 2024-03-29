
/**

Disjoint Set
============

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

/**
 * 
 * Disjoint Set 
 * 1 based indexing
 * 
 **/

struct DisjointSet
{
    unordered_map<int, int> parent;
    vector<int>sz;
    int comp;

    vector<vector<int>>g; /// extra part

    void makeSet(int N)
    {
        sz = vector<int>(N+1,1);
        g = vector<vector<int>>(N+1); /// extra part

        for (int i = 1; i <= N; i++)
            parent[i] = i, g[i].push_back(i);

        comp = N;
    }

    int Find(int k)
    {
        // if k is root
        if (parent[k] == k)
            return k;

        return parent[k] = Find(parent[k]);
    }

    void Union(int a, int b)
    {
        int x = Find(a);
        int y = Find(b);

        if(x==y) return;

        /**
            merge is done according to size
            if we do that, when we maintain adjacency list, we can merge small to large component
            this optimizes the union process
        **/

        if(sz[x] < sz[y]) swap(x,y);

        sz[x] += sz[y];
        parent[y] = x;

        /// extra part
        g[x].insert(g[x].end(), ALL(g[y]));
        g[y].clear();

        comp--;
    }

    void printParent(int N)
    {
        for (int i = 1; i <= N; i++)
            cout<<parent[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    DisjointSet ds;

    ds.makeSet(10);

    ds.Union(1,2);
    ds.Union(2,5);
    ds.Union(5,10);
    ds.Union(3,4);

    for(int i=1;i<=10;i++)
        cout<<"Component of "<<i<<" : "<<ds.Find(i)<<endl;

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


