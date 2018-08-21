/*****************************************************
Author: Patrick Spencer, Thanhbinh Truong, Vannear Por
File Name: tsp.h
Description: TSP Class implementation file
*****************************************************/

#include "tsp.h"


/*******************************************
**name: TSP
**descrption: Constructor for TSP class
********************************************/
TSP::TSP(string input, string output)
{
	int count = 0;
	input_Data = input;
	output_Data = output;

	ifstream Read_File;

	Read_File.open(input_Data.c_str(), ios::in);

	if(!Read_File)
	{
	 	cout << "Cannot open file " << endl;
	 	exit(1);
	}

	string dummyVar;

	while(getline(Read_File, dummyVar))
	{
		++count;
	}
	n = count;

	Read_File.close();


	pathValues = new int*[n];						//allocate memory for pathValue
	for(int i=0; i<n; i++)
	{
		pathValues[i] = new int[n];
	}

	minMatch = new int*[n];							//allocate memory for minMatch
	for(int i=0; i<n; i++)
	{
		minMatch[i] = new int[n];
	}

	adjacent_List = new vector<int>[n];				//allocate memory for adjacent_List
	for(int i=0; i<cityList.size(); i++)
	{
		struct cityNode curr = cityList[i];
	}

	matrixGraph = new int*[n];						//allocate memory for matrix graph
	for(int i=0; i<n; i++)
	{
		matrixGraph[i] = new int[n];
		for(int j=0; j<n; j++)
		{
			matrixGraph[i][j] = 0;
		}
	}

}

/*******************************************
**name: ~TSP
**descrption: Desctructor for TSP Class
********************************************/
TSP::~TSP()
{
	for(int j = 0; j < n; j++)
	{
		delete [] pathValues[j];
		delete [] minMatch[j];
		delete [] matrixGraph[j];
	}
	delete [] matrixGraph;
	delete [] minMatch;
	delete [] pathValues;
	delete [] adjacent_List;
}



/*******************************************
**name: numOfCities
**descrption: Return the number of cities 
********************************************/
int TSP::numOfCities()
{
	return n;
}



/*******************************************
**name: readCities
**descrption: reads in the file
********************************************/
void TSP::readCities()
{
	ifstream Read_File;

	Read_File.open(input_Data.c_str(), ios::in);

	if(!Read_File)
	{
		cout << "Cannot open file "<< endl;
		exit(1);
	}
	
	int z, x, y;
	int count = 0;

	while(!Read_File.eof())
	{
		Read_File >> z >> x >> y;
		count++;

		struct cityNode newCity = {x,y};
		cityList.push_back(newCity);
	}
	count--;

	Read_File.close();
}



/*******************************************
**name: search_For_Odds
**descrption: This function helps finding all the vertices that have odd degrees inside a Minimum Spanning Tree
********************************************/
void TSP::search_For_Odds()
{
	int i;
  	for (i=0; i<n; i++)
  	{
    	if ((adjacent_List[i].size() % 2) != 0)					//check if the degree of current vertex is odd
    	{
    	nodeList.push_back(i);
    	}

  	}

}



/*******************************************
**name: calc_Distance
**descrption: calculates the distance between two cityNodes
********************************************/
int TSP::calc_Distance(struct cityNode first_City, struct cityNode second_City)
{
	int distance_X = pow((float)(first_City.x - second_City.x),2);
	int distance_Y = pow((float)(first_City.y - second_City.y),2);

	return floor((float)(sqrt(distance_X+distance_Y) + .5));
}




/*******************************************
**name: getMinKey
**descrption: Helps find the index of the cloest node that has not been visited yet
********************************************/
int TSP::getMinKey(int key[], bool mst[])
{
	int minimumIndex;
 	int minimum = numeric_limits<int>::max();

 	for (int i=0; i<n; i++)				//go through each vertex to check if it has been visited+smaller key than min
 	{
    	if (mst[i] == false && key[i] < minimum)
    	{
      		minimum = key[i];			//update minimum to the values of this node
      		minimumIndex = i;

    	}

  	}
  return minimumIndex;
}



/*******************************************
**name: Make_Matrix
**descrption: Create a 2-d array holding the distance from cityList indexes
********************************************/
void TSP::make_Matrix()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			matrixGraph[i][j] = matrixGraph[j][i] = calc_Distance(cityList[i],cityList[j]);
		}
	}
}



/*******************************************
**name: find_minWeightMatch
**descrption: find a perfect matching M with the greedy algorithm
********************************************/
void TSP::find_minWeightMatch()
{
	int distance;
	int curr_closest;
 	
 	vector<int>::iterator beginning;
 	vector<int>::iterator var_Holder;

  	search_For_Odds();											//search for odd degree nodes

  	while (!nodeList.empty())
  	{
    	beginning = nodeList.begin();
    	
    	vector<int>::iterator vector_Var = nodeList.begin() + 1;
    	vector<int>::iterator last = nodeList.end();
    
    distance = numeric_limits<int>::max();
    
    for(; vector_Var != last; ++vector_Var)
    {
      	if (matrixGraph[*beginning][*vector_Var] < distance)		//update if node is closer
      	{
        	distance = matrixGraph[*beginning][*vector_Var];
        	curr_closest = *vector_Var;
        	var_Holder = vector_Var;
      	}
    }
    
    adjacent_List[*beginning].push_back(curr_closest);
    adjacent_List[curr_closest].push_back(*beginning);
    
    nodeList.erase(var_Holder);
    nodeList.erase(beginning);
  }
}



/*******************************************
**name: find_MSTree
**descrption: Implements Prim's algorithm to find the minimum spanning tree from MatrixGraph
Reference help from: https://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
********************************************/
void TSP::find_MSTree()
{
  int parent[n];				//array that stores constructed MST
  int key[n];					//key values to pick min. weight edge
  bool mstSet[n];				//represent vertices not yet included in MST

	for(int i=0; i<n; i++)
 	{
		key[i] = numeric_limits<int>::max();	//initialize all keys to infinity
    	mstSet[i] = false;
	}

  key[0] = 0;									//key[0] == 0 to this is picked as beginning vertex
  parent[0] = -1;			


	for(int i=0; i<n-1; i++) 				//MST will have n vertices
	{
    	int k = getMinKey(key, mstSet);			//pick min. key vertex from vertices not included in MST
    	mstSet[k] = true;						//add to MST

    
    //update key pathDistance and parent index of adjacent vertices
    //vetices considered are the ones not included in MST
    for(int j=0; j<n; j++)
    {

    	//update only if graph[k][j] is smaller than key[j]
     	if(matrixGraph[k][j] && mstSet[j] == false && matrixGraph[k][j] < key[j])
      	{
        	parent[j] = k;						//parent updated
        	key[j] = matrixGraph[k][j];			//key updated
      	}
    }

  	}

  	for(int i=0; i<n; i++)				//construct tree
  	{
    	int var = parent[i];
    	
    	if (var != -1)
    	{
      		adjacent_List[i].push_back(var);
      		adjacent_List[var].push_back(i);
    	}
  	}

}




/*******************************************
**name: find_EulerTour
**descrption: find an euler circuit from the graph
********************************************/
void TSP::find_EulerTour(int beginning, vector<int> &path)
{
	vector<int> *adjList_Copy = new vector<int>[n];

	for(int i=0; i<n; i++)
	{
		adjList_Copy[i].resize(adjacent_List[i].size());
		adjList_Copy[i] = adjacent_List[i];
	}

	int index = beginning;
	stack<int> list;

	path.push_back(beginning);

	while(!list.empty() || adjList_Copy[index].size() > 0)
	{
		if(adjList_Copy[index].empty())						//curr node does not have any neighboring vertices
		{
			path.push_back(index);							//add to the euler tour
			index = list.top();
			list.pop();										//remove vertex
		}
		else												//current node does have neighboring vertices
		{
			list.push(index);								//add the vertex at index to stack

			int nearby_Node = adjList_Copy[index].back();

			adjList_Copy[index].pop_back();

			for(int i=0; i<adjList_Copy[nearby_Node].size(); i++)
			{
				if(adjList_Copy[nearby_Node][i] == index)
				{
					adjList_Copy[nearby_Node].erase(adjList_Copy[nearby_Node].begin()+i);
				}
			}
			index = nearby_Node;
		}
	}
	path.push_back(index);
}



/*******************************************
**name: get_HamiltonianPath
**descrption: Get a Hamiltonian Path from the graph
********************************************/
void TSP::get_HamiltonianPath(vector<int> &path, int &pathDistance)
{
	bool visited[n];

		pathDistance = 0;

	int root_Node = path.front();

	for(int i=0; i<n; i++)
	{
		visited[i] = 0;
	}

	vector<int>::iterator current = path.begin();
	vector<int>::iterator next = path.begin()+1;

	visited[root_Node] = 1;

	while(next != path.end())								//step through Euler Circuit
	{
		if(!visited[*next])
		{
			pathDistance += matrixGraph[*current][*next];

			current = next;

			visited[*current] = 1;

			next = current + 1;
		}	
		else
		{
			next = path.erase(next);
		}
	}
	pathDistance += matrixGraph[*current][*next];			//add distance back to root_Node
}


/*******************************************
**name: findPathLength
**descrption: Finds the path length from the specified node and then returns it
********************************************/
int TSP::findPathLength(int beginning)
{
	int len;
	vector<int> path;
	
	find_EulerTour(beginning, path);
	get_HamiltonianPath(path, len);

	return len;
}



/*******************************************
**name: 
**descrption: 
********************************************/
void TSP::output_To_File(){
  ofstream outputStream;
  outputStream.open(output_Data.c_str(), ios::out);
  outputStream << curr_ShortestPath << endl;
  for (vector<int>::iterator vector_Var = eulerCircuit.begin(); vector_Var != eulerCircuit.end(); ++vector_Var) {
    outputStream << *vector_Var << endl;
  }
  outputStream.close();
};
