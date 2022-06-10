#include"file.h"
#include"tree.h"
#include<string>
#include<unordered_map>

std::string convert_word(const std::string& word)
{
    std::string new_word;
    for (auto& ch: word)
    {
        if(std::isalpha(ch) || ch == '-')
            new_word += std::toupper(ch);
    }
    //std::cout << new_word << std::endl;

    return new_word;
}

std::unordered_map<std::string, int> take_map(const char* file_name)
{
    std::unordered_map<std::string, int> count_map;

    std::ifstream file (file_name);

    std::string word;
    while(!file.eof())
    {
        file >> word;
        std::string new_word = convert_word(word);
        
        if(!new_word.empty())
        {
            ++count_map[new_word];
        }
        //std::cout << new_word << std::endl;
    }

    //Before C++17:
    /*for(const std::pair<std::string, int>& value: count_map)
    {
        std::cout << value.first << ":" << value.second << std::endl;

    } */
    
    //since C++17:
    /*for(const auto& [key, value]: count_map)
    {
        std::cout << key << ":" << value << std::endl;
    }*/

    return count_map;   

}

My::Tree take_tree(const char* file_name)
{
    My::Tree count_tree;
    std::ifstream file (file_name);

    std::string word;
    while(!file.eof())
    {
        file >> word;
        std::string new_word = convert_word(word);
        
        if(!new_word.empty())
        {
            count_tree.insert(new_word);
        }
    }
    
    return count_tree;

}