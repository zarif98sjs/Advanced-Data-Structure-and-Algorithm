

/*
 * AVL TREE
 *
 * Key Idea : Force height difference between the 2 child to be atmost 1 using tree rotations only
 *
 * */


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
#define endl "\n"
#endif

#define left 0
#define right 1

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct Node
{
    int data,height,balance;
    Node *child[2];

    Node(int data)
    {
        this->data = data;
        this->balance = 0;
        this->child[left] = NULL;
        this->child[right] = NULL;
    }
};

struct AVL
{
    Node *root;

    AVL()
    {
        root = NULL;
    }

    void update(Node* node)
    {
        int leftH = (node->child[left] == NULL) ? -1 : node->child[left]->height;
        int rightH = (node->child[right] == NULL) ? -1 : node->child[right]->height;

        node->height = 1 + max(leftH,rightH);
        node->balance = rightH - leftH;
    }

    Node* rebalance(Node *node)
    {
        if(node->balance == -2) /*left heavy*/
        {
            if(node->child[left]->balance > 0) /*left-right*/
                return doubleRotate(node,right);
            else /*left-left*/
                return rotate(node,right);
        }
        else if(node->balance == 2) /*right heavy*/
        {
            if(node->child[right]->balance < 0) /*right-left*/
                return doubleRotate(node,left);
            else /*right-right*/
                return rotate(node,left);
        }

        return node;
    }

    Node* rotate(Node *node,bool dir) /*single rotate*/
    {
        Node *temp = node->child[!dir];
        node->child[!dir] = temp->child[dir];
        temp->child[dir] = node;

        update(node);
        update(temp);

        return temp;
    }

    Node* doubleRotate(Node *node,bool dir) /*align ,then rotate*/
    {
        node->child[!dir] = rotate(node->child[!dir],!dir);
        return rotate(node,dir);
    }

    void insert(int data)
    {
        root = insert(root,data);
    }

    Node* insert(Node *node,int data)
    {
        if(node == NULL) return new Node(data);

        bool dir = data > node->data; /*left -> 0 , right -> 1*/
        node->child[dir] = insert(node->child[dir],data);

        update(node);

        return rebalance(node);
    }

    bool search(int data)
    {
        Node* ret = search(root,data);

        if(ret==NULL) return false;
        else return true;
    }

    Node* search(Node* node,int data)
    {
        if(node == NULL || node->data==data)
            return node;

        bool dir = data > node->data;

        return search(node->child[dir],data);
    }

    void preorder()
    {
//        cout<<"Preorder : ";
        preorder(root);
        cout<<endl;
    }

    void preorder(Node *node)
    {
        if(node == NULL)
            return;

        cout<<node->data;

        if(node->child[left] || node->child[right])
            cout<<"(";
        preorder(node->child[left]);
        if(node->child[left] || node->child[right])
            cout<<")";

        if(node->child[left] || node->child[right])
            cout<<"(";
        preorder(node->child[right]);
        if(node->child[left] || node->child[right])
            cout<<")";
    }

    void remove(int data)
    {
        root = remove(root,data);
    }

    Node* remove(Node *node,int data)
    {
        if(node == NULL)
        {
            return node;
        }
        else
        {
            /*found the delete key*/
            if(node->data == data)
            {
                /*has one child only*/
                if(node->child[left]==NULL || node->child[right]==NULL)
                {
                    Node* temp = NULL;
                    if(node->child[left]) temp = node->child[left];
                    if(node->child[right]) temp = node->child[right];

                    return temp;
                }
                else /*has 2 child => replace with inorder predecessor / successor and recurse for that*/
                {
                    Node *temp = getMax(node->child[left]); /*inorder predecessor : maximum value in the left subtree*/

                    node->data = temp->data;
                    data = temp->data; /*updating with predecessor data as this is the one to delete now*/
                }
            }

            bool dir = data > node->data;

            node->child[dir] = remove(node->child[dir],data); /*recurse*/
        }

        update(node);

        return rebalance(node);
    }

    Node* getMax(Node* node)
    {
        Node* now = node;

        while (now && now->child[right] != NULL)
            now = now->child[right];

        return now;
    }
};

int32_t main()
{
    optimizeIO();

    freopen("in1.txt","r",stdin);
//    freopen("out7.txt","w",stdout);

    AVL avl;

    string option;

    while(cin>>option)
    {
        int num;
        cin>>num;

        if(option=="F")
        {
            bool has = avl.search(num);
//            if(has)
//                cout<<"True"<<endl;
//            else
//                cout<<"False"<<endl;
        }
        else if(option=="I")
        {
            avl.insert(num);
//            avl.preorder();
        }
        else if(option=="D")
        {
            avl.remove(num);
//            avl.preorder();
        }
    }

#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}
