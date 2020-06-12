
/**

SET
===

Operations
----------

1.  insert              :   O(logN)                         :
2.  begin               :   O(1)                            : points to the first element
3.  rbegin              :   O(1)                            : points to the last element
4.  erase(iterator)     :   O(1)                            :
    erase(value)        :   O(logN)                         :
    erase(it1 , it2)    :   O(distance between it1 and it2) : deletes all value in range [it1,it2)
5.  swap                :   O(1)

6.  find                :   O(logN)                         : returns iterator to st.end() if not present
7.  count               :   O(logN)                         : returns 1 if present , 0 otherwise

8.  lower_bound(val)    :   O(logN)                         : returns VALUE of first element >= val
9.  upper_bound(val)    :   O(logN)                         : returns VALUE of first element > val

Note : There's NO WAY to know the position using lower_bound and upper_bound in CONSTANT TIME. We have to use PBDS for that.


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
    srand(time(0));

    vector<int>v;
    set<int>st , st1 , st2;

    for(int i=0;i<15;i++)
    {
        int val = rand()%25;
        v.push_back(val);
        st.insert(val);

        if(i&1) st1.insert(val);
        else st2.insert(val);
    }

    cout<<v<<endl;
    cout<<st<<endl;

    cout<<"First element : "<<*st.begin()<<endl;
    cout<<"Last element : "<<*st.rbegin()<<endl;

    /** ERASE **/
    cout<<"ERASE"<<endl;

    // erase using iterator
    auto it = st.begin();
    it++;
    it++; // iterator to 3rd element
    st.erase(it);
    cout<<st<<endl;

    // erase range using iterator
    it = st.begin();
    for(int i=0;i<2;i++) it++;
    st.erase(st.begin(),it);
    cout<<st<<endl;

    // erase using value
    st.erase(22);
    cout<<st<<endl;

    /** SWAP **/
    cout<<"SWAP"<<endl;

    cout<<st1<<endl;
    cout<<st2<<endl;

    st1.swap(st2);

    cout<<st1<<endl;
    cout<<st2<<endl;

    /** FIND **/
    cout<<"FIND"<<endl;
    cout<<st<<endl;

    it = st.find(19);
    if(it!=st.end()) cout<<"PRESENT"<<endl;
    else cout<<"ABSENT"<<endl;

    /** COUNT **/
    cout<<"COUNT"<<endl;

    if(st.count(19)!=0) cout<<"PRESENT"<<endl;
    else cout<<"ABSENT"<<endl;

    /** LOWER BOUND UPPER BOUND **/

    cout<<st<<endl;
    auto itlo = st.lower_bound(10);
    auto ithi = st.upper_bound(10);

    cout<<"Lower bound value : "<<*itlo<<endl;
    cout<<"Upper bound value : "<<*ithi<<endl;

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


