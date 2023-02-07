#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;

  ListNode(int val)
  {
    this->val = val;
    this->next = nullptr;
  }
};

struct LinkedList
{
  int size;
  ListNode *head;
  ListNode *tail;

  LinkedList()
  {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
  }

  void push_back(int val)
  {
    this->size++;
    ListNode *temp = new ListNode(val);
    if (this->head == nullptr)
    {
      this->head = temp;
      this->tail = temp;
    }
    else
    {
      this->tail->next = temp;
      this->tail = temp;
    }
  }

  void print()
  {
    ListNode *cur = this->head;
    while (cur != nullptr)
    {
      cout << cur->val << " ";
      cur = cur->next;
    }
    cout << endl;
  }

  void solve(int k) {
    ListNode *cur = this->head;
    int mini = 99999, index = 0, answer;
    while (cur != nullptr) {
      if (abs(k - cur->val) < mini) {
        mini = abs(k - cur->val);
        answer = index;
      }
      index++;
      cur = cur->next;
    }
    cout << answer;
  }
};

int main()
{
  int n;
  cin >> n;
  LinkedList ll;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    ll.push_back(m);
  }
  int k;
  cin >> k;
  ll.solve(k);
  return 0;
}