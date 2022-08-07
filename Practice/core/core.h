#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <list>

std::string process_line(std::string line);
std::list<std::string> process_lines(std::list<std::string>& lines);
std::list<std::string> process_file();

std::list<std::string> open_file();
void display_list(std::list<std::string> lines);
void error(std::string msg, bool is_fatal = false);

#endif