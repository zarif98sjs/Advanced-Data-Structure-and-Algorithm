
/**

Problem : SPOJ CPCRC1C

Input
-----
Two space-separated integers 0 <= a <= b <= 1e9.

Program terminates if a and b are -1.

Output
------
The sum of the digits of numbers a through b.

Note : This version of the solution doesn't put sum in the dp state.
So, it would work even if the values were large

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

PLL dp[20][2][2];

PLL go(int pos,int choto,int boro)
{
    if(pos<0)
        return MP(0,1);

    PLL &ret = dp[pos][choto][boro];

    if(ret.F!=-1 && boro && choto)
        return ret;

    ret = MP(0,0);
    int lo = 0 , hi = 9;

    if(!choto) hi = B[pos] - '0';
    if(!boro) lo = A[pos] - '0';

    for(int j=lo; j<=hi; j++)
    {
        PLL temp = go(pos-1, choto | (j<hi), boro | (j>lo));
        ret.F += j*temp.S;
        ret.F += temp.F;
        ret.S += temp.S;
    }

    return ret;
}

int main()
{
    optimizeIO();

    memset(dp,-1,sizeof dp);

    while(1)
    {

        //cout<<"----------------------"<<endl;
        //cout<<"Case "<<q<<": ";

        LL a,b;
        cin>>a>>b;

        if(a==-1 && b==-1)
            break;

        A = to_str(a);
        B = to_str(b);

        while(A.size()<B.size())
        {
            A.insert(A.begin(),'0');
        }

        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());

        PLL ans = go(B.size()-1,0,0);
        cout<<ans.F<<endl;
    }


    return 0;
}
