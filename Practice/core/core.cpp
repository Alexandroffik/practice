#include "core.h"

std::string process_line(std::string line){
    std::list<char> result;
    std::string result_str = "";

    for(int i = 0; i < line.length(); ++i){
        if(line[i] == '#'){
            if(result.size() > 0)
                result.pop_back();
            continue;
        }

        result.push_back(line[i]);
    }

    for(auto it : result){
        char value = it;
        result_str += value;
    }
       
    return result_str;
}

std::list<std::string> process_lines(std::list<std::string>& lines){
    std::list<std::string> process_results;

    for(auto it : lines){
        std::string value = it;
        auto str_res = process_line(value);
        process_results.push_back(str_res);
    }

    return process_results;
}

std::list<std::string> process_file(){
    auto str_lines = open_file();
    auto str_results = process_lines(str_lines);
    
    return str_results;
}

std::list<std::string> open_file(){
	std::string filename;
	std::cout << "Enter file name: ";
	std::cin >> filename;

	std::list<std::string> str_list;
	std::ifstream file;
	file.open(filename);
	if (!file.is_open()){
		error("can`t open file with file name " + filename);
		return str_list;
	}
	while(!file.eof()){
		std::string str;
    	std::getline(file, str);
		str_list.push_back(str);
	}
	file.close();
	
	return str_list;
}

void display_list(std::list<std::string> lines){
  for(auto it : lines)
    std::cout << it << std::endl;
}

void error(std::string msg, bool is_fatal){
	std::cout << "[ERR]:> " << msg << std::endl;
	if(is_fatal)
		exit(1);
}