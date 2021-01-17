# My first IOI problem attempt!  
Accidentally solved subtask 5 when doing subtask 4 xd  

__Subtask 1__  
This is just simply creating a tree - connect all nodes to a single "root" node, create a straight line, etc.  

__Subtask 2__
Now, we have a collection of connected components. Each connected component has exactly one path from each node to every other node, so each connected component is a tree. Make sure to check whether merging nodes results in nodes that shouldn't have any paths between them to end up in the same component.  

__Subtask 3__
Here, we have another colleciton of connected components in which every node within a component has exactly two paths to each other node. In other words, each connected component is a cycle. Again, check to make sure merging nodes doesn't result in paths being created between nodes that shouldn't share any paths, and also if there are exactly two nodes in a component, then creating a cycle is impossible.  

__Subtasks 4 & 5__
The key insight here is to realize that for each connected component, all nodes with exactly one path to another node must exist together in a tree, and all nodes with exactly two paths to another node must be a part of a cycle, leading a structure of either a single tree or multiple trees strung together into a cycle (subtask 4). To check if such a structure can exist, another observation is that every node in a tree must have the exact same number of paths to all other nodes. Within a tree, they all share 1 path, and outside the tree, there are exactly two paths to all other nodes through the cycle (subtask 5). Again, don't forget to check if nodes that shouldn't share any paths are in the same component, creating a cycle is possible, etc.  

__Subtask 6__
Finally, after a bit of experimenting, it's obvious that there is only one structure that allows exactly three paths from a node to another: something synonymous to a {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}} set of edges (a cycle of length four with a diagonal crossing through). It's easy to see that with less than four nodes, it's impossible make three paths between two nodes, and with greater than four nodes, you can only make four or more paths if you split a cycle. Therefore, the final subtask is just checking that for every node with three paths to another node, that the connected component they create follows exactly the structure described above with no other nodes connected to it.  

