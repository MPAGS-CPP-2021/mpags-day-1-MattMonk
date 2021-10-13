#include <iostream>
#include <string>
#include <vector>
int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs {argv, argv+argc};
    //Set the input/output files up first, optional argument so change this behaviour later
    std::string input_file{""};
    std::string output_file{""};
    for (size_t i{0}; i<cmdLineArgs.size(); i++)
    {
        std::string arg{cmdLineArgs[i]};
        //If help or version is requested, provide it and then exit the program rather than continuing
        //this is order specific so if --help and --version is supplied it will only give the first one.
        //I think this is fine as they should only really ask one at a time but perhaps it should supply both?
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
            /*
            -i should be followed by a filename but if -i is the last argument collected (no filename)
            then getting the filename as the next argument will run out of bounds.
            So, check it won't run out of bounds first before looking for the next argument.
            If there isn't a next argument, -i and -o are optional so carry on running with default
            options but inform the user that they should either supply a filename after -i or -o
            or just not supply the options at all.
            */
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
    //Will be blank if no -i or -o is supplied
    std::cout << "Input file: " << input_file << "\nOutput file: " << output_file << std::endl;
    
    std::string final{""};
    char in_char{'x'};
    while(std::cin >> in_char)
    {
        //Make sure character is alphanumeric first, otherwise skip to the next one
        if(isalnum(in_char))
        {
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
                    //Here, the character must be alphanumeric so if it is not a number
                    //it must be a letter so convert it to uppercase
                    to_add_str += toupper(in_char);
                    break;
            }
            //add the character to the string with thre requirements
            final += to_add_str;
        }
        else
        {
            continue;
        }
    }
    std::cout << final << std::endl;
    
}