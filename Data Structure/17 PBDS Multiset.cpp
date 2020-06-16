
/**

NOT KNOWING THIS MULTISET VARIENT OF PBDS COST A PROBLEM IN ICPC PRELI 2019 :)

Policy Based Data Structure (MULTI SET)
===========================

SEE PBDS SET FOR AVAILABLE FUNCTIONS

Implementation 1 : using "less_equal" in declaration
-----------------------------------------------------

Use this when no ERASE required

CONS:
1. Erase doesn't work
2. lower_bound works like upper_bound
3. upper_bound works like lower_bound

**/

/**Which of the favors of your Lord will you deny ?**/

#undef _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_multiset = tree<
                    TIn, null_type, less_equal<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e6+7;
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

int main()
{
    optimizeIO();

    indexed_multiset<int> MS;

    MS.insert(30);
    MS.insert(10);
    MS.insert(20);
    MS.insert(10);
    MS.insert(40);
    MS.insert(30);

    for(auto x:MS)
        cout<<x<<" ";
    cout<<endl;

    /// erase DOESN'T work
    MS.erase(10);
    MS.erase(10);
    MS.erase(20);

    for(auto x:MS)
        cout<<x<<" ";
    cout<<endl;

    /// returns the index of first value which has value greater than or equals to x
    /***imp***/
    cout<<MS.order_of_key(10)<<endl;
    cout<<MS.order_of_key(11)<<endl;
    cout<<MS.order_of_key(12)<<endl;
    cout<<MS.order_of_key(20)<<endl;
    cout<<MS.order_of_key(30)<<endl;
    cout<<endl;

    /// returns the value of nth index
    cout<<*MS.find_by_order(0)<<endl;
    cout<<*MS.find_by_order(1)<<endl;
    cout<<*MS.find_by_order(2)<<endl;
    cout<<*MS.find_by_order(3)<<endl;
    cout<<*MS.find_by_order(6)<<endl;
    cout<<endl;

    /// lower_bound works like upper_bound in normal set
	/// (to return the first element > it)
    cout<<*MS.lower_bound(10)<<endl;
    cout<<*MS.lower_bound(20)<<endl;
    cout<<*MS.lower_bound(30)<<endl;
    cout<<*MS.lower_bound(40)<<endl;
    cout<<endl;

    /// upper_bound works like lower_bound in normal set
	/// (to return the first element >= it)
    cout<<*MS.upper_bound(10)<<endl;
    cout<<*MS.upper_bound(20)<<endl;
    cout<<*MS.upper_bound(30)<<endl;
    cout<<*MS.upper_bound(40)<<endl;

}


