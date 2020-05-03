
/**

Problem : LightOj 1032
Adjacent 1 Scores in binary

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

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

string dec_to_bin(LL n)
{
    string bin;
    while(n!= 0)
    {
        bin.push_back(char(n%2+'0'));
        n = n/2;
    }

    reverse(ALL(bin));
    return bin;

}

string A,B;

LL dp[35][2][2][2][35];

LL go(int pos,int choto,int boro,int prev,int score)
{
    if(pos==B.size())
        return score; /** score for each possible number **/

    LL &ret = dp[pos][choto][boro][prev][score];

    if(ret!=-1)
        return ret;

    ret = 0;

    int lo = 0, hi = 1; /** digits : 0,1 **/

    if(!choto)
        hi = B[pos] - '0';
    if(!boro)
        lo = A[pos] - '0';

    for(int j=lo; j<=hi; j++)
    {
        ret += go(pos+1, choto | (j<hi), boro | (j>lo),j,(j==1 && prev==1)+score); /** (current digit==1 && prev digit==1) **/
    }

    return ret;
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    for(int qq=1; qq<=tc; qq++)
    {
        LL a,b;
        cin>>b;
        a = 0;

        B = dec_to_bin(b);
        A = to_str(a);

        while(A.size()<B.size())
        {
            A.insert(A.begin(),'0');
        }

        memset(dp,-1,sizeof dp);
        LL ans = go(0,0,0,0,0);

        cout<<"Case "<<qq<<": "<<ans<<endl;
    }

    return 0;
}


