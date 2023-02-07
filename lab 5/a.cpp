#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct MinHeap
{
    vector<ll> heap;

    ll parent(ll i)
    {
        return (i - 1) / 2;
    }
    ll left(ll i)
    {
        return 2 * i + 1;
    }
    ll right(ll i)
    {
        return 2 * i + 2;
    }
    void insert(ll value)
    {
        this->heap.push_back(value);
        ll i = this->heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] > this->heap[i])
        {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    ll extractMin()
    {
        if (this->heap.size() == 0)
            return INT_MAX;
        if (this->heap.size() == 1)
        {
            ll root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        ll root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }
    void heapify(ll i)
    {
        ll l = this->left(i);
        ll r = this->right(i);
        ll smallest = i;
        if (l < this->heap.size() && this->heap[l] < this->heap[smallest])
            smallest = l;
        if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(this->heap[i], this->heap[smallest]);
            this->heapify(smallest);
        }
    }

    ll getSize()
    {
        return heap.size();
    }
};

int main()
{
    MinHeap heap;
    ll n;
    cin >> n;
    ll ar[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    for (ll i = 0; i < n; i++)
    {
        heap.insert(ar[i]);
    }
    ll answer = 0;
    while (heap.getSize() > 1)
    {
        ll first = heap.extractMin();
        ll second = heap.extractMin();
        answer += first + second;
        heap.insert(first + second);
    }
    cout << answer;
    return 0;
}