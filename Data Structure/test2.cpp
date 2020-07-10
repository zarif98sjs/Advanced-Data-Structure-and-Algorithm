
/**

NOT KNOWING THIS MULTISET VARIENT OF PBDS COST A PROBLEM IN ICPC PRELI 2019 :)

Policy Based Data Structure (MULTI SET)
===========================

SEE PBDS SET FOR AVAILABLE FUNCTIONS

Implementation 2 : using "pair<,>" in declaration
--------------------------------------------------

This uses a dummy second variable to use this PBDS as a multiset.
Works fine with almost all the functions .


**/

/**Which of the favors of your Lord will you deny ?**/

//#undef _GLIBCXX_DEBUG

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
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_multiset = tree<
                    pair<TIn,TIn>, null_type, less< pair<TIn,TIn> >,
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

indexed_multiset<int> MS;
indexed_multiset<int> MS2;

template <class T>
void erase_all_occurrence(T val) /** O(n) **/
{
    while((*MS.lower_bound({val,0})).F==val)
        MS.erase(MS.lower_bound({val,0}));
}

template <class T>
void erase_one_occurrence(T val) /** O(logN) **/
{
    MS.erase(MS.lower_bound({val,0}));
}

void printMS()
{
    for(auto x:MS)
        cout<<x<<" ";
    cout<<endl;
}

int main()
{
    optimizeIO();

    MS.clear();

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;

        MS.insert({x,i}); /** insert **/
        MS2.insert({x,i}); /** insert **/
    }

    printMS();

    vector<int> v;
	merge(MS.begin(), MS.end(), MS2.begin(), MS2.end(), back_inserter(v));

	multiset<int> m(v.begin(), v.end());

	for(const auto &element : m) {
		cout << element << " ";
	}
	cout << endl;



}


/**

8
30 10 20 10 40 30 20 20

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
