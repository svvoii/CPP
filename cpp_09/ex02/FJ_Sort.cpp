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
/*
** Function to construct the graph for the Ford-Johnson algorithm
**
** In the sequence example given in the main function below:
** `sequence = {33, 11, 44, 22, 99, 55, 88, 66, 77, 100}`
** This function will construct the following graph:
** `graph = {
		{ 33, {} }, 
		{ 11, {} }, 
		{ 44, {0, 1} }, 
		{ 22, {1} }, 
		{ 99, {0, 1, 2, 3} }, 
		{ 55, {0, 1, 2, 3} }, 
		{ 88, {0, 1, 2, 3, 5} }, 
		{ 66, {0, 1, 2, 3, 5} }, 
		{ 77, {0, 1, 2, 3, 5, 7} }, 
		{ 100, {0, 1, 2, 3, 4, 5, 6, 7, 8} }
	}`
*/
void constructGraph(const vector<int>& sequence, vector<Task>& graph) {

	for (int i = 0; i < sequence.size(); i++) {

		//graph[i].value = sequence[i];
		graph.emplace_back(Task{sequence[i], {}});
		graph[i].dependencies.reserve(i);

		for (int j = 0; j < i; j++) {

			if (sequence[j] < sequence[i]) {
				//graph[i].dependencies.push_back(j);
				graph[i].dependencies.emplace_back(j);
			}
		}
		/*
		int dependency = std::distance(sequence.begin(), std::lower_bound(sequence.begin(), sequence.begin() + i, sequence[i]));
		graph[i].dependencies.push_back(dependency);
		*/
	}
}

// Define a function to find the longest path in the graph using the Bellman-Ford algorithm
/*
** The Bellman-Ford algorithm is used to find the longest path in the graph.
** It works by assigning a weight to each task, 
**
** The flow:
** Setting of the first task in the graph to 0.
** Iterating over each task in the graph.
** For each task, iterates through all its dependencies. 
** For each dependency, calculates the distance to the
** current task by adding 1 to the distance of the dependency.
** If the calculated distance is greater than the current distance
** of the task, then the distance of the task is updated to the 
** calculated distance.
**
** Function to find the longest path in the graph using the Bellman-Ford algorithm
**
** The Bellman-Ford algorithm is used to find the longest path in the graph.
** After the graph is constructed, in the function above, and the original sequence:
** `sequence = {33, 11, 44, 22, 99, 55, 88, 66, 77, 100}`, 
** this function shall identifies the longest path in the graph. 
**
** Given the example graph above, and the mechanichs of the function below, 
** the longest path vector would look like this:
** `dist = {0, 0, 1, 1, 2, 2, 3, 3, 4, 5}`
** Not sure if these are the correct values, since the there are same
** weight values for different tasks/numbers.
*/
void findLongestPath(vector<Task>& graph, vector<int>& dist) {

	dist[0] = 0;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].dependencies.size(); j++) {

			int dependency = graph[i].dependencies[j];
			int weight = i;

			if (dist[dependency] + 1 > dist[weight]) {
				dist[weight] = dist[dependency] + 1;
			}
			//dist[weight] = std::max(dist[weight], dist[dependency] + 1);
		}
	}
}

// Define a function to sort the sequence using the Ford-Johnson algorithm
/*
** The priority queue `pq` is used to sort the sequence.
** The first element of the pair is the weight of the task, 
** which is the distance to the node/task in the graph
** The second element of the pair is the corresponding value in the sequence.
*/
void fordJohnsonSort(vector<int>& sorted, vector<int>& sequence) {
	vector<Task> graph;
	graph.reserve(sequence.size());
	vector<int> dist(sequence.size(), numeric_limits<int>::min());
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	constructGraph(sequence, graph);
	findLongestPath(graph, dist);

	for (int i = 0; i < sequence.size(); i++) {
		pq.emplace(dist[i], graph[i].value);
	}
	for (int i = 0; i < sequence.size(); i++) {
		sorted.push_back(pq.top().second);
		pq.pop();
	}
}

// Define a main function to test the Ford-Johnson algorithm
int main() {
	vector<int> sequence = {33, 11, 44, 22, 99, 55, 88, 66, 77, 100};
	vector<int> sorted;
	sorted.reserve(sequence.size());
	
	fordJohnsonSort(sorted, sequence);

	for (int i = 0; i < sorted.size(); i++) {
		cout << sorted[i] << " ";
	}
	cout << endl;
	return 0;
}
