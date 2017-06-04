#include <iostream>
#include <fstream>
#include <algorithm>
#include "dynmatrix.h"

using namespace std;

// construct a string representation 

void usage() {
  cerr << "Usage: upgma species.txt" << endl;
}

int main( int argc, char *argv[] ) {
  if( argc != 2 ) {
    usage();
    return 0;
  }

  // let's start with empty DynMatrix:
  ClusterNode* head = NULL; 
  ClusterNode* tail = NULL;
  int n = 0; // number of species
  ifstream fin( argv[1] );
  if( fin.is_open() ) {
    // read species:
    string species;
    while ((fin.peek() != '\n') && (fin >> species)) {
      n++;
     // addCluster adds empty species into DynMatrix 
      addCluster(head, tail, species);
    }
    // Adding distances to the DynMatrix initialized to zeroes
    ClusterNode *node = head;
    for (int i=0; i<n && fin; i++) {
      DistanceNode *newDistance = node->row;
      for (int j=0; j<n && fin; j++) {
        double d;
        fin >> d;

        newDistance->distance = d;

        newDistance = newDistance->nextInRow;
      }
    node  = node->next;
    }
    fin.close();
  }
  // Run UPGMA until there is only one node left
  int j = 1;
  while (head->next) {
    cout << "---------------Printing UPGMA Round " << j << " (by rows)---------------" << endl;
    printRowByRow(head);
    cout << "--------------------------------------------------------------" << endl;
   
    cout << "---------------Printing UPGMA Round " << j << " (by columns)------------" << endl;
    printColumnByColumn(head);
    cout << "--------------------------------------------------------------" << endl;
    
    UPGMA(head,tail);

    j++;
  }
  // Print out name of last node
  if (head) {
    cout  << head->name << endl;
  }
  // BONUS (optional): print the tree in a nice way

  return 0;
}
