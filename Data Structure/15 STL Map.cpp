
/**

MAP
===

Declaration
-----------

map< KEY , VALUE > MAP

Different type of possible variations of declaring MAP .

1.    map<int,int>MAP1;
2.    map<PII,int>MAP2;
3.    map<string, vector<int> >MAP3;

There can be many many more ways of declaring maps

Operations
----------

ALMOST identical to all the functions of STL SET.


**/

/** Which of the favors of your Lord will you deny ? **/

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

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

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

const int nmax = 2e5+7;
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}


int main()
{
    optimizeIO();

    cout<<"Map Type 1 "<<endl;
    cout<<"==========="<<endl;

    map<int,int>MAP1;
    MAP1[10] = 5;
    MAP1[5] = 15;
    MAP1[2] = 45;

    for(auto x:MAP1)
        cout<<x.F<<" : "<<x.S<<endl;

    cout<<"Map Type 2 "<<endl;
    cout<<"==========="<<endl;

    map<PII,int>MAP2;
    MAP2[ {10,5} ] = 5;
    MAP2[ {5,2} ] = 15;
    MAP2[ {2,12} ] = 45;

    for(auto x:MAP2)
        cout<<x.F.F<<" , "<<x.F.S<<" : "<<x.S<<endl;

    cout<<"MAP Type 3 "<<endl;
    cout<<"==========="<<endl;

    map<string, vector<int> >MAP3;
    MAP3["A"].push_back(15);
    MAP3["A"].push_back(5);

    MAP3["B"].push_back(10);
    MAP3["B"].push_back(2);

    for(auto x:MAP3)
    {
        cout<<x.F<<" : ";
        for(auto v:x.S)
            cout<<v<<" ";
        cout<<endl;
    }

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


