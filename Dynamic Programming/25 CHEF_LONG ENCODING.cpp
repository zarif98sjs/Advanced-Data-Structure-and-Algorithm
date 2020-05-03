
/**

Prob : CHEF LONG ENCODING

Let's define a function f(x) for a positive integer x as follows:

1) Consider the decimal representation of x (without leading zeros).
Split it into the minimum number of contiguous subsequences of digits
such that in each subsequence, all digits are identical.

2) For each subsequence, look at its position in the original decimal representation of x
.Let's say that the most significant digit it contained was the e-th digit,
where e=0 corresponds to the least significant digit of x.
For example, 388,822,442 can be split into subsequences "3", "888", "22", "44", "2", where e=7 for the sequence "888" and e=4
for the sequence "22".

3) The value of a subsequence which contains a digit d repeated one or more times is d*10^e.

4) f(x) is the sum of values of these subsequences. For example,
f(388,822,442)=3*1e8+8*1e7+2*1e4+4*1e2+2*1e0

The oven has a screen which displays two long integers L
and R (with NL and NR digits respectively, without leading zeros).
The password is the sum of f(x) for each x between L and R inclusive.

Chef does not have a lot of time, so he asks for your help.
Please find the password for the oven so that he can start cooking as fast as possible.
Since this number could be very large, compute it modulo 109+7

Constraints
-----------
1≤T≤10

1≤NL,NR≤105
1≤L≤R<1e100000
L and R do not contain leading zeros

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

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e3+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

string inp;
string A,B;

PLL dp[100005][2][2][20];
LL ten[100005];

LL MOD = 1e9+7;

inline void precalculate ()
{
    ten[0] = 1;
    for(int i=1;i<=100000;i++)
        ten[i] = ((ten[i-1]%MOD) *10)%MOD;
}

LL bigMod(LL x,LL n,LL mo)
{
    if(n==0)
        return 1;

    LL u = bigMod(x,n/2,mo);
    u = ((u%mo)*(u%mo))%mo;

    if(n%2==1)
        u = ((u%mo)*(x%mo))%mo;

    return u;
}

PLL go(int pos,int choto,int boro,int prev)
{
    if(pos<0)
        return MP(0,1);

    PLL &ret = dp[pos][choto][boro][prev];

    if(ret.F!=-1 && boro && choto)
        return ret;

    ret = MP(0,0);
    int lo = 0, hi = 9;

    if(!choto)
        hi = B[pos] - '0';
    if(!boro)
        lo = A[pos] - '0';

    for(int j=lo; j<=hi; j++)
    {
        PLL temp = go(pos-1, choto | (j<hi), boro | (j>lo),j);
        temp.F %= MOD;
        temp.S %= MOD;
        if(j!=prev)
        {
            ret.F = (ret.F%MOD + (((j*temp.S)%MOD)*ten[pos]))%MOD;

        }
        ret.F = (ret.F%MOD + temp.F)%MOD;
        ret.S = (ret.S%MOD + temp.S)%MOD;

    }

    return ret;
}

int main()
{
    //optimizeIO();
    precalculate ();

    int tc;
    scanf("%d",&tc);
    //cin>>tc;

    memset(dp,-1,sizeof dp);

    for(int q=1; q<=tc; q++)
    {

        //cout<<"----------------------"<<endl;
        //cout<<"Case "<<q<<": ";

        LL la,lb;
        string a,b;
        char s1[100007],s2[100007];
        scanf("%lld",&la);
        scanf("%s",s1);

        scanf("%lld",&lb);
        scanf("%s",s2);
        //cin>>la>>a>>lb>>b;

        A = s1;
        B = s2;

        while(A.size()<B.size())
        {
            A.insert(A.begin(),'0');
        }

        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());

        PLL ans = go(B.size()-1,0,0,-1);
        ans.F %= MOD;
        printf("%lld\n",ans.F);
        //cout<<ans.F<<endl;
    }


    return 0;
}

/**

Example Input

3
1 9
2 97
1 8
2 12
1 1
1 8

Example Output

4681
49
36

**/
