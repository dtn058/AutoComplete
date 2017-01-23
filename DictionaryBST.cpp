#include "util.h"
#include "DictionaryBST.h"

#include <string>
#include <set>

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){ }

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
  return (set.insert(word)).second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
  if (set.find(word) == set.end()){
    return false;
  }
  else{ return true; }
}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
