#include<iostream>
#include<fstream>
#include"file.h"
#include"tree.h"

#include<ctime>

int main(int argc, char* argv[])
{
    std::string file_name;
    if (argc > 1)
    {
        file_name = argv[1];
    }
    else
    {
        std::cout << "Input file name to read words: ";
        std::cin >> file_name;
    }
    


    std::clock_t clock1 = std::clock();
    //std::cout << "Clock 1: " << clock1 << std::endl;

    std::unordered_map<std::string, int> count_map = take_map(file_name.c_str());

    std::clock_t clock2 = std::clock();
    //std::cout << "Clock 2: " << clock2 << std::endl;
    std::cout << "Time spend to read file in map: " << 1'000'000 * (clock2 - clock1) / CLOCKS_PER_SEC << " us" << std::endl;

    std::string keyword;
    if (argc > 2)
    {
        keyword = argv[2];
    }
    else
    {
        std::cout << "Input word to find: ";
        std::cin >> keyword;
    }
    
    keyword = convert_word(keyword);
    std::clock_t clock3 = std::clock();
    std:: cout << "Word " << keyword << " found in map " << count_map[keyword] <<  " times." << std::endl;
    std::clock_t clock4 = std::clock();
    std::cout << "Time spend to find word in map: " << 1'000'000 * (clock4 - clock3) / CLOCKS_PER_SEC << " us"<< std::endl;

    std::clock_t clock5 = std::clock();
    My::Tree count_tree = take_tree(file_name.c_str());
    
    std::clock_t clock6 = std::clock();
    std::cout << "Time spend to read file in tree: " << 1'000'000 * (clock6 - clock5) / CLOCKS_PER_SEC << " us" << std::endl;

    std::clock_t clock7 = std::clock();
    std:: cout << "Word " << keyword << " found in tree " << count_tree.find(keyword) <<  " times." << std::endl;
    std::clock_t clock8 = std::clock();
    std::cout << "Time spend to find word in tree: " << 1'000'000 * (clock8 - clock7) / CLOCKS_PER_SEC << " us"<< std::endl;
}