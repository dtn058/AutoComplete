#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#include <fstream>
#define LETTERS 26
using namespace std;

void isFalse(std::string word);
void testFind(vector<std::string> words);

int main(int argc, char** argv)
{

  //Initialize words
  vector<std::string> words;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  //initialize nonwords
  set<string> nope;
  set<string>::iterator nit;
  set<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  int t_bst, t_ht, tt;

  words.push_back("harrys");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");
  words.push_back("har rys");
  words.push_back("auto complete");
  words.push_back("har");
  
  
  cout << "Inserting into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";

      if(!t_bst)
	    {
	      cout << "failed for DictionaryBST... ";
	    }
      if(!t_ht)
	    {
	      cout << "failed for DictionaryHashset... ";
	    }
      if(!tt)
	    {
	      cout << "failed for DictionaryTrie... ";
    	}
      if(t_bst && t_ht && tt)
	    {
	     cout << "PASSED! :D ";
	    }
      cout << endl;
    }
        for (std::string a: words){
          dt.insert(a,20);
          if (!dt.find(a)){
            cout << "failed words vector: "<< a << endl;
          }
      }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

 
  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  
/*You are supposed to add more test cases in this file */
  //test find method
  testFind(words);

  cout << "Trying find on variations of 'harry' (h, ha, harr, harrys)" << endl;
  if(dt.find("h")){isFalse("DictionaryTrie's find");}
  if(dt.find("ha")){isFalse("DictionaryTrie's find");}
  if(dt.find("harr")){isFalse("DictionaryTrie's find");}
  if(dt.find("harrys ")){isFalse("DictionaryTrie's find");}
  cout << "Variations are not in the trie" << endl; 

  //@@@@@Starting here reading in dictionaries@@@@@
  cout << endl;
  cout << endl;
  cout << "READING IN DICTIONARIES" << endl;

  // open stream
  ifstream in;
  in.open(argv[1]);

  if (!in.is_open()){ // check if file is opening
    cout << "Invalid input file. No file was opened" << endl;
    return -1;
  }
  else{  
    vector<std::string> vect;
    DictionaryTrie trie;
    DictionaryBST bst;
    DictionaryHashtable hash;

    Utils::load_vector(vect, in);
    in.close();
    in.open(argv[1]);
    
    cout << "vector: " << endl;
    for (std::string a: vect){
      cout << a << endl; // print out all words to check if vector is correct
    }
    // load into the BST
    Utils::load_dict(bst, in);
    in.close();
    in.open(argv[1]);
    // load int the Hashtable
    Utils::load_dict(hash, in);
    in.close();
    in.open(argv[1]);
    //load into the Trie
    Utils::load_dict(trie, in);
    in.close();
    // check if trie is working
    for (std::string a: vect){
      if(!trie.find(a)){
        cout << "word messed up: " << a << endl;
      }
      
    }

  }
  // want to make it so you can't put in special characters (ascii <95 etc)
  return 0;
}

void isFalse(std::string word){
 cout << "The following method is NOT WORKING: " << word;
}

void testFind(vector<std::string> words){

  cout << "**Testing find with our cases** \n";
  
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;

  wit = words.begin();
  wen = words.end();
  bool bst,hash,trie;
  for(; wit != wen; ++wit){

    cout << "Testing find on bst/ht/dt with word: " << *wit;
    bst = d_bst.find(*wit);
    hash = d_ht.find(*wit);
    trie = dt.find(*wit);
    
    if(bst)
       {
          isFalse("Find for BST");
        }
      if(hash)
        {
          isFalse("Find for HashTable");
        }
      if(trie)
        {
          isFalse("Find for Trie");
        }
      if(!bst && !hash && !trie)
        {
          cout << "-- passed test ";
        }
      cout << endl;
  }

  cout << endl;
  cout << endl;

}


