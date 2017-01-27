#include "util.h"
#include "DictionaryTrie.h"

using namespace std;

DictionaryTrie::Node::Node(void){
  this->isWord = false;
  this->frequency = 0;
  for (int i = 0; i < 27; i++){
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
  for(std::string::size_type i=0; i < word.size(); i++){
  //iterate through the string
    int ascii = word[i] % (int)'a';  // convert all lowercase letters to 0-25
    if( ascii == 32 ) {
      ascii = 26;
    }
    if (!curNode->charNode[ascii]){ // check if Node exists at the loc
      Node* newNode = new Node();
      curNode->charNode[ascii] = newNode; //create a new Node and insert in arr
      curNode = curNode->charNode[ascii]; //set curNode = new inserted node
      retVal = true; //since had to insert a new char, a new word has been ins
      if( i == (word.size()-1)){
        curNode->isWord = true;
        if (curNode->frequency < freq){
          curNode->frequency = freq;  //set new frequency if larger
        } 
      }
    }else{
      curNode = curNode->charNode[ascii]; // curNode = the next char
      if(i == (word.size()-1)){  //check if at the end of the word
        //cout << "sets boolean " << word[i] <<  endl;
        curNode->isWord = true;  // recognize that its a word node
        //cout << "isWord " << curNode->isWord << endl;
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
  for(std::string::size_type i = 0; i < word.size(); ++i){
  //iterate through the string
   // cout << "letter is: " << word[i] << endl;
    int ascii = word[i] % (int)'a';  // convert all lowercase letters to 0-25
    if( ascii == 32 ) {
      ascii = 26;
      //cout << "this is working" << endl;
    }
    //cout << "ascii is: " << word[i] << endl;
    if (!curNode->charNode[ascii]){ // check if Node exists at the loc
      //cout << "returning false" << endl;
      return false;
    }else{
      curNode = curNode->charNode[ascii]; // curNode = the next char
      //cout << "else statement runs" << endl;
      //cout << "i: " << i << endl;
      //cout << "word.size()-1 = " << word.size()-1 << endl;
      //cout << "curNode->isWord " << curNode->isWord << endl;
      if( i == (word.size()-1) && curNode->isWord){  
      //check if at the end of the word
        //cout << "should print true" << endl;
        return true;
      }
    }
  }
  return false;
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
DictionaryTrie::~DictionaryTrie(){

  DFSDelete(&(this->root));
}

void DictionaryTrie::DFSDelete(Node* n){

   for(int i = 0; i<27; i++){
     if(n->charNode[i]){
        DFSDelete((n->charNode[i]));
     }
    }
   if (n != &this->root){
    delete(n);
   }
  }
