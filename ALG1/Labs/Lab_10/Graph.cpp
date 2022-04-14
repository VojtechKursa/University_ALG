#include "Graph.h"

void Graph::ResetColors()
{
	for (auto vertex : this->vertices)
	{
		vertex->color = 0;
	}
}

bool Graph::Contains_BFS_Private(int value)
{
	if (this->vertices.empty())
		return false;

	queue<Vertex*> foundVertices;
	foundVertices.push(this->vertices.front());

	Vertex* currentVertex;
	while (!foundVertices.empty())
	{
		currentVertex = foundVertices.front();
		foundVertices.pop();
		cout << "Taking vertex " << currentVertex->value << endl;

		currentVertex->color = 2;

		if (value == currentVertex->value)
			return true;

		for (auto vertexNeighbor : currentVertex->neighbors)
		{
			if (vertexNeighbor->color == 0)
			{
				foundVertices.push(vertexNeighbor);
				vertexNeighbor->color = 1;
			}
		}
	}

	return false;
}

bool Graph::Contains_DFS_Private(int value)
{
	if (this->vertices.empty())
		return false;

	stack<Vertex*> foundVertices;	// Stejný algoritmus jako BFS, jen se místo Queue použije Stack, čímž obrátím pořadí prohledávání
	foundVertices.push(this->vertices.front());

	Vertex* currentVertex;
	while (!foundVertices.empty())
	{
		currentVertex = foundVertices.top();
		foundVertices.pop();
		cout << "Taking vertex " << currentVertex->value << endl;

		currentVertex->color = 2;

		if (value == currentVertex->value)
			return true;

		for (auto vertexNeighbor : currentVertex->neighbors)
		{
			if (vertexNeighbor->color == 0)
			{
				foundVertices.push(vertexNeighbor);
				vertexNeighbor->color = 1;
			}
		}
	}

	return false;
}



bool Graph::Contains_BFS(int value)
{
	bool returnValue = Contains_BFS_Private(value);
	ResetColors();
	return returnValue;
}

bool Graph::Contains_DFS(int value)
{
	bool returnValue = Contains_DFS_Private(value);
	ResetColors();
	return returnValue;
}

void Graph::Insert(int value, vector<int> neighbors)
{
	Vertex* newVertex = new Vertex(value);
	vertices.push_back(newVertex);

	for (auto neighbor : neighbors)		//foreach (range-based for)
	{
		for (auto vertex : this->vertices)
		{
			if (vertex->value == neighbor)
			{
				vertex->neighbors.push_back(newVertex);
				if (vertex != newVertex)
					newVertex->neighbors.push_back(vertex);

				break;
			}
		}
	}
}