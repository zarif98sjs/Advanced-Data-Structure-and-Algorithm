
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

/** Number of Divisors **/

/// NOD
LL number_of_Divisors(LL N)
{
    LL PF_idx = 0, PF = primes[PF_idx], ans = 1;             /// start from ans = 1
    while (N != 1 && (PF * PF <= N))
    {
        LL power = 0;                                             /// count the power
        while (N % PF == 0)
        {
            N /= PF;
            power++;
        }
        ans *= (power + 1);                              /// according to the formula
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans *= 2;             /// (last factor has pow = 1, we add 1 to it)
    return ans;
}

/// Sum of NOD from 1 to N [O(sqrt(N))]
LL cumulative_sum_of_number_of_Divisors(LL N)
{
    LL res = 0;
    LL u = sqrtl(N);
    for ( LL i = 1; i <= u; i++ )
    {
        res += ( N / i ) - i; //Step 1
    }
    res *= 2; //Step 2
    res += u; //Step 3
    return res;
}



/** Sum of Divisors **/

/// SOD
LL sum_of_Divisors(LL N)
{
    LL res = 1;
    LL sqrtn = sqrtl (N);
    for ( LL i = 0; i < primes.size() && primes[i] <= sqrtn; i++ )
    {
        if ( N % primes[i] == 0 )
        {
            LL tempSum = 1; // Contains value of (p^0+p^1+...p^a)
            LL p = 1;
            while ( N % primes[i] == 0 )
            {
                N /= primes[i];
                p *= primes[i];
                tempSum += p;
            }
            sqrtn = sqrtl ( N );
            res *= tempSum;
        }
    }
    if ( N != 1 )
    {
        res *= ( N + 1 ); // Need to multiply (p^0+p^1)
    }
    return res;
}


LL sum(LL n)
{
    return (n*(n+1))/2;
}

/// Sum of SOD from 1 to N [O(sqrt(N))]
LL cumulative_sum_of_Divisors(LL N)
{
    LL ans=0;
    LL nod=0;
    LL u=sqrtl(N);

    for(LL i=2; i<=u; i++)
    {
        nod = (N/i)-i;
        ans += nod*i;
        ans += (sum(N/i)-sum(i));
        ans += i;
    }

    return ans;
}


int main()
{
    optimizeIO();

    bit_sieve(1e6);

    while(1)
    {
        LL num;
        cin>>num;

        cout<<number_of_Divisors(num)<<endl;
        cout<<cumulative_sum_of_number_of_Divisors(num)<<endl;
        cout<<sum_of_Divisors(num)<<endl;
        cout<<cumulative_sum_of_Divisors(num)<<endl;
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


