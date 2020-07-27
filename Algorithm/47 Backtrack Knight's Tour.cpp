
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

const int nmax = 2e2+7;

int vis[nmax][nmax];
#define N 6

//vector<int> dx = {+1,-1,+1,-1,-2,-2,+2,+2};
//vector<int> dy = {-2,-2,+2,+2,+1,-1,+1,-1};

/// the order in which the knight will move is circular and will be optimum
vector<int> dx = { 2, 1, -1, -2, -2, -1,  1,  2 , 2 };
vector<int> dy = { 1, 2,  2,  1, -1, -2, -2, -1, 1 };

bool ok(int x,int y)
{
    if(x>=0 && x<N && y>=0 &&y<N)
        return true;
    return false;
}

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << vis[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void dfs(int x,int y,int num)
{
    vis[x][y] = num;

    if(num>=N*N)
    {
        printBoard();
        vis[x][y] = 0;
        return;
    }

    for(int i=0;i<8;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(ok(nx,ny) && vis[nx][ny]==0)
        {
            dfs(nx,ny,num+1);
        }
    }

    vis[x][y] = 0;
}

int main()
{
    optimizeIO();

    dfs(0,0,1);

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


