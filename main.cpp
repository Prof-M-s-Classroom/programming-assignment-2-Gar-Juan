#include <iostream>
#include <string>
#include "GameDecisionTree.h"

using namespace std;

int main() {
    GameDecisionTree<Story> myGame;

    string filename = "C:\\Users\\Juan Garcia\\Documents\\programming-assignment-2-Gar-Juan\\story.txt";  // Specify the input file
    char delimiter = '|';                // '|' is the delimiter, change if needed
    // string filename2 = "C:\\Users\\Juan Garcia\\Documents\\programming-assignment-2-Gar-Juan\\introduction.txt";
    // Load the story data from the file
    myGame.loadStoryFromFile(filename, delimiter);

    // Start the game
    myGame.playGame();


    return 0;
}