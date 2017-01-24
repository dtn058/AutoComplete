#include "util.h"
#include "DictionaryTrie.h"

DictionaryTrie::Node::Node(void){
  this->isWord = false;
  this->frequency = 0;
  for (int i = 0; i < 26; i++){
    this->charNode[i] = NULL;
  }
}

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  Node *curNode = &(this->root);
  bool retVal = false;
  for(std::string::iterator it=word.begin(); it!=word.end(); ++it){
  //iterate through the string
    int ascii = *it % (int)'a';  // convert all lowercase letters to 0-25
    if (!curNode->charNode[ascii]){ // check if Node exists at the loc
      Node* newNode = new Node();
      curNode->charNode[ascii] = newNode; //create a new Node and insert in arr
      curNode = curNode->charNode[ascii]; //set curNode = new inserted node
      retVal = true; //since had to insert a new char, a new word has been ins
    }else{
      curNode = curNode->charNode[ascii]; // curNode = the next char
      if((it + 1) == word.end()){  //check if at the end of the word
        curNode->isWord = true;  // recognize that its a word node
        if (curNode->frequency < freq){
          curNode->frequency = freq;  //set new frequency if larger
        } 
      }
    }
  }

  return retVal;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
  const Node *curNode = &(this->root);
  for(std::string::iterator it=word.begin(); it!=word.end(); ++it){
  //iterate through the string
    int ascii = *it % (int)'a';  // convert all lowercase letters to 0-25
    if (!curNode->charNode[ascii]){ // check if Node exists at the loc
      return false;
    }else{
      curNode = curNode->charNode[ascii]; // curNode = the next char
      if((it + 1) == word.end() && curNode->isWord){  
      //check if at the end of the word
        return true;
      }
    }
  }
}

/* Return up to num_completions of the most frequent completions
 * of the prefix, such that the completions are words in the dictionary.
 * These completions should be listed from most frequent to least.
 * If there are fewer than num_completions legal completions, this
 * function returns a vector with as many completions as possible.
 * If no completions exist, then the function returns a vector of size 0.
 * The prefix itself might be included in the returned words if the prefix
 * is a word (and is among the num_completions most frequent completions
 * of the prefix)
 */
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){}
