
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

class Node
{
public:
    int id, cost;
    string name;

    Node(int id,int cost,string name)
    {
        this->id = id;
        this->cost = cost;
        this->name = name;
    }
};

ostream &operator <<(ostream &os, Node const&node)
{
    os<<"Id : "<<node.id<<" , Cost : "<<node.cost<<" , Name : "<<node.name;
    return os;
}

bool operator<(const Node &A,const Node &B) /** Operator overloaded with Ascending order of cost **/
{
    if(A.cost==B.cost)
        return A.name<B.name;

    return A.cost<B.cost;
}

int main()
{
    optimizeIO();

    /**
        VECTOR
    **/

    vector<Node>v;

    v.push_back(Node(1,100,"C"));
    v.push_back(Node(1,100,"A"));
    v.push_back(Node(1,100,"B"));
    v.push_back(Node(1,500,"AB"));
    v.push_back(Node(1,50,"ABC"));

    cout<<v<<endl;

    sort(ALL(v)); /** Uses the overloaded < operator **/

    cout<<v<<endl;

    /**
        SET
    **/

    set<Node>st; /** Uses the overloaded < operator **/
    st.insert(Node(1,100,"C"));
    st.insert(Node(1,100,"A"));
    st.insert(Node(1,100,"B"));
    st.insert(Node(1,500,"AB"));
    st.insert(Node(1,50,"ABC"));
    cout<<st<<endl;

    /**

    PRIORITY QUEUE is MAX HEAP by default .
    So , uses overloaded < operator and the result will be opposite of what we got in SET .

    **/

    priority_queue<Node>pq;
    pq.push(Node(1,100,"C"));
    pq.push(Node(1,100,"A"));
    pq.push(Node(1,100,"B"));
    pq.push(Node(1,500,"AB"));
    pq.push(Node(1,50,"ABC"));

    while(!pq.empty())
        cout<<pq.top()<<" " , pq.pop();
    cout<<endl;

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


