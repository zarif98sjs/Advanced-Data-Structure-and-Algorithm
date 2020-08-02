
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#endif

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

vector<int>v;
vector<bool>inPermutaion;
int n;

vector<int>permutation;

void generate()
{
    if((int)permutation.size()==n)
    {
        cout<<permutation<<endl;
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(inPermutaion[i]) continue;

        inPermutaion[i] = true;
        permutation.push_back(v[i]);
        generate();

        inPermutaion[i] = false;
        permutation.pop_back();
    }
}

void generate_using_stl()
{
    permutation.clear();

    permutation = v;

    cout<<"STL"<<endl;

    do{
        cout<<permutation<<endl;
    }while(next_permutation(ALL(permutation)));
}

int main()
{
    optimizeIO();

    while(true)
    {
        cin>>n;

        v = vector<int>(n);
        inPermutaion = vector<bool>(n,false);

        for(int i=0; i<n; i++)
            cin>>v[i];

        generate();
        generate_using_stl();
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


