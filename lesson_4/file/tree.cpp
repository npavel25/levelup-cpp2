#include "tree.h"
#include <iostream>
//Tree* root;

namespace My {

Tree::Tree()
: count(0)
, lnode(nullptr)
, rnode(nullptr)
{
    word.clear();
}

Tree::Tree(const Tree& t)
: word(t.word)
, count(t.count)
, lnode(t.lnode)
, rnode(t.rnode)
{}

Tree::Tree(const String& s)
: word(s)
, count(1)
, lnode(nullptr)
, rnode(nullptr)
{}

void Tree::insert(const String& s)
{
    if(word.empty())
    {
        word = s;
        ++count;
    }
    else
    {
        if (s < word)
        {
            if(lnode) lnode->insert(s);
            else 
            {
                Tree* newNode = new Tree(s);
                lnode = newNode;
            }
        }
        else if (s == word)
        {
            ++count;
        }
        
        else // s > word
        {
            if(rnode) rnode->insert(s);
            else
            {
                Tree* newNode =  new Tree(s);
                rnode = newNode;

            }
        }

    }
}
Int Tree::find(const String& s)
{
    if(word.empty() || word == s)
        return count;
    
    if( s < word)
    {
        if(lnode) return lnode->find(s);
        else return 0;
    }

    if( s > word)
    {
        if(rnode) return rnode->find(s);
        else return 0;
    }
}

void Tree::print()
{
    //std::cout << "----------------------------------------------------------" <<std::endl;
    std::cout << word << ": " << count << std::endl;
    if(lnode) lnode->print();
    if(rnode) rnode->print();
}
}