
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second

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

int ara[nmax];

int binarySearch(int lo,int hi,int key)
{
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;

        if(ara[mid]<key) lo = mid + 1;
        else if (ara[mid]>key) hi = mid - 1;
        else return mid;
    }

    return -1;
}

int lowerBound(int lo,int hi,int key)
{
    while(lo!=hi)
    {
        int mid = lo + (hi-lo)/2;

        if(ara[mid]<key) lo = mid + 1;
        else hi = mid;
    }

    return lo;

}

int upperBound(int lo,int hi,int key)
{
    while(lo!=hi)
    {
        int mid = lo + (hi-lo)/2;

        if(ara[mid]<=key) lo = mid + 1;
        else hi = mid;
    }

    return lo;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>ara[i];

    sort(ara+1,ara+n+1);

    for(int i=1;i<=n;i++)
        cout<<ara[i]<<" ";
    cout<<endl;

    while(1)
    {
        int val;
        cin>>val;
        int idx = binarySearch(1,n,val);
        if(idx!=-1) cout<<val<<" present at : "<<idx<<endl;
        else cout<<val<<" absent"<<endl;
    }

    /// for 1 based indexing with n elements , set lo = 1 , hi = n+1

    while(1)
    {
        int val;
        cin>>val;
        int idx = lowerBound(1,n+1,val);
        if(idx>n) cout<<"lower_bound doesn't exist"<<endl;
        else cout<<"lower_bound of "<<val<<" : "<<idx<<endl;
    }

    while(1)
    {
        int val;
        cin>>val;
        int idx = upperBound(1,n+1,val);
        if(idx>n) cout<<"upper_bound doesn't exist"<<endl;
        else cout<<"upper_bound of "<<val<<" : "<<idx<<endl;
    }

    return 0;
}

/**

10
10 2 2 8 5 6 4 5 4 4

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


