
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
    }

    printMS();

    /// order_of_key : returns the index of first value which has value greater than or equals to x  , 0 based indexing
    /*** imp : this is one of the reasons we use PBDS , to know the NUMBER of VALUES < x  ***/
    cout<<"Number of values < 10 : "<<MS.order_of_key({10,0})<<endl;
    cout<<"Number of values < 20 : "<<MS.order_of_key({20,0})<<endl;
    cout<<"Number of values < 30 : "<<MS.order_of_key({30,0})<<endl;

    /// find_by_order : returns the value of nth index , 0 based indexing
    /*** imp : this is one of the reasons we use PBDS , to ACCESS set by index  ***/
    cout<<"At 1th Position : "<<(*MS.find_by_order(1)).F<<endl;
    cout<<"At 2th Position : "<<(*MS.find_by_order(2)).F<<endl;
    cout<<"At 6th Position : "<<(*MS.find_by_order(6)).F<<endl;


    /** lower_bound **/
    auto it1 = MS.lower_bound({10,0});
    auto v = *it1;
    DBG(v);
    auto it2 = MS.lower_bound({25,0});
    v = *it2;
    DBG(v);
    auto it3 = MS.lower_bound({30,0});
    v = *it3;
    DBG(v);

    /** upper_bound **/
    it1 = MS.upper_bound({10,n+1});
    v = *it1;
    DBG(v);
    it2 = MS.upper_bound({25,n+1});
    v = *it2;
    DBG(v);
    it3 = MS.upper_bound({30,n+1});
    v = *it3;
    DBG(v);

    /** erase only one occurrence : O(logN) **/
    erase_one_occurrence(30);

    /** erase ALL occurrence : O(N) **/
    erase_all_occurrence(20);

    printMS();

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
