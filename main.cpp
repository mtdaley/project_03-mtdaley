/**
 * What a fabulous docblock!
 * Yay!
 */

#include "AvlTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include <fstream>
#include <iostream>
#include <random>
#include "Prospects.h"

/**
 * Instantiate a splay tree with splayOnAdd set to boolean
 * parameter supplied. Then read through trace file, count
 * depths, and return sum of depths.
 */
float calcAverageDepth(bool splayOnAdd) {

    SplayTree<int> splayTree(splayOnAdd);

    std::ifstream fin;
    fin.open("../data/splay_trace.csv");

    if (!fin) {
        // Bad file / could not open
        std::cout << "Could not open trace file." << std::endl;
    }

    int sumOfDepths = 0;  // The cumulative sum of depths over all operations
    int operations = 0;  // The number of operations performed, i.e., add or find
    while (fin && fin.peek() != EOF) {
        std::string action;
        std::string valString;
        int value;
        char comma = ',';
        std::getline(fin, action, comma);
        std::getline(fin, valString);
        value = std::stoi(valString);

        // Add code here to add a value if the action is "add" or
        // find a value if the action is "find". Be sure to measure
        // correctly the depth of the tree on find operations and
        // to calculate the sum of depths in the variable `sumOfDepths`
        if (action == "add"){
            splayTree.add(value);
        } else if (action == "find"){
            int depth = 0;
            splayTree.find(value, depth);
            sumOfDepths += depth;
        }



        // End add code here
        operations++;
    }
    float averageDepth = (float)sumOfDepths / (float)operations;
    return averageDepth;
}

int main() {
    // Example of writing out to a file

    BinarySearchTree<int> bst1;
    bst1.add(8);
    bst1.timber();

    std::random_device rd;  // rd is short for random device

    std::vector<int> v;
    for (int i = 1; i <= 100; i++) {
        v.push_back(i);
    }

    std::ofstream outfileOrder;
    outfileOrder.open("../data/ordered.csv");
    for (int i: v){
        bst1.add(i);
        int depth = 0;
        bst1.find(i, depth);
        outfileOrder << i << "," << depth << std::endl;
    }
    outfileOrder.close();
    std::vector<int> vOrder = v;
    // Requires std::random_device rd; from above ^^^
    std::shuffle(vOrder.begin(), vOrder.end(), rd);

    BinarySearchTree<int> bst2;
    std::ofstream outFile;
    outFile.open("../data/example_output.csv");
    for (int i: vOrder){
        bst2.add(i);
        int depth = 0;
        bst2.find(i, depth);
        outFile << i << "," << depth << std::endl;
    }
    outFile.close();

    std::vector<Prospects> data;
    std::string fn = "../data/milb_stats.csv";
    loadFromFile(fn, data);
    BinarySearchTree<Prospects> bst3;
    std::ofstream pFile;
    pFile.open("../data/prospectbst.csv");
    for (Prospects p: data){
        bst3.add(p);
        int depth = 0;
        bst3.find(p, depth);
        pFile << p.getPlayerID() << "," << depth << std::endl;
    }
    pFile.close();

    AvlTree<int> avl1;
    std::ofstream avlOrder;
    avlOrder.open("../data/AVLOrdered.csv");
    for (int i: v){
        avl1.add(i);
        int depth = 0;
        avl1.find(i, depth);
        avlOrder << i << "," << depth << std::endl;
    }
    avlOrder.close();

    AvlTree<int> avl2;
    std::ofstream avlRand;
    avlRand.open("../data/AVLrand.csv");
    for (int i: vOrder){
        avl2.add(i);
        int depth = 0;
        avl2.find(i, depth);
        avlRand << i << "," << depth << std::endl;
    }
    avlRand.close();

    AvlTree<Prospects> avl3;
    std::ofstream pAvl;
    pAvl.open("../data/prospectavl.csv");
    for (Prospects p: data){
        avl3.add(p);
        int depth = 0;
        avl3.find(p, depth);
        pAvl << p.getPlayerID() << "," << depth << std::endl;
    }
    pAvl.close();

    SplayTree<int> spt1 = SplayTree<int>(false);
    std::ofstream sptOrder;
    sptOrder.open("../data/sptorder.csv");
    for (int i: v){
        spt1.add(i);
        int depth = 0;
        spt1.find(i, depth);
        sptOrder << i << "," << depth << std::endl;
    }
    sptOrder.close();

    SplayTree<int> spt2 = SplayTree<int>(false);
    std::ofstream sptRand;
    sptRand.open("../data/sptrand.csv");
    for (int i: vOrder){
        spt2.add(i);
        int depth = 0;
        spt2.find(i, depth);
        sptRand << i << "," << depth << std::endl;
    }
    sptRand.close();

    SplayTree<Prospects> spt3 = SplayTree<Prospects>(false);
    std::ofstream pSpt;
    pSpt.open("../data/sptprospect.csv");
    for (Prospects p: data){
        spt3.add(p);
        int depth = 0;
        spt3.find(p, depth);
        pSpt << p.getPlayerID() << "," << depth << std::endl;
    }
    pSpt.close();

    SplayTree<int> rand2 = SplayTree<int>(false);
    // create a spt by adding 1-100 in order
    for (int i: v){
        rand2.add(i);
    }

    std::ofstream findSpt;
    findSpt.open("../data/findspt.csv");
    // search for the ints in random order
    for (int i: vOrder){
        int depth = 0;
        rand2.find(i, depth);
        findSpt << "Search 1" << "," << i << "," << depth << std::endl;
        depth = 0;
        rand2.find(i, depth);
        findSpt << "Search 2" << "," << i << "," << depth << std::endl;
        depth = 0;
        rand2.find(i, depth);
        findSpt << "Search 3" << "," << i << "," << depth << std::endl;
        depth = 0;
        rand2.find(i, depth);
        findSpt << "Search 4" << "," << i << "," << depth << std::endl;
        depth = 0;
        rand2.find(i, depth);
        findSpt << "Search 5" << "," << i << "," << depth << std::endl;

    }
    findSpt.close();

    std::cout << std::setprecision(4);

    // Experiment #1: splay on add set to false
    float averageDepth = calcAverageDepth(false);
    std::cout << "Splay on add = false" << std::endl;
    std::cout << "Average depth = " << averageDepth << std::endl;

    // Experiment #2: splay on add set to true
    averageDepth = calcAverageDepth(true);
    std::cout << "Splay on add = true" << std::endl;
    std::cout << "Average depth = " << averageDepth << std::endl;




    return 0;

}

