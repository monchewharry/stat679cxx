#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <queue>
#include "Bit_Vector.h"

using namespace std;

struct Tree {
    unsigned char data;
    int count; // sum of counts of char's in this subtree
    Tree *left;
    Tree *right;
};

//const int N_ASCII_VALUES = 128;
const size_t N_ASCII_VALUES = 256;

struct Tree_priority {
    bool operator()(const Tree *x, const Tree *y) {
        return x->count > y->count;
    }
};

void print(Tree *root, int level) {
    const int INDENTATION = 5;
    if (root) {
      print(root->right, level + 1);
      cerr << setw(level * INDENTATION) << " " << root->data <<root->count<<endl;
      print(root->left, level + 1);
    }
}

void collect_frequencies(int frequencies[], int n, const char *infile) {
    unsigned char ch;
    string FileName=infile;
    ifstream inFile(FileName.c_str());

    if (!inFile.is_open()){
        cout << "The input file could not be opened."<<endl;
    }

    for (int k = 0; k < n; k++){
      frequencies[k] = 0;//initialize
    }

    ch = inFile.get();
    while (!inFile.eof()){
       ch = toupper(ch);
       frequencies[ch]++;
       ch = inFile.get();
    }
    inFile.close();
}

Tree * build_tree_from_frequencies(int frequencies[], int n) {
    priority_queue<Tree *, vector<Tree *>, Tree_priority> pq;
    for(unsigned char ch = 'A'; ch <= 'Z'; ch++){
      if(frequencies[ch]>0){
        cout<<ch<<": "<<frequencies[ch]<<endl;
        Tree *t;
        t= new Tree;//trivial tree
        t->data=ch;
        t->count=frequencies[ch];
        pq.push(t);
      }
    }

    int code_size = pq.size();
    for (int i = 0; (unsigned)i < (unsigned)code_size-1; i++){
      Tree* tnew = new Tree;
      tnew->data='*';
      tnew->left = pq.top(); pq.pop();
      tnew->right= pq.top(); pq.pop();
      tnew->count = tnew->left->count + tnew->right->count;
      pq.push(tnew);
    }
    Tree* root = pq.top(); pq.pop();
    return root;
}


int main (int argc, char *argv[]) {
  int frequencies[N_ASCII_VALUES];
  const char *infile;//, *outfile;
  if (argc != 3) {
    cerr << "usage: " << argv[0] << " <infile> <outfile>" << endl;
    exit(0);
  }
  infile = argv[1];
  //outfile = argv[2];

  collect_frequencies(frequencies, N_ASCII_VALUES, infile);
  Tree* root =build_tree_from_frequencies(frequencies,N_ASCII_VALUES);
  //cout<< "root's count"<<root->count<<endl;
  print(root, 0);
  return 0;
}
