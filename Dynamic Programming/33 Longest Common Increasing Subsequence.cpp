
/**

LCIS(Longest Common Increasing Subsequence)
===========================================

Straightforward DP : O(N^3)

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
// int dp[505][505][505];

map<string,int>dp;

int LCIS(int i,int j,int prev)
{
    if(i==n1 || j==n2) return 0;

    string state = to_str(i) + "|" + to_str(j) + to_str(prev);

    if(dp.find(state)!=dp.end()) return dp[state];
    int &ret = dp[state];

    if(v1[i]==v2[j] && v1[i]>prev)
    {
        // DBG(i), DBG(v1[i]);
        ret = max(1 + LCIS(i + 1, j + 1, v1[i]), LCIS(i+1,j+1,prev));
    }
    else
    {
        ret = max(LCIS(i,j+1,prev), LCIS(i+1,j,prev));
    }

    return ret;
}

void solveLCIS(int i,int j,int prev,vector<int>&vLCS)
{
    if(i==n1 || j==n2) return;

    if(v1[i]==v2[j] && v1[i]>prev)
    {
        int way1 = 1 + LCIS(i + 1, j + 1, v1[i]) , way2 = LCIS(i+1,j+1,prev);

        if(way1 > way2)
        {
            vLCS.push_back(v1[i]);
            return solveLCIS(i+1,j+1,v1[i],vLCS);
        }
        else
        {
            return solveLCIS(i+1,j+1,prev,vLCS);
        }
    }
    else
    {
        int way1 = LCIS(i+1,j,prev) , way2 = LCIS(i,j+1,prev);

        if(way1 > way2) return solveLCIS(i+1,j,prev,vLCS);
        else return solveLCIS(i,j+1,prev,vLCS);
    }
}

int main()
{
    optimizeIO();


    cin>>n1;
    v1 = vector<int>(n1);
    for(int i=0;i<n1;i++)
        cin>>v1[i];

    cin>>n2;
    v2 = vector<int>(n2);
    for(int i=0;i<n2;i++)
        cin>>v2[i];

    int len = LCIS(0,0,-1);
    vector<int>vLCIS;
    solveLCIS(0,0,-1,vLCIS);

    cout<<len<<endl;
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



