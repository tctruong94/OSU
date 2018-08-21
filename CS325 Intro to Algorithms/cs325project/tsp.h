/*****************************************************
Author: Patrick Spencer, Thanhbinh Truong, Vannear Por
File Name: tsp.cpp
Description: TSP Class header file
*****************************************************/
#ifndef TSP_H
#define TSP_H

#include <iostream>
#include <fstream>

#include <cstdlib>
#include <stdio.h>

#include <algorithm>

#include <cmath>
#include <ctime>

#include <cstring>
#include <string>

#include <queue>
#include <stack>
#include <vector>

#include <limits>
#include <iomanip>


using namespace std;


struct TSP
{
private:

	struct cityNode
	{
		int x, y;
	};

	string input_Data;
	string output_Data;

	vector<int>nodeList;					//a list that contains odd nodes

	int **minMatch;							//stores distances between odd nodes

	void search_For_Odds();  				//find vertices of odd degree in Minimum Spanning Tree

public:
	int n;									//# of cities
	int **pathValues;						//array that stores length of TSP path at each node
	int **matrixGraph;						//matrix with distance between each city
	int curr_ShortestPath;					//the current shorest path length

	vector<cityNode> cityList;				//stores cities from input file

	vector<int> eulerCircuit;				//Euler Circuit
  	vector<int>* adjacent_List;				//Vector of n arrays holding list of node its connected to

	TSP(string input, string output);		//Constructor
	~TSP();									//Desctructor

	int numOfCities();
	void readCities();
	
	int calc_Distance(struct cityNode first_City, struct cityNode second_City);		//calculate distance between nodes
	int getMinKey(int key[], bool mst[]);

	void make_Matrix();

	void find_minWeightMatch();												//find perfect matching

	void find_MSTree();														//find the Minimum Spanning Tree with Prim's algorithm
	void find_EulerTour(int beginning, vector<int> &path);					//find Euler Tour
	void get_HamiltonianPath(vector<int> &path, int &pathDistance);			//get the Hamiltonian Path
	int findPathLength(int beginning);	

	void output_To_File();

};

#endif
