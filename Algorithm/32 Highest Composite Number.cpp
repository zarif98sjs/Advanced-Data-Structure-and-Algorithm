
/**

Highest Composite Number (HCN)
==============================

A Highly Composite Number (HCN) is a positive integer which has more divisors than any smaller positive integer
i.e, if NOD(N)>NOD(i), where 0<i<N, then N is HCN.

Problem
-------
Given an integer N, find the largest HCN which is smaller than or equal to N.

Let’s try to solve it for when N=1e9.
We know that p10=6469693230, so we will only have primes 2,3,5,7,11,13,17,19,23 in HCN factorization.

**/

/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e6+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}
// prime[] is a list of prime.
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23 };

int resNum, resDiv, n;
void recur ( int pos, int limit, long long num, int div )
{
    if ( div > resDiv )   // Get the number with highest NOD
    {
        resNum = num;
        resDiv = div;
    }
    else if ( div == resDiv && num < resNum )   //In case of tie, take smaller number
    {
        resNum = num;
    }

    if ( pos == 9 )
        return; //End of prime list

    long long p = prime[pos];

    for ( int i = 1; i <= limit; i++ )
    {
        if ( num * p > n )
            break;
        recur ( pos + 1, i, num * p, div * ( i + 1 ) );
        p *= prime[pos];
    }
}

int main ()
{
    while(1)
    {
        cin>>n;
        resNum = 0;
        resDiv = 0;
        recur ( 0, 30, 1, 1 );
        printf ( "%d %d\n", resNum, resDiv );
    }

}

