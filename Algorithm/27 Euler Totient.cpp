
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

const int nmax = 1e6+7;
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

/** Bit Sieve **/

const int pnmax = 1e8+7;
LL LIM;
bitset<pnmax> bs;   /// can sieve upto 1e8 in ~ 1 sec
vector<LL> primes;

void bit_sieve(LL upperbound)
{
    LIM = upperbound + 1;
    bs.set();                                     /// set all bits to 1
    bs[0] = bs[1] = 0;
    for (LL i = 2; i <= LIM; i++) /** If I don't want to know the primes , it is enough to loop upto sqrt(LIM) here **/
        if (bs[i])
        {
            for (LL j = i * i; j <= LIM; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
}

bool isPrime(LL N)
{
    if (N <= LIM)
        return bs[N];                   /// O(1) for small primes

    /** note: only work for N <= (last prime in "primes" vector)^2 . So, if Sieve is done upto 10^6 , can know isPrime upto 10^12 **/
    for (LL x:primes)
        if (N % x == 0)
            return false;
    return true;                    /// it takes longer time if N is a large prime!
}

/** calculates Euler Totient of n **/
LL eulerPhi(LL n)
{
    LL res = n;
    LL sqrtn = sqrtl ( n );
    for ( LL i = 0; i < primes.size() && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
            }
            sqrtn = sqrtl ( n );
            res /= primes[i];
            res *= primes[i] - 1;
        }
    }
    if ( n != 1 )
    {
        res /= n;
        res *= n - 1;
    }
    return res;
}


/** calculates Euler Totient from 1 to n **/

LL phi[nmax];

void eulerPhi_upto_n(LL n)
{
    for (int i=1; i<=n; i++)
        phi[i] = i; /// indicates not evaluated yet and initializes for product formula.

    for (int p=2; p<=n; p++) /// Compute other Phi values
    {
        if (phi[p] == p) /// If phi[p] is not computed already, then number p is prime
        {
            phi[p] = p-1; /// Phi of a prime number p is always equal to p-1.

            for (int i = 2*p; i<=n; i += p)  /// Update phi values of all multiples of p
                phi[i] = (phi[i]/p) * (p-1);  /// Add contribution of p to its multiple i by multiplying with (1 - 1/p)
        }
    }

//    // Print precomputed phi values
//    for (int i=1; i<=n; i++)
//      cout << "Totient of " << i << " is "
//           << phi[i] << endl;
}



int main()
{
    optimizeIO();

    bit_sieve(1e6);

    eulerPhi_upto_n(1e6);

    while(1)
    {
        LL num;
        cin>>num;

        cout<<phi[num]<<endl;
        cout<<eulerPhi(num)<<endl;
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


