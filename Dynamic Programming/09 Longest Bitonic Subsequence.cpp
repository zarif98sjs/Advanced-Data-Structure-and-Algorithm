
/**

Problem : Longest Bitonic Subsequence

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

/** 1 based indexing **/

/**
LIS[i] = LIS ending at index i
LDS[i] = LDS starting at index i (Basically LIS thinking from the reverse side)
**/
int LIS[nmax];
int LDS[nmax];
vector<int>ISEQ[nmax];
vector<int>DSEQ[nmax];

int main()
{
    optimizeIO();

    vector<int>ara = {-1,4,2,5,9,7,6,10,3,1}; /** 1 based indexing **/
    int n=ara.size()-1;

    for(int i=1;i<=n;i++)
    {
        LIS[i] = 1;
        for(int j=1;j<=i;j++)
        {
            if(ara[i]>ara[j])
            {
                LIS[i] = max(LIS[i],LIS[j]+1); /** **/
                if(ISEQ[j].size()+1 > ISEQ[i].size()) ISEQ[i] = ISEQ[j];
            }
        }
        ISEQ[i].push_back(ara[i]);
    }

    for(int i=n;i>=1;i--)
    {
        LDS[i] = 1;
        for(int j=n;j>=i;j--)
        {
            if(ara[i]>ara[j])
            {
                LDS[i] = max(LDS[i],LDS[j]+1);
                if(DSEQ[j].size()+1 > DSEQ[i].size()) DSEQ[i] = DSEQ[j];
            }
        }
        DSEQ[i].push_back(ara[i]);
    }

    for(int i=1;i<=n;i++)
        cout<<"LIS & LDS "<<i<<" : "<<LIS[i]<<" , "<<LDS[i]<<endl;

    int lbs_len = 0;
    vector<int>lbs1;
    vector<int>lbs2;

    for(int i=1;i<=n;i++)
    {
        if(LIS[i]+LDS[i]-1>lbs_len)
        {
            lbs_len = LIS[i]+LDS[i]-1;
            lbs1 = ISEQ[i];
            lbs2 = DSEQ[i];
        }
    }

    cout<<lbs_len<<endl;

    cout<<"Increasing Part : ";
    for(auto x:lbs1)
        cout<<x<<" ";
    cout<<endl;

    cout<<"Decreasing Part : ";
    reverse(ALL(lbs2));
    for(auto x:lbs2)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}


