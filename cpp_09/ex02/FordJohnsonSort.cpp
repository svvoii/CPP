#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

/*
** Some theory about the Ford-Johnson algorithm:
** 
** The Ford-Johnson algorithm works by assigning a weight to each task, 
** which represents the time it takes to complete the task. 
** The algorithm then constructs a graph of the tasks,
** where each task is represented by a node and the weight of each task 
** is represented by the length of the edge connecting the nodes.
** 
** The algorithm then finds the longest path in the graph, 
** which represents the optimal order in which to perform the tasks.
**
** The graph like structure of tasks is the base of the Ford-Johnson algorithm.
** Ford-Johnson algorithm is used to find the optimal order in which to perform the tasks.
** Tofind the longest path in the graph, the Bellman-Ford algorithm or
** the Dijkstra algorithm or yet the Floyd-Warshall algorithm can be used.
**
** Once the longest path is found, given the graph of tasks, then it can be used 
** to determine/construct the optimal order in which to perform the tasks.
*/

/*
** In this case of sorting a sequence of numbers using the Ford-Johnson algorithm,
** each number in the sequence would be considered a task.
** The weight of each task would be the value of the number.
** The dependencies between the tasks would be determined by the order 
** of the numbers in the sequence.
** 
*/

/*
** `struct Task` represent each number in the sequence.
** Each task has a value and a list of dependencies.
** The value is the number itself.
** The dependencies are the indices of all numbers (in the unsorted sequence)
** that come before the number/value in the given task.
**
** For example, if the sequence is {3, 1, 4, 2}, and we are constructing the task for 4,
** then the value of the task is 4, and the dependencies are the indices of 3 and 1,
** `dependencies = {0, 1}`.
** because 3 and 1 come before 4 in the unsorted sequence.
*/
struct Task {
	int value; // The value of the number
	vector<int> dependencies; // The indices of the numbers that come before this number
};

// Define a function to construct the graph for the Ford-Johnson algorithm
vector<Task> constructGraph(vector<int>& sequence, vector<Task>& graph) {

	for (int i = 0; i < sequence.size(); i++) {

		graph[i].value = sequence[i];

		for (int j = 0; j < i; j++) {

			if (sequence[j] < sequence[i]) {
				graph[i].dependencies.push_back(j);
			}
		}
	}
	return graph;
}

// Define a function to find the longest path in the graph using the Bellman-Ford algorithm
/*
** The Bellman-Ford algorithm is used to find the longest path in the graph.
** It works by assigning a weight to each task, 
** which represents the time it takes to complete the task.
**
** The comparison condition is `dist[k] + graph[k].value > dist[i]`.
** The weight is `graph[k].value`.
** `i` is the index of the task that comes after the task `k`.
** `dist[i]` is the weight of the task `i`.
** `dist[k]` is the weight of the task `k`.
** `k` is the index of the task that comes before the task `i`.
*/
void findLongestPath(vector<Task>& graph, vector<int>& dist) {

	dist[0] = 0;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].dependencies.size(); j++) {
			int k = graph[i].dependencies[j];
			if (dist[k] + 1 > dist[i]) {
				dist[i] = dist[k] + 1;
			}
			/*
			if (dist[k] + graph[k].value > dist[i]) {
				dist[i] = dist[k] + graph[k].value;
			}
			*/
		}
	}
}

// Define a function to sort the sequence using the Ford-Johnson algorithm
/*
** The priority queue `pq` is used to sort the sequence.
** The first element of the pair is the weight of the task, 
** which is the distance to the node/task in the graph
** The second element of the pair is the corresponding value in the sequence.
** 
*/
void fordJohnsonSort(vector<int>& sorted, vector<int>& sequence) {
	vector<Task> graph(sequence.size());
	vector<int> dist(graph.size(), numeric_limits<int>::min());
	priority_queue<pair<int, int>> pq;
	
	constructGraph(sequence, graph);
	findLongestPath(graph, dist);

	for (int i = 0; i < sequence.size(); i++) {
		pq.push(make_pair(dist[i], graph[i].value));
	}
	for (int i = 0; i < sequence.size(); i++) {
		//sorted[pq.top().first] = pq.top().second;
		sorted[i] = pq.top().second;
		pq.pop();
	}
}

// Define a main function to test the Ford-Johnson algorithm
int main() {
	vector<int> sequence = {3, 1, 4, 2, 9, 5, 8, 6, 7, 10};
	vector<int> sorted(sequence.size());
	
	fordJohnsonSort(sorted, sequence);

	for (int i = 0; i < sorted.size(); i++) {
		cout << sorted[i] << " ";
	}
	cout << endl;
	return 0;
}
