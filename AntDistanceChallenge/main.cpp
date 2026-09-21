/*
	Problem statement
		An ant on the floor can move in 4 diagonal directions, which are defined from the point of view of a fixed aerial observer (The ant does not ""turn).
		You are given a parameter moves, a vector of integers, containing the ant steps. Calculate the euclidean distance between the starting position and te final positionof the ant.
		Each step is a value between 0 and 3:
		0: the ant moevs 1 unit up and 1 unit to the right
		1: the ant moves one unit down and one unit to the right
		2: the ant moves one unit down and one unit to the left
		3: the ant moves one unit up and one unit to the left

		You must truncate the calculated euclidean distance and return an integer.
*/

#include <vector>
#include <iostream>
#include <array>

int calculateAntDistance(std::vector<int> moves) //make moves a const ref
{
	//setup move lookup table
	struct xyValues
	{
		int dx;
		int dy;
	};
	static constexpr std::array<xyValues, 4> moveValues{ xyValues{1,1},xyValues{1,-1},xyValues{-1,-1},xyValues{-1,1} };
	//run through ant moves and calculate total distance in either direction (horizontal and vertical)
	int xValue{ 0 };
	int yValue{ 0 };
	//simple, cache friendly, branchless lookup 
	//fast, readable, no thread overhead for realistic input sizes
	for (const auto& move : moves)
	{
		xValue += moveValues[move].dx;
		yValue += moveValues[move].dy;
	}
	//calculate euclidean distance
	return static_cast<int>(sqrt(static_cast<double>(xValue)* xValue+ static_cast<double>(yValue)*yValue));
}

int main()
{
	std::vector<int> moves = { 0,3,0,0,2,0,0 };
	std::cout<<calculateAntDistance(moves);
	return 0;
}