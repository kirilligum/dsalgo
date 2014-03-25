#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <limits>

using namespace std;

struct node{
  int val;
  node(int val):val(val) {}
  node* left = nullptr;
  node* right = nullptr;
};

template <
  typename t
> void print (t* n) {
  if(n==nullptr) return;
  cout << "(";
  print(n->left);
  cout << n->val;
  print(n->right);
  cout << ")";
}

void find_wrong_pairs(node * a, int min, int max){
  if(a==nullptr) return;
  if(a->val<max) {
    find_wrong_pairs(a->left,min,a->val);
  } else {
    cout << a->val << ">=" << max << endl;
  }
  if(min<a->val) {
    find_wrong_pairs(a->right,a->val,max);
  } else {
    cout << min << ">=" << a->val << endl;
  }
}

int main(int argc, char const *argv[]) {
  cout << " hi \n";
  node * a = new node(5);
  node * b = new node(10);
  node * c = new node(14);
  node * d = new node(6);
  node * e = new node(3);
  a->left = b;
  a->right = c;
  b->left = d;
  c->right = e;
  print(a); cout << endl;
  find_wrong_pairs(a,numeric_limits<int>::min(),numeric_limits<int>::max());
  delete a;
  return 0;
}
