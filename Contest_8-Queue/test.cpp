// C++ implementation of the approach 
#include <bits/stdc++.h> 
#define n 3 
using namespace std; 

// Function to return the minimum steps 
// required to reach the end of the matrix 
int minSteps(int arr[][n]) 
{ 
	// Array to determine whether 
	// a cell has been visited before 
	bool v[n][n] = { 0 }; 

	// Queue for bfs 
	queue<pair<int, int> > q; 

	// Initializing queue 
	q.push({ 0, 0 }); 

	// To store the depth of search 
	int depth = 0; 

	// BFS algorithm 
	while (q.size() != 0) { 

		// Current queue size 
		int x = q.size(); 
		while (x--) { 

			// Top-most element of queue 
			pair<int, int> y = q.front(); 

			// To store index of cell 
			// for simplicity 
			int i = y.first, j = y.second; 
			q.pop(); 

			// Base case 
			if (v[i][j]) 
				continue; 

			// If we reach (n-1, n-1) 
			if (i == n - 1 && j == n - 1) 
				return depth; 

			// Marking the cell visited 
			v[i][j] = 1; 

			// Pushing the adjacent cells in the 
			// queue that can be visited 
			// from the current cell 
			if (i + arr[i][j] < n) 
				q.push({ i + arr[i][j], j }); 
			if (j + arr[i][j] < n) 
				q.push({ i, j + arr[i][j] }); 
		} 
		depth++; 
	} 

	return -1; 
} 

// Driver code 
int main() 
{ 
	int arr[n][n] = { { 1, 1, 1 }, 
					{ 1, 1, 1 }, 
					{ 1, 1, 1 } }; 

	cout << minSteps(arr); 

	return 0; 
} 
