#include <iostream>
#include "node.h"

using namespace std;

double water(int n) {
  if (n == 0) {
    return 10;
  }
  else {
    return (water(n-1)/2) + 1;
  }
}

bool isSorted(int a[], int n) {
  if (n < 2) {
    return a[0] <= a[1];
  }
  else {
    if (a[n - 2] > a[n - 1]) {
      return false;
    }
    else {
      return isSorted(a, n - 1);
    }
  }
}

int main() {
  cout<<water(1)<<endl;

  int a[4] = {1, 2, 3, 4};
  cout<<isSorted(a, 4)<<endl;

  node *head = new node(4, nullptr); node *tail(head);
  node *temp;
  temp = new node(1, nullptr); tail->set_link(temp);
  tail = temp;
  head = new node(1, head); head = new node(3, head);
  temp = new node(5, nullptr); tail->set_link(temp);
  tail = temp;

  cout<<list_index(head, 1)<<endl;

  cout<<list_at(head, 2)->data()<<endl;
  

  return 0;
}
