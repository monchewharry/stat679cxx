// compress.cxx: Collect character frequencies from infile, make
// Huffman code tree from frequencies, make code from tree, use code
// to compress infile. Write tree, newline, and Bit_Vector of
// compressed infile to outfile.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <queue>      // STL, has priority_queue<T>
#include "Bit_Vector.h"

using namespace std;

//const int N_ASCII_VALUES = 128;
const size_t N_ASCII_VALUES = 256;

struct Tree {
    unsigned char data;
    int count; // sum of counts of char's in this subtree
    Tree *left;
    Tree *right;
};

// An instantiation of this struct is a "function object"; I don't
// quite understand this, but it's in Stroustrup's book and the STL.
struct Tree_priority {
    bool operator()(const Tree *x, const Tree *y) {
	return x->count > y->count;
    }
};

// Print tree at which root points in backwards inorder, which leads
// to a tree a person can read in the shell by turning his or her head
// to the left. Start by indenting level spaces.
void print(Tree *root, int level) {
    const int INDENTATION = 5;

    if (root) {
	print(root->right, level + 1);
	cerr << setw(level * INDENTATION) << " " << root->data << endl;
	print(root->left, level + 1);
    }
}

// Collect character counts from file, storing them in frequencies, an
// array of length n.
void collect_frequencies(int frequencies[], int n, const char *file) {
    unsigned char ch;
    string FileName=file;
    ifstream inFile(FileName.c_str());

    if (!inFile.is_open()){
        cout << "The input file could not be opened."<<endl;
        return 1;
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
    return 0;
}

// Return pointer to root of Huffman code tree made from character counts in frequencies, an array of size n.
Tree * build_tree_from_frequencies(int frequencies[], int n) {
    priority_queue<Tree *, vector<Tree *>, Tree_priority> pq;
    Tree *root = 0; // 0 is wrong, but I want this program to compile.
    for(unsigned char ch = 'A'; ch <= 'Z'; ch++){
        Tree *t;
        t= new Tree;//trivial tree
        t->data=ch;
        t->count=frequencies[ch];
        pq.push(t)
    }
    delete t;
    
    return root;
}

// Recursively traverse tree at which root points, building up code by
// adding '0' at each left branch or '1' at each right branch. At each
// leaf, write code into code_words[], an array of length n.
void write_code(const Tree *root, string code_words[], size_t n, string code) {
    // ...
}

// Recursively dump tree at which root points to stream ofs.
void preorder(Tree *root, ostream &ofs) {
    // ...
}

// Use the Huffman code tree at which root points to compress data in
// infile. Write tree and bits into outfile.
void compress_data(Tree *root, const char *infile, const char *outfile) {
    string code_words[N_ASCII_VALUES];
    // ...
    write_code(root, code_words, N_ASCII_VALUES, "");
    // ...
}

// Recursively de-allocate memory used by tree at which root points.
void destroy_tree(Tree *root) {
    if (root) {
	destroy_tree(root->left);
	destroy_tree(root->right);
	delete root;
    }
}

// (This comment is repeated from the top of the file, which is not a
// great idea.)
// 
//  Collect character frequencies from infile, make Huffman code tree
// from frequencies, make code from tree, use code to compress
// infile. Write tree, newline, and Bit_Vector of compressed infile to
// outfile.
int main(int argc, char *argv[]) {
    int frequencies[N_ASCII_VALUES];
    const char *infile, *outfile;

    if (argc != 3) {
	cerr << "usage: " << argv[0] << " <infile> <outfile>" << endl;
	exit(0);
    }
    infile = argv[1];
    outfile = argv[2];
    collect_frequencies(frequencies, N_ASCII_VALUES, infile);
    Tree *root = build_tree_from_frequencies(frequencies, N_ASCII_VALUES);
//    print(root, 0); // for debugging
    compress_data(root, infile, outfile);
    destroy_tree(root);

    return 0;
}
