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
		size_t tree_count = 0;
		size_t position = 0;
		constexpr size_t POSITION_INCREASE = 3;

		while ( getline( input_file, line ) )
		{
			size_t pos = position > 0 ? position % line.length() : position;
			if ( line[pos] == '#' )
				++tree_count;

			position += POSITION_INCREASE;
		}

		std::cout << "Part 1 trees encountered :" << tree_count;

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
		std::vector<std::string> lines;

		while ( getline( input_file, line ) )
		{
			lines.emplace_back( line );
		}

		auto calc_trees_encountered = [&]( size_t x, size_t y )
		{
			size_t x_position = 0;
			size_t y_position = 0;
			size_t tree_count = 0;
			while ( y_position < lines.size() )
			{
				if ( lines[y_position][x_position % lines[y_position].length()] == '#' )
					++tree_count;

				x_position += x;
				y_position += y;
			}
			return tree_count;
		};
		
		const auto a = calc_trees_encountered( 1, 1 );
		const auto b = calc_trees_encountered( 3, 1 );
		const auto c = calc_trees_encountered( 5, 1 );
		const auto d = calc_trees_encountered( 7, 1 );
		const auto e = calc_trees_encountered( 1, 2 );

		std::cout << "\nPart 2 trees encountered :" << a * b * c * d * e;

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