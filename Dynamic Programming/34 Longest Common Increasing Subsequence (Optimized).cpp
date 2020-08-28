
/**

LCIS(Longest Common Increasing Subsequence)
===========================================

O(N^2) Optimization
-------------------

We can get rid of the pos2 state by adding a greedy approach

next_pos[pos1][last_pos2] = greedy next state from (pos1,last_pos2)
i.e next value in 2nd array to be the same as array1[pos1] which is situated after last_pos2

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

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

int n1,n2;
vector<int>v1,v2;
int dp[505][505];
int next_pos[505][505]; /// greedy next state from (pos1,last_pos2) i.e next value in 2nd array to be the same as array1[pos1] which is situated after last_pos2

int LCIS(int pos1,int last_pos2)
{
    if(pos1>n1 || last_pos2>n2) return 0;

    int &ret = dp[pos1][last_pos2];
    if(~ret) return ret;

    ret = 0;

    int np = next_pos[pos1][last_pos2];

    if(v1[pos1]>v2[last_pos2] && np<=n2)
    {
        ret = max(ret, 1 + LCIS(pos1+1,np));
    }

    ret = max(ret, LCIS(pos1+1,last_pos2));

    return ret;
}

void solveLCIS(int pos1,int last_pos2,vector<int>&vLCIS)
{
    if(pos1>n1 || last_pos2>n2) return;

    int np = next_pos[pos1][last_pos2];

    int way1 = INT_MIN, way2 = LCIS(pos1+1,last_pos2);

    if(v1[pos1]>v2[last_pos2] && np<=n2)
    {
        way1 =  1 + LCIS(pos1+1,np);
    }

    if(way1>=way2)
    {
        vLCIS.push_back(v2[np]);
        return solveLCIS(pos1+1,np,vLCIS);
    }
    else return solveLCIS(pos1+1,last_pos2,vLCIS);
}

int main()
{
    optimizeIO();


    cin>>n1;
    v1 = vector<int>(n1+2);
    for(int i=1;i<=n1;i++)
        cin>>v1[i];

    cin>>n2;
    v2 = vector<int>(n2+2);
    for(int i=1;i<=n2;i++)
        cin>>v2[i];
    v2[0] = INT_MIN; /// init

    for(int i=1;i<=n1;i++)
    {
        int last_sem = n2+1;
        for(int j=n2;j>=0;j--)
        {
            next_pos[i][j] = last_sem;

            if(v1[i]==v2[j]) last_sem = j;
        }
    }

    memset(dp,-1,sizeof dp);
    int len = LCIS(1,0);
    cout<<len<<endl;

    vector<int>vLCIS;
    solveLCIS(1,0,vLCIS);

    for(int x:vLCIS) cout<<x<<" ";
    cout<<endl;

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



