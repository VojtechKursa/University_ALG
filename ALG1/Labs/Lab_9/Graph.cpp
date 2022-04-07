#include "Graph.h"

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