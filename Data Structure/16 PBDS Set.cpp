
/**

Policy Based Data Structure (SET)
===========================

The problem with STL SET is that :

1. We can NOT ACCESS by index . Here we can ,
using : *find_by_order(index) // 0 based indexing

2. We can NOT know the NUMBER of values < x , we can only get the VALUE > x using lower_bound() of set . Here we can ,
using : order_of_key(value) // 0 based indexing

Functions:
==========

1) insert(val)
2) erase(val)
3) order_of_key(val) // 0 based indexing          :  returns NUMBER of integers < "val" which is the same as returning the first index to have value >= "val"
4) *find_by_order(index) // 0 based indexing      :  returns value at ith index
5) *lower_bound(val)                              :  returns first value >= "val"
6) *upper_bound(val)                              :  returns first value > "val"


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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

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

const int nmax = 1e6+7;
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

indexed_set<int> s;

int main()
{
    optimizeIO();

    s.clear();

    s.insert(40);
    s.insert(10);
    s.insert(100);
    s.insert(50);
    s.insert(50); /// only 1 instance
    s.insert(30);
    s.insert(20);
    s.insert(20);

    for(auto x:s)
        cout<<x<<" ";
    cout<<endl;

    s.erase(50);
    s.erase(30);

    for(auto x:s)
        cout<<x<<" ";
    cout<<endl;


    /// 0 based indexing
    cout<<"Number of integers < 30 : "<<s.order_of_key(30)<<endl; /// returns the value of last index if not present
    cout<<"Number of integers < 100 : "<<s.order_of_key(100)<<endl;

    cout<<endl;

    /// 0 based indexing
    cout<<"At 1th Position : "<<*s.find_by_order(1)<<endl;
    cout<<"At 2th Position : "<<*s.find_by_order(2)<<endl;
    cout<<"At 3th Position : "<<*s.find_by_order(3)<<endl;
    cout<<"At 4th Position : "<<*s.find_by_order(4)<<endl; /// returns 0 if not present

    /// lower_bound
    cout<<"lower_bound(10) : "<<*s.lower_bound(10)<<endl;
    cout<<"lower_bound(25) : "<<*s.lower_bound(25)<<endl;

    /// upper_bound
    cout<<"upper_bound(10) : "<<*s.upper_bound(10)<<endl;
    cout<<"upper_bound(25) : "<<*s.upper_bound(25)<<endl;

}


