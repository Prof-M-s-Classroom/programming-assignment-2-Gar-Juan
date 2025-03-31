#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
//#include <unistd.h>

#include "Node.h"
#include "Story.h"

using namespace std;

template <typename T>

class GameDecisionTree {

private:
    Node<T>* root; // Starting point root of the story tree

    //unordered_map<string, Node<T>*> nodeMap;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    //Deconstructor cleans up dynamically allocated memory
   ~GameDecisionTree() {
        delete root;
    }
    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {
        // To open file using the provided filename wouldn't open, so I had to use the full path of the .txt file
        ifstream file(filename);

        /* Having trouble with reading the text file found this online to check https://www.geeksforgeeks.org/how-to-get-current-directory-in-cpp/
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != nullptr) {
            std::cout << "Current working directory: " << cwd << std::endl;
        } else {
            std::cerr << "Error getting current directory" << std::endl;
        }
        */

        //Check if file is opened print error statment
        if (!file.is_open()) {
            cerr << "File " << filename << " could not be opened." << endl;
            return;
        }else {
            //cerr << "File " << filename << " opened." << endl;
        }

        // Map to temporarily store all story nodes using their event number
        map<int, Node<T>*> nodeMap;

        // Declare a string variable to store each line read from the file
        string line;

        //reads one line at a time.
        while (getline(file, line)) {

            istringstream iss(line); //initializes the istringstream object with the string data
            string text, desc, leftNum, rightNum;// eventNumber -- leftEventNumber -- rightEventNumber

            // Skip empty lines
            //if (line.empty()) continue;

            // Trim any leading/trailing spaces from the description
           // desc = trim(desc); // Implement your trim function or use a library that supports trimming whitespace.

            getline(iss, text, delimiter);
            // Parse the line using the delimiter
            getline(iss, desc, delimiter);
            getline(iss, leftNum, delimiter);
            getline(iss, rightNum, delimiter);

            // Convert string integers using stoi function
            int id = stoi(text);
            int left = stoi(leftNum);
            int right = stoi(rightNum);

            // Create a story object
            T story(desc, id, left, right);
            //Contain the Story object in a Node
            auto* newNode = new Node<T>(story);

            // Map the node to its event number
            nodeMap[id] = newNode;
        }

        // Connect each node to its left and right child (linking branches of the tree)
        typename map<int, Node<T>*>::iterator it; //READ ONLY ACCESS

        for (it = nodeMap.begin(); it != nodeMap.end(); ++it) {
            Node<T>* curr = it->second;

            int leftID = curr->data.leftEventNumber;
            int rightID = curr->data.rightEventNumber;

            if (nodeMap.count(leftID) > 0) {
                curr->left = nodeMap[leftID];
            }

            if (nodeMap.count(rightID) > 0) {
                curr->right = nodeMap[rightID];
            }
        }
        // Look into using auto
        //  1 will be root node
        if (nodeMap.count(1) > 0) {
            root = nodeMap[1];
        } else {
            root = nullptr;
        }
        // Close file when reading is done
        file.close();
    }

    void playGame() {
        // Display the introduction text once before the game starts
        ifstream introFile(R"(C:\Users\Juan Garcia\Documents\programming-assignment-2-Gar-Juan\introduction.txt)");
        if (introFile.is_open()) {
            string line;
            while (getline(introFile, line)) {
                cout << line << std::endl;  // Print each line of the introduction
            }
            introFile.close();  // Close the file after reading
        } else {
            cout << "Failed to open introduction.txt." << endl;
        }

        if (root == nullptr) {
            cout << "No story populated the tree." << endl;
            return;
        }

        // Start the game @ root
        Node<T>* curr = root;

        // Continue the traversal until currnt = nullptr
        while (curr != nullptr) {

            cout << curr->data.description << endl;

            // When we reach the end of story which is two null child nodes this will print out the text
            if (curr->left == nullptr && curr->right == nullptr) {
                cout << "[Your choices will go with you. The end]" << endl;
                break;
            }
            // Ask for user input 1 to go left and 2 to go right
            int choice;
            cout << "Choose wisely, brave traveler remember 1 = left & 2 = right" << endl;
            cout << "Enter 1 or 2: ";
            cin >> choice;

            // when user input recived will move to next node
            if (choice == 1 && curr->left != nullptr) {

                curr= curr->left;
            } else if (choice == 2 && curr->right != nullptr) {
                curr= curr->right;
            } else {
                // Error validation for user input
                cout << "Please try again!  " << endl;
            }
        }
    }
};
#endif // GAMEDECISIONTREE_H