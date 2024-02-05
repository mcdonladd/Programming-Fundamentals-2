/*
	The purpose of this program is to analyse a C source code file,
 	which replaces all #define constants with its corrosponding value,
	and then is written to an output file

 Date of last modification: 29/04/23
 Program written by Sam McDonald
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "BST.h"


using namespace std;

int main ( int argc, char *argv[] )
{
	//create an instance of the BST class
	 BST tree;

	 	//declare variables
    string line;
    string token;
		string constantName;
		string fileName(argv[1]); //store the filename as a string to modify for the output

		//open the file
		ifstream input_file(fileName);

		//file name without extension
		size_t extIndex = fileName.find_last_of (" .") ;
		string baseFileName = fileName.substr(0, extIndex);
		string outputFileName = baseFileName + ".o";

		//opens the output file for writing
    ofstream output_file(outputFileName);

		//read each line from input file
    while(getline(input_file, line))
    {
      stringstream stream(line);
			//tokenize line by space
      while (stream >> token)
      {
        if (token == "#define")
        {

        stream >> token;
				//get the constant name and store it
				constantName = token;
				//iterate the token to get corrosponding value
				stream >> token;
				tree.insert_constant(constantName, token); //insert the pair to the tree

				break; // process next line
        }

			//write corrosponding value to output file
			output_file << tree.get_value(token);

			//This segment of code removes the name of the contant from the file
			//find the constant in the file
				if (tree.get_value(token) != "")
				{
					output_file << " ";
					if (stream >> token)
					{
						output_file << "";
					}
				}

			output_file << token << " ";

			}//end while loop

			if (line.find("#define") == std::string::npos)
			{
				//write a new line character if line does not contain define
				output_file << endl;
			}

    }//end while loop

		//close files
		input_file.close();
		output_file.close();

    return 0;

}
