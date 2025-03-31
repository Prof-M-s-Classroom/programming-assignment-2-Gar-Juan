[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Juan Garcia]`  
### **Student ID:** `[Your ID]`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)
My project implements a text-based RPG game that takes place in a mystical realm of Elderwood, and utilizes a binary decision
tree to guide the player through interactive story paths. The player makes strategic choices at pivotal moments which branch 
out into different outcomes such as encountering creatures. Each choice affects the storyline, leading to varied quests alliances
with magical beings, and encounters with the forest's dark secrets. The game emphasizes strategic decision-making, and exploration 
of a rich, fantastical world filled with both peril and wonder. The game ends when a leaf node (with '-1'as left and right children) 
is reached.

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[This program is responsible for setting up and running my text-based RPG game by loading the story from the story.txt using a decision tree to handle choices and then playing through the game with a brief introduction of the world of Elderwood using introduction.txt.
]`  
- **`GameDecisionTree.h`** → `[This file holds the main logic of the RPG Game. It defines a class that builds and manages the decision tree from the story.txt allowing the player to navigate through the game by making choices. It contains the loadStoryFromFile function to read the story from the story.txt file and organizes it into a tree structure while the play game handles the actual gameplay. Gameplay consists of guiding the player through different events based on their choices, it includes input validation and cleans up memory when the game is done.
]`  
- **`Node.h`** → `[the node,h file is pretty straight forward. It defines the basic building block for the game's decision tree. Each node holds a piece of story data and has pointers to two possible next steps (left and right), which represent the player's choices. The constructor just sets up a new node with some data and makes sure it starts with no connections. ]`  
- **`Story.h`** → `[ This file sets up the story and is responsible for holding each part of the game's story. It contains the description of what is happening, the event number to keep track of it, and two numbers that point to the next possible events according to the players choice. It also contains a basic constructor and another one that lets you fill in all the details when creating a story event.
]`  
- **`story.txt`** → `[Holds the story and it writen a special format.]
---

## **3. Decision Tree Construction**
Decision tree construction: The decision tree is built directly from story.txt by reading each line, where each entry follows the 
format: eventNumber | description | leftEventNumber | rightEventNumber, with | as the delimiter. A Story object is created for each 
event and stored in a node, which is then linked to other nodes based on its left and right event numbers. This forms the tree structure, 
and if an event has -1 for either choice, it means there's no path in that direction, marking it as a dead-end or ending in the story.
 

---

## **4. Game Traversal**
(Game Traversal: Game moves through the decision tree by starting at the root node and allowing the player to choose between two possible
paths at each iteration. The user either enters a 1 to go left or 2 to go right and the game updates the current node. If the player reaches 
a leaf node (an event with no further choices), the game ends. In cases where multiple events lead to the same outcome, different choices may 
converge to a shared node, meaning the same event description and choices appear regardless of how the player arrived there.

---

## **5. File Parsing & Data Loading**
File Parsing and Data Loading: The game reads story.txt line by line, splitting each entry using | to create Story objects stored in map promoting fast access. 
These nodes are tracked in a map to ensure proper linking. Initially, I had trouble opening story.txt, so I had to copy the full file path into 
main.cpp for it to be read by GameDecisionTree.h. At first, I overcomplicated the parsing by trying to include whitespace handling, which wasn’t 
fully necessary. I also chose | as the delimiter instead of , to avoid conflicts with potential commas in the text.

---

## **6. Debugging Process (Errors & Fixes)**
Initially, my program wasn’t reading the story.txt file when using just the filename. I ran multiple debugging tests to check if the file was 
being opened, but they failed. Then, I tested whether the directory was correct and if I could print the contents of story.txt. I ultimately fixed 
the issue by using the full file path, which confirmed that the problem was with how the file was being accessed. I had other errors that I was able
to correct but this was the most time consuming.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
You enter Elderwood's misty borders. A howl echoes investigate or seek shelter?
Choose wisely, brave traveler remember 1 = left & 2 = right
Enter 1 or 2:3

Please try again!
You enter Elderwood's misty borders. A howl echoes investigate or seek shelter?
Choose wisely, brave traveler remember 1 = left & 2 = right
Enter 1 or 2:1

A massive wolf with glowing blue eyes growls but doesn't attack.
Choose wisely, brave traveler remember 1 = left & 2 = right
Enter 1 or 2:3

Please try again!
A massive wolf with glowing blue eyes growls but doesn't attack.
Choose wisely, brave traveler remember 1 = left & 2 = right
Enter 1 or 2:2

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n)`  
- **Searching for an event in the tree** → `O(logn)`  
- **Game traversal efficiency** → `O(logn)`  

---

## **9. Edge Cases & Testing**
I tested for input validation from player if 1 or 2 are not selected it will ask the same question again without crashing. 
I also tested to see if the file's current directory was working with a code handy code segment I research on Geeksforgeeks.org.
---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)
I included an introduction.txt that gives a brief introduction of what the game is about. Its just a text file that prints at the beging of the game.
---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
