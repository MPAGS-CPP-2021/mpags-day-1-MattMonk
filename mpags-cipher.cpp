#include <iostream>
#include <string>
#include <vector>
int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs {argv, argv+argc};
    std::string input_file{""};
    std::string output_file{""};
    for (size_t i{0}; i<cmdLineArgs.size(); i++)
    {
        std::string arg{cmdLineArgs[i]};
        //If help or version is requested, provide it and then exit the program
        if(arg=="-h" || arg=="--help")
        {
            std::cout << "Here's some help text" << std::endl;
            return 0;
        }
        else if(arg=="--version")
        {
            std::cout << "Version v0.1.0" << std::endl;
            return 0;
        }
        else if (arg=="-i")
        {
            if (i<cmdLineArgs.size()-1)
            {
                input_file = cmdLineArgs[i+1];
            }
            else
            {
                std::cout << "Could not find a filename -- using default. Please put a filename after -i or remove the -i option." << std::endl;
            }
        }
        else if (arg=="-o")
        {
            if (i<cmdLineArgs.size()-1)
            {
                output_file = cmdLineArgs[i+1];
            }
            else
            {
                std::cout << "Could not find a filename -- using default. Please put a filename after -o or remove the -o option." << std::endl;
            }
        }
    }
    std::cout << "Input file: " << input_file << "\nOutput file: " << output_file << std::endl;
    
    std::string final{""};
    char in_char{'x'};
    while(std::cin >> in_char)
    {
        if(isalnum(in_char))
        {
            //char curr_char = toupper(in_char);
            //std::cout << curr_char << std::endl;
            std::string to_add_str{""};
            switch(in_char)
            {
                case '0':
                    to_add_str = "ZERO";
                    break;
                case '1':
                    to_add_str = "ONE";
                    break;
                case '2':
                    to_add_str = "TWO";
                    break;
                case '3':
                    to_add_str = "THREE";
                    break;
                case '4':
                    to_add_str = "FOUR";
                    break;
                case '5':
                    to_add_str = "FIVE";
                    break;
                case '6':
                    to_add_str = "SIX";
                    break;
                case '7':
                    to_add_str = "SEVEN";
                    break;
                case '8':
                    to_add_str = "EIGHT";
                    break;
                case '9':
                    to_add_str = "NINE";
                    break;
                default:
                    to_add_str += toupper(in_char);
                    break;
            }
            final += to_add_str;
        }
        else
        {
            continue;
        }
    }
    std::cout << final << std::endl;
    
}