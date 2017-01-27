#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
  return (hashSet.insert(word)).second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  if (hashSet.find(word) == hashSet.end()){ // check if iterator is null
    return false;
  }
  return true;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
