<h1 style="text-align: center;"> # Calculating best travel routes using a Graph</h1>

The purpose of this project is to calculate the shortest paths a solar sales person can take on their typical route. To do this, this program uses a bidirectional, weighted, matrix graph. This is a version of a graph that is represented through a 2D array. Each sub-array represents a node and each value in the sub-array represents a the connections between that node and every other node. The value of each connection represents the weight of that connection. A value of 0 means there is no connection between the nodes. I created a class that has simple functions like *addWeight()* and *print()* to complete this assignment. I also added the option to use a key to represent the nodes, as I found it confusing to keep track of all the indexes. This is done by creating a string array that matches by index to the nodes in the graph. There are a few other functions added simply to make the class feel more complete, even though I do not use them for this problem.

## Algorithims Used

### Depth First Search

