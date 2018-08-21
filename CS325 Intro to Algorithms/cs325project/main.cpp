/*****************************************************
Author: Patrick Spencer, Thanhbinh Truong, Vannear Por
File Name: main.cpp
Description: Uses Christofides Algorithm to solve the Travel Salesmen Problem
*****************************************************/

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <climits>
#include <cstring>
#include <string>
#include <math.h>
#include "tsp.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		exit(-1);
	}

	string input;
	string output;

	input = argv[1];						//read in arguments
	output = argv[1];						//read in argument to add .tour at the end for output file name

	output.append(".tour");

	TSP tsp(input, output);					//create the traveling saleman problem object
	int size_Of_Tsp = tsp.numOfCities();	//holds the size of the number of cities in tsp

	tsp.readCities();
	tsp.make_Matrix();						//create matrix
	tsp.find_MSTree();						//find the MST within input file data
	tsp.find_minWeightMatch();

	int shortest_Index;
	int shortest = INT_MAX;

	for (long l=0; l<size_Of_Tsp; l++)
	{
		int result = tsp.findPathLength(l);

		tsp.pathValues[l][0] = l; 	
		tsp.pathValues[l][1] = result; 

		if (tsp.pathValues[l][1] < shortest)
		{
			shortest_Index = tsp.pathValues[l][0];
			shortest = tsp.pathValues[l][1];
		}
	}

	tsp.find_EulerTour(shortest_Index,tsp.eulerCircuit);					//create Euler Tour

	tsp.get_HamiltonianPath(tsp.eulerCircuit,tsp.curr_ShortestPath);		//get Hamiltonian Path from Euler Circuit

	tsp.output_To_File();		//print output to .tour file
}
