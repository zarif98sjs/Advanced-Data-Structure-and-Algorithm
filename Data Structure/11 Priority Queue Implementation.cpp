
/**

Priority Queue Implementation

P.S : Did this a L2T1 Offline

**/

/** Which of the favors of your Lord will you deny ? **/

#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y);

class Priority_Queue
{
    int *ara;
    int max_size;
    int heap_size;
public:

    Priority_Queue()
    {
        this->max_size = 10;
        heap_size = 0;
        ara = new int[max_size];
    }

    Priority_Queue(int max_size)
    {
        this->max_size = max_size;
        heap_size = 0;
        ara = new int[max_size];
    }

    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return (2*i + 1);
    }
    int right(int i)
    {
        return (2*i + 2);
    }

    void MaxHeapify(int );

    void Insert(int k);

    int FindMax()
    {
        return ara[0];
    }
    int ExtractMax();

    void IncreaseKey(int i, int new_val);
    void DecreaseKey(int i, int new_val);

    void PrintHeap();
    void resize();
};


void Priority_Queue::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && ara[l] > ara[i])
        largest = l;
    if (r < heap_size && ara[r] > ara[largest])
        largest = r;
    if (largest != i)
    {
        swap(&ara[i], &ara[largest]);
        MaxHeapify(largest);
    }
}

void Priority_Queue::resize()
{
    max_size+=10;

    int *temp;
    temp = new int[max_size];

    for(int i=0; i<heap_size; i++)
        temp[i]=ara[i];

    delete[] ara;
    ara = temp;
}

void Priority_Queue::Insert(int k)
{
    heap_size++;
    if (heap_size == max_size)
    {
        resize();
    }
    int i = heap_size - 1;
    ara[i] = k;

    //Fix the min heap property if it is violated
    while (i != 0 && ara[parent(i)] < ara[i])
    {
        swap(&ara[i], &ara[parent(i)]);
        i = parent(i);
    }
}

void Priority_Queue::IncreaseKey(int i, int new_val)
{
    if(i > heap_size)
    {
        cout<<"Value of index is not within range"<<endl;
        return;
    }
    else if(new_val<ara[i])
    {
        cout<<"New value is smaller than current value"<<endl;
        return;
    }
    //cout<<"Deleted value : "<<ara[i]<<endl;
    ara[i] = new_val;
    while (i != 0 && ara[parent(i)] < ara[i])
    {
        swap(&ara[i], &ara[parent(i)]);
        i = parent(i);
    }
}

void Priority_Queue::DecreaseKey(int i, int new_val)
{
    if(i > heap_size)
    {
        cout<<"Value of index is not within range"<<endl;
        return;
    }
    else if(new_val>ara[i])
    {
        cout<<"New value is greater than current value"<<endl;
        return;
    }

    ara[i] = new_val;
    MaxHeapify(i);
}

int Priority_Queue::ExtractMax()
{
    if (heap_size <= 0)
        return INT_MIN;
    if (heap_size == 1)
    {
        heap_size--;
        return ara[0];
    }

    int root = ara[0];
    ara[0] = ara[heap_size-1];
    heap_size--;
    MaxHeapify(0);

    return root;
}

void Priority_Queue::PrintHeap()
{
    for(int i=0; i<heap_size; i++)
        cout<<ara[i]<<" ";
    cout<<endl;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    Priority_Queue pq(11);
    while(1)
    {
        printf("1. Insert.      \t\t 4. Increase Key. \n");
        printf("2. Find Max.    \t\t 5. Decrease Key. \n");
        printf("3. Extract Max. \t\t 6. Print Heap. \n");
        printf("7. Exit. \n");

        //printf("4. (Add from homework). 5. Print Graph  6. Exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u;
            cout<<"Element to insert : ";
            cin>>u;
            pq.Insert(u);

        }
        else if(ch==2)
        {
            cout<<"Max element is : "<<pq.FindMax()<<endl;
        }
        else if(ch==3)
        {
            int el = pq.ExtractMax();
            if(el == INT_MIN) cout<<"No element in the priority queue."<<endl;
            else cout<<"Extracted max element is : "<<el<<endl;
        }
        else if(ch==4)
        {
            int idx,val;
            cout<<"Index : ";
            cin>>idx;
            cout<<"New increased value : ";
            cin>>val;
            pq.IncreaseKey(idx,val);
        }
        else if(ch==5)
        {
            int idx,val;
            cout<<"Index : ";
            cin>>idx;
            cout<<"New decreased value : ";
            cin>>val;
            pq.DecreaseKey(idx,val);
        }
        else if(ch==6)
        {
            pq.PrintHeap();
        }
        else if(ch==7)
        {
            break;
        }

    }
    return 0;
}

