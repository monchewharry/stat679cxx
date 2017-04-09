// decompress.cxx: Read input from file containing prefix tree,
// newline, and Bit_Vector of encoded data. Write decoded data to new
// file.

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cstdlib>
#include <sstream>
#include "Bit_Vector.h"

using namespace std;

struct Tree {
    string data;
    Tree *left;
    Tree *right;
};

void print(Tree *root, int level) {
    const int INDENTATION = 5;

    if (root) {
	print(root->right, level + 1);
	cerr << setw(level * INDENTATION) << " " << root->data << endl;
	print(root->left, level + 1);
    }
}

// Recursively build a tree by reading characters (where the
// two-character sequence "\*" denotes an internal node and any other
// character denotes a leaf) from stream ifs. Return a pointer to the
// tree's root. (Hint: Do not use a loop! Trust recursion.)
Tree* maketree(ifstream &ifs,int nl=0) {
    Tree *p = new Tree;

    string ch;
    ch=ifs.get();
    if(ch=="\n"){nl++;}

    if(nl<=1){//jump the \n in the content      
        if(ch=="\\" && ifs.get() =='*'){  
            p->data = '*';
            p->left=maketree(ifs,nl);//go deeper
            p->right=maketree(ifs,nl);  
        }
        else{
            p->data = ch;
            p->left=NULL;//no deeper
            p->right=NULL;
        }
    }
    else{ p=NULL;}//ending by the \n at the end of dump tree

    return p;
}

// Given the Huffman code tree at which root points, read a compressed
// file from stream ifs and write its decompressed version to ofs.
void decompress(Tree *root, ifstream &ifs, ofstream &ofs) {
    assert(ifs.good());
    Bit_Vector moreBits;
    moreBits.read(ifs); 
    size_t n = moreBits.size(); 
    Tree *t = root; 
    for (size_t i = 0; i < n; i++) {
        string data=t->data;
        if(moreBits[i]==0){t=t->left;}
        else{t=t->right;}
        if(!t){
            ofs<<data;t=root;
            if(moreBits[i]==0){t=t->left;}
            else{t=t->right;}
        }
    }     
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
// Read input from file containing prefix tree, newline, and
// Bit_Vector of encoded data. Write decoded data to new file.
int main(int argc, char *argv[]) {
    if (argc != 3) {
	cerr << "usage: " << argv[0] << " <infile> <outfile>" << endl;
	exit(0);
    }

    ifstream ifs(argv[1]);
    assert(ifs);
    ofstream ofs(argv[2]);
    assert(ofs);
    //maketree(ifs);
    Tree *root = maketree(ifs);
    //cout<<"print the tree"<<endl;
    //print(root,0);

    decompress(root,ifs,ofs);
    ifs.close();
    ofs.close();
    destroy_tree(root);
    return 0;
}
