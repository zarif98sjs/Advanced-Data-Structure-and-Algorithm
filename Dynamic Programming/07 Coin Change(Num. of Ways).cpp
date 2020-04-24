
/**

Problem : Coin Change (Number of ways to make a sum)

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
WAYS[i] = number of ways to make sum i
**/

int WAYS[nmax];

int main()
{
    optimizeIO();

    int sum = 5;
    vector<int>coins = {1,2,5};

    WAYS[0] = 1;

    for(int s=0;s<=sum;s++)
    {
        for(int i=0;i<coins.size();i++)
        {
            if(s-coins[i]>=0)
                WAYS[s] += WAYS[s-coins[i]];
        }
    }

    for(int s=0;s<=sum;s++)
        cout<<"WAYS "<<s<<" : "<<WAYS[s]<<endl;


    return 0;
}


