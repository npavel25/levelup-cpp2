#ifndef FILE_H
#define FILE_H

#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include"tree.h"

std::string convert_word(const std::string& word);
std::unordered_map<std::string, int> take_map(const char* file_name);
My::Tree take_tree(const char* file_name);

#endif