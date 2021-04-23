#include <iostream>
#include <string>

using namespace std;

struct node {
  int value;
  node * next;
};

class linked_list {
private:
  node * head, * tail;
public:
  linked_list() {
    head = NULL;
    tail = NULL;
  }

  node * get_head() {
    return head;
  }

  void insert_tail(int v) {
    node * p = new node();
    p -> value = v;
    p -> next = NULL;

    if (head == NULL) {
      head = p;
      tail = p;
    }
    else {
      tail -> next = p;
      tail = p;
    }
  }

  void insert_head(int v) {
    node * p = new node();
    p -> value = v;
    p -> next = head;
    head = p;
  }

  void print() {
    node * current = head;
    while (current != NULL) {
      cout << current -> value << " -> ";
      current = current -> next;
    }
    cout << "NULL" << endl;
  }

  void reverse() {
    linked_list new_list;
    node * current = head;
    while (current != NULL) {
      new_list.insert_head(current -> value);
      current = current -> next;
    }
    head = new_list.get_head();
  }
};

linked_list generate_linked_list(int n) {
  string ns = to_string(n);
  int ns_size = ns.size();

  linked_list l;

  while (ns.size() > 0) {
    int substring_length = ns.size() > 3 ? 3 : ns.size();
    int cut_index = ns.size() - substring_length;
    string substring = ns.substr(cut_index);

    if (ns.size() > 3) ns = ns.substr(0, cut_index);
    else ns = "";

    int v = stoi(substring);

    l.insert_tail(v);
  }

  return l;
}

linked_list add(linked_list list1, linked_list list2) {
  linked_list sum_list;

  node * list1_current = list1.get_head();
  node * list2_current = list2.get_head();

  int carry_forward = 0;

  while (list1_current != NULL || list2_current != NULL) {
    int value1 = list1_current != NULL ? list1_current -> value : 0;
    int value2 = list2_current != NULL ? list2_current -> value : 0;

    int node_sum = value1 + value2 + carry_forward;

    if (node_sum >= 1000) {
      node_sum -= 1000;
      carry_forward = 1;
    } else {
      carry_forward = 0;
    }

    sum_list.insert_head(node_sum);

    list1_current = list1_current != NULL ? list1_current -> next : NULL;
    list2_current = list2_current != NULL ? list2_current -> next : NULL;
  }

  if (carry_forward == 1) sum_list.insert_head(1);

  return sum_list;
}

string merge_list(linked_list list) {
  string s = "";

  node * current = list.get_head();
  bool is_head = current -> next != NULL;

  while (current != NULL) {
    string substring = to_string(current -> value);
    int missing_zero_count = 3 - substring.size();

    if (!is_head) {
      for (int i = 0; i < missing_zero_count; i++) {
        substring = '0' + substring;
      }
    }

    s += substring;

    current = current -> next;
    is_head = false;
  }

  return s;
}

int main() {
  int n1, n2;
  cin >> n1;
  cin >> n2;

  linked_list list1 = generate_linked_list(n1);
  linked_list list2 = generate_linked_list(n2);

  linked_list sum_list = add(list1, list2);

  string sum_str = merge_list(sum_list);

  cout << "sum: " << sum_str << endl;
}
