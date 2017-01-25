#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;

void isFalse(std::string word);
void isTrue(std::string word);
void testFind();

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

  cout << "**Testing find with our cases** \n";
  
  DictionaryBST test_bst;
  DictionaryHashtable test_ht;
  DictionaryTrie test_dt;

  wit = words.begin();
  wen = words.end();
  bool bst,hash,trie;
  for(; wit != wen; ++wit){

    cout << "Testing find on bst/ht/dt with word: " << *wit;
    bst = test_bst.find(*wit);
    hash = test_ht.find(*wit);
    trie = test_dt.find(*wit);
    
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
  if(dt.find("h")){isFalse("DictionaryTrie's find");}
  if(dt.find("ha")){isFalse("DictionaryTrie's find");}
  if(dt.find("harr")){isFalse("DictionaryTrie's find");}
  if(dt.find("harrys ")){isFalse("DictionaryTrie's find");}    

  // want to make it so you can't put in special characters (ascii <95 etc)
  return 0;
}

void isFalse(std::string word){
 cout << "The following method is NOT WORKING: " << word;
}

void isTrue(std::string word){
 cout << "The following method is TRUE: " << word << endl;
}



