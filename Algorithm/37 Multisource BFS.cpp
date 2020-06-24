
/**

Multisource BFS
===============

Problem
-------

https://www.spoj.com/problems/BITMAP/

In short , given multiple source . Find for all other nodes , the shortest distance to a source .

Idea
----

Just Modify the BFS and start with multiple source in the queue.

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

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

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
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

string ara[200];
int dist[200][200];
bool vis[200][200];

vector<int>dx = {-1,0,1,0};
vector<int>dy = {0,1,0,-1};

bool isOk(int i,int j,int r,int c)
{
    if(i>=0 && i<r && j>=0 && j<c)
        return true;
    return false;
}

void multisourceBFS(const vector<PII> &src,int r,int c)
{
    queue<PII>q;

    for(auto x:src) q.push(x) , vis[x.F][x.S] = true;

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();
        int ux = u.F , uy = u.S;

        for(int i=0;i<4;i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(isOk(vx,vy,r,c)==false)
                continue;
            if(vis[vx][vy])
                continue;

            dist[vx][vy] = dist[ux][uy] + 1;
            vis[vx][vy] = true;
            q.push({vx,vy});
        }
    }

}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int r,c;
        cin>>r>>c;

        for(int i=0; i<r; i++)
            cin>>ara[i];

        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                dist[i][j] = 0 , vis[i][j] = false;

        vector<PII>src;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(ara[i][j] == '1')
                {
                    src.push_back({i,j});
                }
            }
        }

        multisourceBFS(src,r,c);

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
                cout<<dist[i][j]<<" ";
            cout<<endl;
        }

    }

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


