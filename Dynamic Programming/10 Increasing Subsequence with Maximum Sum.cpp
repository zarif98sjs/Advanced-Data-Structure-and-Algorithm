
/**

Problem : Maximum Increasing Subsequence Sum

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
ISum[i] = Maximum increasing subsequence sum ending at i
**/
int ISum[nmax];
vector<int>ISEQ[nmax];

int main()
{
    optimizeIO();

    vector<int>ara = {-1,0,8,4,12,2,10,6,14,1,9,5,13,3,11}; /** 1 based indexing **/
    int n=ara.size()-1;

    for(int i=1; i<=n; i++)
    {
        ISum[i] = ara[i];
        for(int j=1; j<=i; j++)
        {
            if(ara[i]>ara[j]) /** If increasing subsequence **/
            {
                if(ISum[j]+ara[i] > ISum[i]) /** If (current max in ara[1...j]+ara[i]) is greater than current value **/
                {
                    ISum[i] = ISum[j]+ara[i];
                    ISEQ[i] = ISEQ[j];
                }
            }
        }
        ISEQ[i].push_back(ara[i]);
    }

//    for(int i=1;i<=n;i++)
//        cout<<"ISum "<<ara[i]<<" : "<<ISum[i]<<endl;

    int max_sum = 0;
    int max_sum_idx = 0;

    for(int i=1; i<=n; i++)
        if(ISum[i]>max_sum)
            max_sum = ISum[i], max_sum_idx = i;

    cout<<"Maximum Sum : "<<max_sum<<endl;
    cout<<"Increasing Subsequence with maximum sum : ";
    for(auto x:ISEQ[max_sum_idx])
        cout<<x<<" ";
    cout<<endl;

    return 0;
}


