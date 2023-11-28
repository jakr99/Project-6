#ifndef MYMAP_H
#define MYMAP_H

#include "TreeNode.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

template <typename K, typename V> class MyMap {
private:
  TreeNode<K, V> *root = nullptr;

  V &at_helper(TreeNode<K, V> *&rt, const K &access_key);

  int size_helper(TreeNode<K, V> *rt) const;

  void clear_helper(TreeNode<K, V> *&rt);

  void insert_helper(TreeNode<K, V> *&rt, const K &new_key, const V &new_value);

  TreeNode<K, V> *get_min(TreeNode<K, V> *rt);

  void erase_helper(TreeNode<K, V> *&rt, const K &erase_key);

  TreeNode<K, V> *find_helper(TreeNode<K, V> *rt, const K &search_key) const;

  void print_helper(TreeNode<K, V> *rt, std::string indent) const;

  // Helper Function for operator[], similar to at() except:
  // If access_key is not found, create new node with that key and return ref to
  // its value You can assume type V has default constructor available (i.e. V()
  // is valid)
  V &bracket_helper(TreeNode<K, V> *&rt, const K &access_key);

  TreeNode<K, V> *clone(const TreeNode<K, V> *rt);

public:
  MyMap();

  ~MyMap();

  MyMap(const MyMap<K, V> &source);

  MyMap<K, V> &operator=(const MyMap<K, V> &source);

  TreeNode<K, V> *&begin();

  V &at(const K &access_key);

  V &operator[](const K &access_key);

  bool empty() const;

  int size() const;

  void clear();

  void insert(const K &new_key, const V &new_value);

  void erase(const K &erase_key);

  TreeNode<K, V> *find(const K &search_key) const;

  void print() const;

  void convert_to_sorted_list(TreeNode<K, V> *&rt, std::vector<V> &sorted);
};

// Should accept a text file (for example a book) via std in
// Should build a dictionary of the counts of the characters it that book
// Do not add newlines (\n) to the dictionary (they'll mess up print)
// ./a.out <sample_input.txt should be the form of input
void get_letter_frequency(MyMap<char, int> &in_tree);

#include "MyMap.hpp"
#endif
