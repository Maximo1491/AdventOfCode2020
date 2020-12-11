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
		std::vector<int> expense_report;
		std::string line;
		//Get our expense report in a readable format
		while ( getline( input_file, line ) )
		{
			expense_report.emplace_back( std::stoi( line ) );
		}

		constexpr int REQUIRED_SUM = 2020;

		for ( size_t i = 0; i < expense_report.size(); i++ )
		{
			for ( size_t j = i + 1; j < expense_report.size(); j++ )
			{
				if ( expense_report[i] + expense_report[j] == REQUIRED_SUM )
				{
					std::cout << "Fix for expense report: " << expense_report[i] * expense_report[j];
					break;
				}
			}
		}
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
		std::vector<int> expense_report;
		std::string line;
		//Get our expense report in a readable format
		while ( getline( input_file, line ) )
		{
			expense_report.emplace_back( std::stoi( line ) );
		}

		constexpr int REQUIRED_SUM = 2020;

		for ( size_t i = 0; i < expense_report.size(); i++ )
		{
			for ( size_t j = i + 1; j < expense_report.size(); j++ )
			{
				for ( size_t k = j + 1; k < expense_report.size(); k++ )
				{
					if ( expense_report[i] + expense_report[j] + expense_report[k] == REQUIRED_SUM )
					{
						std::cout << "Fix for expense report: " << expense_report[i] * expense_report[j] * expense_report[k];
						break;
					}
				}
			}
		}
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