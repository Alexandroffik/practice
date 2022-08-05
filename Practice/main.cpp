#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>


void error(std::string msg, bool is_fatal = false);
void hand_sig(int sig);
void create_file();
void init_sig();

int main() {
	std::cout << "Practice" << std::endl;
	std::string command;

	init_sig();
	
	// main logic with menu
	while(true){
		// switch or if logic
		std::cout << "practice:> ";
		std::cin >> command;
		
		if(command == "create_file"){
			create_file();
			continue;	
		}

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

//1.ввести имя файла	(+)
//2.создать файл с именем 
//3.ввод в файл
//3.1.ввод пока is_end != true 
//3.2 получаем введенную строку (обрезать до 100 символов)(можно выдавать предупреждение)
//3.3 записать строку в файл
//4.закрыть файл
//по ctrl+z is_end = true

bool is_end = false;
void create_file(){
	//ввод имени файла
	std::string filename;
	std::cout << "Enter file name: ";
	std::cin >> filename;

	//создание файла
	std::ofstream file;
	file.open(filename);
	if (!file.is_open()){
		error("can`t create file with file name " + filename);
		return;
	}
	
	while(is_end != true){
		std::string text;
		std::getline(std::cin, text);
		if (text.length() > 100 ){
			std::cout << "string is cut for 100 symbols" << std::endl;
			text = text.substr(0, 100);
		}
		file << text << std::endl;
	}
	

	file.close();
}

void init_sig(){
	struct sigaction new_action;
	new_action.sa_handler = hand_sig;
	sigemptyset(&new_action.sa_mask);
	sigaddset(&new_action.sa_mask, SIGTSTP);
	sigaction(SIGTSTP, &new_action, NULL);
}

void hand_sig(int sig){
	is_end = true;
}