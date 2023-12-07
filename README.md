# Calculating best travel routes using a Graph

*By: Kyle Riebeling
For: CIS-7 Discrete Structures Fall 23*

The purpose of this project is to calculate the shortest paths a solar sales person can take on their typical route. To do this, this program uses a bidirectional, weighted, matrix graph. This is a version of a graph that is represented through a 2D array. Each sub-array represents a node and each value in the sub-array represents a the connections between that node and every other node. The value of each connection represents the weight of that connection. A value of 0 means there is no connection between the nodes. I created a class that has simple functions like *addWeight()* and *print()* to complete this assignment. I also added the option to use a key to represent the nodes, as I found it confusing to keep track of all the indexes. This is done by creating a string array that matches by index to the nodes in the graph. There are a few other functions added simply to make the class feel more complete, even though I do not use them for this problem.

## Algorithims Used

### Depth First Search

This algorithim is used to find the shortest paths starting at each different city. It is implemented in two separate functions - *DFS()* and *DFSUtil()*. *DFS()* is simply the caller function. This function is called and initialized a new bool array that holds the visited values. The function them simply calls on *DFSUtil()*. *DFSUtil()* is the recursive function that actually does the searching. It starts by printing the node you are at. It, then, visits each node that is connected to the node you are currently at. As it visits each node, it compares all the weights to find the lowest weight and then recursively calls iteself to the node with the lowest weight that hasn't been visited already.

### Print Adjacencies

Printing adjacencies is very easy with this implementation due to the graph already being in a table structure. To print the adjacencies, it simply loops through the 2D array in the Graph class and prints each value. If using a key, which I choose to do for this project, I will also print the labels to each node. This is all done in the *print()* function.

### Prim Minimum Spanning Tree


