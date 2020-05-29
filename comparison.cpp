#include "comparison.h"


OOP_Dictionary::OOP_Dictionary()
{
    count = 0;
}

bool OOP_Dictionary::add(std::string word)
{

    for(auto& pair : data_map)
    {
        if(pair.first.compare(word) == 0)
        {
            pair.second++;
            return true;
        }
    
    }
    data_map.insert(std::pair<std::string, int>(word, INIT_VALUE));
    count++;
    return true;

}

bool OOP_Dictionary::find(const std::string word)
{
    auto map_it = data_map.find(word);

    if(map_it != data_map.end())
    {
        std::cout << "Found '" << map_it->first << "' with value: " << map_it->second++ << "\n";
        return true;
    }
    else
    {
        std::cout << "Could not find word: " << word << "\n";
        return false;
    }

    return false;
}

void OOP_Dictionary::print_map()
{
    for(auto& apair : data_map)
    {
        std::cout << apair.first << ", " << apair.second << "\n";
    }
    
    std::cout << "A Total of " << count << " pairs.\n";
}


DoD_Dictionary::DoD_Dictionary()
{
    count = 0;
}


DoD_Manager::DoD_Manager()
{
    
}

bool DoD_Manager::add(std::vector<std::string>& Keys, std::vector<int>& Values, size_t& count, std::string word)
{
    for(size_t i = 0; i < count; i++)
    {
        if(Keys[i].compare(word) == 0)
        {
            Values[i]++;
            return true;
        }
    }
    
    Keys.push_back(word);
    Values.push_back(INIT_VALUE);
    count++;

    return true;
    
}

int DoD_Manager::find(const std::string word, const std::vector<std::string> Keys, const size_t count)
{
    const int invalidIndex = -1;
    
    for(size_t i = 0; i < count; i++)
    {
        if(Keys[i].compare(word) == 0)
        {
            std::cout << "Found '" << word << "' ";
            return i;
        }
    }
    
    std::cout << "Could not find word: " << word << "\n";
    return invalidIndex;
}


void DoD_Manager::get(const std::vector<int> Values, const int index)
{
    std::cout << "with value: " << Values[index] << "\n";
}

void DoD_Manager::print_map(const std::vector<std::string> Keys, const std::vector<int> Values, const size_t count)
{
    for(size_t i = 0; i < count; i++)
    {
        std::cout << Keys[i] << ", "<< Values[i] << "\n";
    }

    std::cout << "A Total of " << count << " pairs.\n";
}

bool readfile(const std::string file, std::vector<std::string>& wordList)
{
    std::ifstream in_file(file);
    std::string file_line;

    //Validate in file
    if(in_file.is_open())
    {
        //While still more to read/read was good
        while(getline(in_file, file_line) && in_file.good())
        {        
            //tokenize next line
            boost::tokenizer<> tok(file_line);
                
            //Iterate over line, get each word    
            for(auto tok_line=tok.begin(); tok_line!=tok.end(); ++tok_line)
            {
                //convert to string
                std::string tok_word(*tok_line);

                //Erase digits
                tok_word.erase(std::remove_if(tok_word.begin(), tok_word.end(), &isdigit), tok_word.end());
               
                //If the word was empty (digit only word)
                if(tok_word.empty())
                {
                    continue;
                }   
                else
                {
                    //Add the node
                    wordList.push_back(tok_word);
                }
            }
        }    
    }
    else
    {
        std::cerr << "Error opening file: " << file << "\n";
        return false;
    }
    
    in_file.close();
    return true;
}


int main()
{
    std::vector<std::string> wordList;
    OOP_Dictionary OOP;
    
    DoD_Dictionary DoD;
    DoD_Manager manager;

    readfile(fileName, wordList);   
  
    for(size_t i = 0; i < wordList.size(); i++)
    {
        //OOP.add(wordList[i]);
        manager.add(DoD.Keys, DoD.Values, DoD.count, wordList[i]);
    }

    //OOP.find(wordB);
    int index = manager.find(wordB, DoD.Keys, DoD.count);
    if(index >= 0)
    {
        manager.get(DoD.Values, index);
    }
    return EXIT_SUCCESS;
}
