
#include "A.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool should_continue = true;


int main()
{
	std::vector<string> lines_history;
	while(should_continue)
	{
		string line; 
		getline(std::cin, line);
		lines_history.push_back(line);
		
	}
	
	
	// clean up
	return 0;
}
