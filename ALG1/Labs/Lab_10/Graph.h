#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
private:
	class Vertex
	{
	public:
		int value;
		int color;	//0 = undiscovered, 1 = discovered, 2 = processed
		
		vector<Vertex*> neighbors;
		
		Vertex(int value)
		{
			this->value = value;
			this->color = 0;
		}
	};

	vector<Vertex*> vertices;

	void ResetColors();

	bool Contains_BFS_Private(int value);
	bool Contains_DFS_Private(int value);

public:
	void Insert(int value, vector<int> neighbors);

	bool Contains_BFS(int value);	// BFS = Breath first search (hledání do šířky)
	bool Contains_DFS(int value);	// DFS = Depth first search (hledání do hloubky)
};

