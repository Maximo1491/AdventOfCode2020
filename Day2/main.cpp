#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void part1()
{
	std::ifstream input_file;
	input_file.open( "input.txt", std::ios::in );

	if ( input_file.is_open() )
	{
		std::string line;
		int valid_password_count = 0;

		while ( getline( input_file, line ) )
		{
			const int min_num = std::stoi( line.substr( 0, line.find_first_of( "-" ) ) );
			const int max_num = std::stoi( line.substr( line.find_first_of( "-" ) + 1, line.find_first_of( " " ) ) );
			const std::string letter = line.substr( line.find_first_of( ":" ) - 1, 1 );

			const std::string password = line.substr( line.find_last_of( " " ) + 1, line.length() );

			int letter_count = 0;
			for ( size_t i = 0; (i=password.find( letter, i )) != std::string::npos; ++i, ++letter_count );

			if ( letter_count >= min_num && letter_count <= max_num )
				++valid_password_count;
		}

		std::cout << "Part 1 Valid password count :" << valid_password_count;

	}
	else
	{
		std::cout << "Couldn't open file.";
	}
}

void part2()
{
	std::ifstream input_file;
	input_file.open( "input.txt", std::ios::in );

	if ( input_file.is_open() )
	{
		std::string line;
		int valid_password_count = 0;

		while ( getline( input_file, line ) )
		{
			const int first_index = std::stoi( line.substr( 0, line.find_first_of( "-" ) ) ) - 1;
			const int second_index = std::stoi( line.substr( line.find_first_of( "-" ) + 1, line.find_first_of( " " ) ) ) - 1;
			const std::string letter = line.substr( line.find_first_of( ":" ) - 1, 1 );

			const std::string password = line.substr( line.find_last_of( " " ) + 1, line.length() );

			if ( (password.substr(first_index, 1) == letter || password.substr( second_index, 1 ) == letter) &&
				 !(password.substr( first_index, 1 ) == letter && password.substr( second_index, 1 ) == letter) )
				++valid_password_count;
		}

		std::cout << "\nPart 2 Valid password count :" << valid_password_count;
	}
	else
	{
		std::cout << "Couldn't open file.";
	}
}

int main()
{
	part1();
	part2();

	return 1;
}