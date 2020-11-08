
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

struct Node
{
    int data,color;
    Node *child[2];

    Node(int data,int color)
    {
        this->data = data;
        this->color = color;
        this->child[left] = NULL;
        this->child[right] = NULL;
    }
};

#define RED 0
#define BLACK 1

/// Red - 0 , Black - 1

struct RBT
{
    Node *root;

    RBT()
    {
        root = NULL;
    }

    bool red(Node *node)
    {
        if(node==NULL)
            return false;

        return node->color == RED;
    }

    void colorFlip(Node *node)
    {
        node->color = node->color^1;
        node->child[left]->color = node->child[left]->color^1;
        node->child[right]->color = node->child[right]->color^1;
    }

    Node* rotate(Node *node,bool dir)
    {
        Node *temp = node->child[!dir];
        node->child[!dir] = temp->child[dir];
        temp->child[dir] = node;

        temp->color = node->color;
        node->color = RED;

        return temp;
    }

    /// align reds  , then rotate
    Node* doubleRotate(Node *node,bool dir)
    {
        node->child[!dir] = rotate(node->child[!dir],!dir);
        return rotate(node,dir);
    }

    void insert(int data)
    {
        root = __insert(root,data);
        root->color = BLACK;
    }

    Node* INSERT_FIX_UP(Node *node,bool dir)
    {
        if(red(node->child[dir]))
        {
            /// case 1 : both child red => any one child has 2 reds in a row (LL LR RR RL) => flip colors
            if(red(node->child[!dir]))
            {
                if(red(node->child[dir]->child[dir]) || red(node->child[dir]->child[!dir]))
                {
                    colorFlip(node);
                }
            }
            else
            {
                /// case 2 : both child not red

                if(red(node->child[dir]->child[dir]))
                {
                    /// any one child has 2 reds in a row (LL RR) => rotate
                    node = rotate(node,!dir);
                }
                else if(red(node->child[dir]->child[!dir]))
                {
                    /// any one child has 2 reds in a row (LR RL) => align first , then rotate
                    node = doubleRotate(node,!dir);
                }
            }
        }
        return node;
    }

    Node* __insert(Node *node,int data)
    {
        if(node == NULL)
            return new Node(data,RED);

        bool dir = data > node->data; /// left -> 0 , right -> 1
        node->child[dir] = __insert(node->child[dir],data);

        return INSERT_FIX_UP(node,dir);
    }

    bool search(int data)
    {
        Node* ret = search(root,data);

        if(ret==NULL)
            return false;
        else
            return true;
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

        cout<<node->data<<":"<<(node->color==RED ? "r":"b");

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

    void delete_(int data)
    {
        bool ok = false;
        root = __delete(root,data,ok);
        if(root!=NULL)
            root->color = BLACK;
    }

    Node* __delete(Node *node,int data,bool &ok)
    {
        if(node == NULL)
        {
            cout<<"NULL"<<endl;
            ok = true;
        }
        else
        {
            /// found the delete key
            if(node->data == data)
            {
                /// has one child only
                if(node->child[left]==NULL || node->child[right]==NULL)
                {
                    Node* temp = NULL;
                    if(node->child[left])
                        temp = node->child[left];
                    if(node->child[right])
                        temp = node->child[right];


                    if(red(node)) /// the node is red => just delete it
                    {
                        free(node);
                        ok = true;
                    }
                    else if(red(temp)) /// only child is red => replace with that red child and recolor black . so , black balance restored
                    {
                        temp->color = BLACK;
                        free(node);
                        ok = true;
                    }

                    return temp;
                }
                else /// has 2 child => replace with inorder predecessor / successor and recurse for that
                {
                    Node *temp = getMax(node->child[left]); /// inorder predecessor : maximum value in the left subtree

                    node->data = temp->data;
                    data = temp->data; /// updating with predecessor data as this is the one to delete now
                }
            }


            bool dir = data > node->data;

            node->child[dir] = __delete(node->child[dir],data,ok); /// recurse

            if(ok==false)
            {
                node = DELETE_FIX_UP(node,dir,ok);
            }
        }

        return node;
    }

    Node* DELETE_FIX_UP(Node *node,bool dir, bool &ok)
    {
        Node *parent = node; /// saving for later red sibling fixing case
        Node *sibling = node->child[!dir];

        /// Case 1 : Red Sibling => Reduce to deterministic Black Sibling Case
        if(red(sibling))
        {
            node = rotate(node,dir);
            sibling = parent->child[!dir];
        }

        if(sibling != NULL)
        {
            /// Case 2 Part 1 : Black Sibling with only black children
            if(!red(sibling->child[left]) && !red(sibling->child[right]))
            {
                if(red(parent))
                    ok = true; /// will color it black and sibling subtree will not have imbalance

                parent->color = BLACK; /// if not ok , it will mean DOUBLE BLACK edge
                sibling->color = RED;
            }
            else /// Case 2 Part 2 : Black Sibling with not all black children
            {

                int initcol_parent = parent->color;
                bool isRedSiblingReduction = !(node==parent);

                if(red(sibling->child[!dir])) /// RR , LL
                {
                    parent = rotate(parent,dir); /// single rotation
                }
                else
                {
                    parent = doubleRotate(parent,dir); /// align and rotate
                }

                parent->color = initcol_parent; /// color will be the same as initial parent
                parent->child[left]->color = BLACK;
                parent->child[right]->color = BLACK;

                if(isRedSiblingReduction)
                {
                    node->child[dir] = parent; /// fixing the child for proper bottom up fixing later
                }
                else
                {
                    node = parent; /// usual black case
                }

                ok = true;
            }
        }

        return node;
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
//    freopen("input7.txt","r",stdin);
//    freopen("out7.txt","w",stdout);

    RBT r;

    string option;

    while(cin>>option)
    {
        int num;
        cin>>num;

        if(option=="F")
        {
            bool has = r.search(num);
            if(has)
                cout<<"True"<<endl;
            else
                cout<<"False"<<endl;
        }
        else if(option=="I")
        {
            r.insert(num);
            r.preorder();
        }
        else if(option=="D")
        {
            r.delete_(num);
            r.preorder();
        }
    }

    return 0;
}
