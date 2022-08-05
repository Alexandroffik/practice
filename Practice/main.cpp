#include <iostream>
#include <iomanip>
#include <cstdlib>

void error(std::string msg, bool is_fatal = false);

int main() {
	std::cout << "Practice" << std::endl;
	std::string command;

	// main logic with menu
	while(true){
		// switch or if logic
		std::cout << "practice:> ";
		std::cin >> command;
		
		if(command == "exit")
			break;
		
		error("unknown command");
	}

	// just pause before closing
	std::cin.get();
	return 0;
}


void error(std::string msg, bool is_fatal){
	std::cout << "[ERR]:> " << msg << std::endl;
	if(is_fatal)
		exit(1);
}