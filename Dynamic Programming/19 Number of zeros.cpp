
/**

Problem : LightOj 1140
Number of zeros

Jimmy writes down the decimal representations of all natural numbers
between and including m and n, (m ≤ n).
How many zeroes will he write down?

**/


/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
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

string A,B;

LL dp[10][2][2][2][12];

LL go(int pos,int choto,int boro,int not_first_pos,int val)
{
    if(pos==B.size())
        return val;

    LL &ret = dp[pos][choto][boro][not_first_pos][val];

    if(ret!=-1)
        return ret;

    ret = 0;

    int lo = 0, hi = 9;

    if(!choto) hi = B[pos] - '0';
    if(!boro) lo = A[pos] - '0';

    for(int j=lo; j<=hi; j++)
        ret += go(pos+1, choto | (j<hi), boro | (j>lo), not_first_pos | (j>0) ,  (j==0 && not_first_pos)+val);

    return ret;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {

        //cout<<"----------------------"<<endl;
        cout<<"Case "<<q<<": ";

        LL a,b;
        cin>>a>>b;

        B = to_str(b);
        A = to_str(a);
        while(A.size()<B.size())
        {
            A.insert(A.begin(),'0');
        }

        //cout<<inp<<endl;
        memset(dp,-1,sizeof dp);
        LL ans = go(0,0,0,0,0) + (a==0);
        cout<<ans<<endl;

    }


    return 0;
}
