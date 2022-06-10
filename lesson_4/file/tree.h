#ifndef TREE_H
#define TREE_H

#include<string>

namespace My {

typedef std::string String;
typedef int Int;

class Tree
{
public:
    Tree();
    Tree(const Tree& t);
    Tree(const String& s);

    void insert(const String& s);
    Int find(const String& s);
    void print();    

private:
    String word;
    Int count;
    Tree* lnode;
    Tree* rnode;
};

}
#endif