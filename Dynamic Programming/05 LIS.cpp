
/**

Problem : Longest Increasing Subsequence

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
**/
int LIS[nmax];
vector<int>SEQ[nmax];

int main()
{
    optimizeIO();

    vector<int>ara = {-1,6,2,5,1,7,4,8,3};
    int n=ara.size();

    for(int i=1;i<=n;i++)
    {
        LIS[i] = 1;
        for(int j=1;j<=i;j++)
        {
            if(ara[i]>ara[j])
            {
                LIS[i] = max(LIS[i],LIS[j]+1); /** **/
                if(SEQ[j].size()+1 > SEQ[i].size()) SEQ[i] = SEQ[j];
            }
        }
        SEQ[i].push_back(ara[i]);
    }

    int lis_len = *max_element(LIS+1,LIS+n+1);

    vector<int>lis = SEQ[1];

    for(int i=2;i<=n;i++)
        if(SEQ[i].size()>lis.size())
            lis = SEQ[i];

    for(auto x:lis)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}


