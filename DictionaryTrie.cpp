#include "util.h"
#include "DictionaryTrie.h"

using namespace std;
/**
 * Constructor for the Node class
 * sets everything to false, 0, and null
 */
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
        if (!curNode->isWord){
          curNode->isWord = true;  // recognize that its a word node
          retVal = true;
        }
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
    int ascii = word[i] % (int)'a';  // convert all lowercase letters to 0-25
    if( ascii == 32 ) {
      ascii = 26;
    }
    if (!curNode->charNode[ascii]){ // check if Node exists at the loc
      return false;
    }else{
      curNode = curNode->charNode[ascii]; // curNode = the next char
      if( i == (word.size()-1) && curNode->isWord){  
        //check if at the end of the word
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
  Node *curNode = &(this->root);
  std::vector<std::string> words;
  std::vector<std::string> finalres;
  std::string arbword;
  std::string::size_type i = 0;
  for(;i < prefix.size(); ++i){
    //iterate through the string
    int ascii = prefix[i] % (int)'a';  // convert all lowercase letters to 0-25
    if( ascii == 32 ) {
      ascii = 26;
    }

    if (!curNode->charNode[ascii]){ // check if Node exists at the loc
      // that means prefix isn't in trie
    }else{
      curNode = curNode->charNode[ascii];
      if(i == prefix.size()-1){

        cout << "is this node isword true?: " << curNode->isWord << endl;
        DFSPredict(curNode, arbword, prefix[i], words);

      }

    }

  }

  cout << "Size of finalres" << words.size() << endl;
    for (std::string a: words){
      cout << "Elements are: " << a << endl; // print out all words to check if vector is correct
    }

  return words;
}

void DictionaryTrie::DFSPredict(Node* n, std::string &arbword, char letter, std::vector<std::string> &words){

  if(n->isWord){
    words.push_back(arbword);
  }

  arbword.push_back(letter);
  for(int i = 0; i<27; i++){ 
    // iterate through Node aray and check if there are still nodes
    char letter = (i+'a');
    if(n->charNode[i]){
    //  if(i == 26){
     //   letter = " ";
    //  }
      DFSPredict(n->charNode[i], arbword, char(i+'a'), words); // recursively call until reach final node
    }
  }
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){

  DFSDelete(&(this->root)); // call helper
}


/**
 * Helper method for the destructor
 * recursively deletes all the nodes in trie using depth first search
 * Parameter: next node to check or delete
 */
void DictionaryTrie::DFSDelete(Node* n){

  for(int i = 0; i<27; i++){ 
    // iterate through Node aray and check if there are still nodes
    if(n->charNode[i]){
      DFSDelete((n->charNode[i])); // recursively call until reach final node
    }
  }
  //delete if it is not the root node. Prevents excessive frees
  if (n != &this->root){
    delete(n); 
  }
}
