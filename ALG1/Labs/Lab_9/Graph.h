#pragma once
#include <vector>

using namespace std;

class Graph
{
private:
	class Vertex
	{
	public:
		int value;
		
		vector<Vertex*> neighbors;
		
		Vertex(int value)
		{
			this->value = value;
		}
	};

	vector<Vertex*> vertices;

public:
	void Insert(int value, vector<int> neighbors);
};

