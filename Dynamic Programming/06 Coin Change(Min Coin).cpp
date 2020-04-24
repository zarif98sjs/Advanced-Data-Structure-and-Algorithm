
/**

Problem : Coin Change (Minimum number of coins to make a sum)

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

/**
MIN[i] = minimum number of coins to make sum i
**/

int MIN[nmax];

int main()
{
    optimizeIO();

    int sum = 11;
    vector<int>coins = {1,3,7};

    fill(MIN,MIN+nmax,INT_MAX); /** **/
    MIN[0] = 0;

    for(int s=1;s<=11;s++)
    {
        for(int i=0;i<coins.size();i++)
        {
            if(s-coins[i]>=0)
                MIN[s] = min(MIN[s],MIN[s-coins[i]]+1); /** **/
        }
    }

    for(int s=0;s<=sum;s++)
        cout<<"MIN for "<<s<<" : "<<MIN[s]<<endl;

    /** Finding the solution **/
    while(1)
    {
        int backtrack_value;
        cin>>backtrack_value;

        int val = backtrack_value;
        vector<int>ans;

        while(val>0)
        {
            for(int i=0;i<coins.size();i++)
            {
                if(MIN[val] - MIN[val-coins[i]] ==1)
                {
                    ans.push_back(coins[i]);
                    val -= coins[i];
                    break;
                }
            }
        }

        cout<<"Value : "<<backtrack_value<<endl;
        for(auto x:ans)
            cout<<x<<" ";
        cout<<endl;
    }


    return 0;
}


