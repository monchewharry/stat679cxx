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

    for (int k = 0; (unsigned) k < (unsigned)n; k++){
      frequencies[k] = 0;//initialize
    }

    ch = inFile.get();
    while (!inFile.eof()){
       frequencies[ch]++;
       ch = inFile.get();
    }
    inFile.close();
}

Tree * build_tree_from_frequencies(int frequencies[], int n) {
    priority_queue<Tree *, vector<Tree *>, Tree_priority> pq;
    for(int k = 0; (unsigned) k < (unsigned)n; k++){
      if(frequencies[k]>0){
        //cout<<(char)k<<":"<<frequencies[k]<<" ";
        Tree* t= new Tree;//trivial tree
        t->data=(char)k;
        t->count=frequencies[k];
        t->left=NULL;
        t->right=NULL;
        pq.push(t);
      }
    }
    cout<<endl;

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


// Recursively traverse tree at which root points, building up code by
// adding '0' at each left branch or '1' at each right branch. At each
// leaf, write code into code_words[], an array of length n.

void write_code(const Tree *root, string code_words[],string star) {
  if(root){
    if(root->left){
      write_code(root->left,code_words,star+"0");
      write_code(root->right,code_words,star+"1");}
    else {code_words[root->data] = star;}

  }
}

// Recursively dump tree at which root points to stream ofs.
void preorder(Tree *root, ostream &ofs) {
    if(root->left){
      ofs<<"\\*";
      preorder(root->left,ofs);
      preorder(root->right,ofs);
    }
    else{ofs<<root->data;}
}

// Use the Huffman code tree at which root points to compress data in
// infile. Write tree and bits into outfile.
void compress_data(Tree *root, const char *infile, size_t n,const char *outfile) {
    string code_words[N_ASCII_VALUES];
    for(int k = 0; (unsigned) k < (unsigned)n; k++){
      code_words[k] = "";//initialize
    }
    write_code(root, code_words, "");
    /*for(int k = 0; (unsigned) k < (unsigned)n; k++){
      if(code_words[k]==""){}
      else {cout<<(char)k<<":"<<code_words[k]<<" ";}
    }
    cout<<endl;*/

    string huffmancode="";
    string inFileName=infile;
    string outFileName=outfile;
    ifstream inFile(inFileName.c_str());
    ofstream outFile(outFileName.c_str());

    unsigned char ch;
    ch = inFile.get();
    
    while (!inFile.eof()){
       huffmancode+=code_words[ch];
       ch = inFile.get();
    }
    inFile.close();

    preorder(root,outFile);//dumped tree
    outFile<<endl;
    int value ;
    Bit_Vector bits; 
    for(int i; (unsigned)i<(unsigned)huffmancode.length();i++){
      value = huffmancode[i] - '0';
      bits.push_back(value);
    }
    cout<<"bits.size "<<bits.size()<<endl;
    bits.write(outFile);
    cout<<"compress data done!"<<endl;
    outFile.close();
}



int main (int argc, char *argv[]) {
  int frequencies[N_ASCII_VALUES];
  const char *infile, *outfile;
  if (argc != 3) {
    cerr << "usage: " << argv[0] << " <infile> <outfile>" << endl;
    exit(0);
  }
  infile = argv[1];
  outfile = argv[2];

  collect_frequencies(frequencies, N_ASCII_VALUES, infile);
  Tree* root =build_tree_from_frequencies(frequencies,N_ASCII_VALUES);
  //print(root, 0);
  compress_data(root,infile,N_ASCII_VALUES,outfile);
  return 0;
}
