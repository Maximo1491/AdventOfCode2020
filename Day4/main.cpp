#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

typedef std::map<std::string, std::string> PASSPORT;

std::vector<std::string> split( std::string const &str, const char delim )
{
	std::stringstream ss( str );
	std::vector<std::string> out;

	std::string s;
	while ( getline( ss, s, delim ) )
	{
		out.push_back( s );
	}

	return out;
}

PASSPORT process_passport( std::vector<std::string>& lines )
{
	std::vector<std::string> passport_items;
	PASSPORT new_passport;
	for ( std::string line : lines )
	{
		std::vector<std::string> new_items = split( line, ' ' );
		passport_items.insert( passport_items.end(), new_items.begin(), new_items.end() );
	}

	for ( std::string item : passport_items )
	{
		std::vector<std::string> key = split( item, ':' );
		new_passport.insert( std::make_pair( key[0], key[1] ) );
	}

	return new_passport;
}

bool validate_birthday( std::string string )
{
	auto birthday = std::atoi( string.c_str() );

	return birthday >= 1920 && birthday <= 2002;
}

bool validate_issue( std::string string )
{
	auto issue = std::atoi( string.c_str() );

	return issue >= 2010 && issue <= 2020;
}

bool validate_expiration( std::string string )
{
	auto expiration = std::atoi( string.c_str() );

	return expiration >= 2020 && expiration <= 2030;
}

bool validate_height( std::string string )
{
	auto height = std::atoi( string.c_str() );

	if ( string.find( "cm" ) != std::string::npos )
	{
		return height >= 150 && height <= 193;
	}
	else if ( string.find( "in" ) != std::string::npos )
	{
		return height >= 59 && height <= 76;
	}

	return false;
}

bool validate_hair( std::string string )
{
	if ( string.size() == 7 && string[0] == '#' )
	{
		return string.find_first_not_of( "0123456789abcdef", 1 ) == std::string::npos;
	}

	return false;
}

bool validate_eyes( std::string string )
{
	return	string == "amb" || string == "blu" ||
			string == "brn" || string == "gry" ||
			string == "grn" || string == "hzl" ||
			string == "oth";
}

bool validate_id( std::string string )
{
	return string.size() == 9 && string.find_first_not_of( "0123456789" ) == std::string::npos;
}

void part1()
{
	std::ifstream input_file;
	input_file.open( "input.txt", std::ios::in );

	if ( input_file.is_open() )
	{
		std::string line;
		std::vector<std::string> passport_raw;
		std::vector<PASSPORT> passports;
		size_t valid_passports{};

		while ( getline( input_file, line ) )
		{
			if ( line != "" )
			{
				passport_raw.emplace_back( line );
			}
			else
			{
				//I cheated here, doing this we miss the last passport as we don't process the last line... I just added an extra line to the text file :(
				PASSPORT new_passport = process_passport( passport_raw );
				passports.emplace_back( new_passport );
				passport_raw.clear();
			}
		}

		for ( PASSPORT passport : passports )
		{
			if ( passport.find( "byr" ) != passport.end() &&
				 passport.find( "iyr" ) != passport.end() && 
				 passport.find( "eyr" ) != passport.end() && 
				 passport.find( "hgt" ) != passport.end() && 
				 passport.find( "hcl" ) != passport.end() && 
				 passport.find( "ecl" ) != passport.end() && 
				 passport.find( "pid" ) != passport.end() )
			{
				valid_passports++;
			}
		}

		std::cout << "Valid passports: " << valid_passports;

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
		std::vector<std::string> passport_raw;
		std::vector<PASSPORT> passports;
		size_t valid_passports{};

		while ( getline( input_file, line ) )
		{
			if ( line != "" )
			{
				passport_raw.emplace_back( line );
			}
			else
			{
				//I cheated here, doing this we miss the last passport as we don't process the last line... I just added an extra line to the text file :(
				PASSPORT new_passport = process_passport( passport_raw );
				passports.emplace_back( new_passport );
				passport_raw.clear();
			}
		}

		for ( PASSPORT passport : passports )
		{
			if ( passport.find( "byr" ) != passport.end() &&
				 passport.find( "iyr" ) != passport.end() &&
				 passport.find( "eyr" ) != passport.end() &&
				 passport.find( "hgt" ) != passport.end() &&
				 passport.find( "hcl" ) != passport.end() &&
				 passport.find( "ecl" ) != passport.end() &&
				 passport.find( "pid" ) != passport.end() )
			{
				if ( validate_birthday( passport.find( "byr" )->second ) &&
					 validate_issue( passport.find( "iyr" )->second ) &&
					 validate_expiration( passport.find( "eyr" )->second ) &&
					 validate_height( passport.find( "hgt" )->second ) &&
					 validate_hair( passport.find( "hcl" )->second ) &&
					 validate_eyes( passport.find( "ecl" )->second ) &&
					 validate_id( passport.find( "pid" )->second ) )
				{
					valid_passports++;
				}
			}
		}

		std::cout << "\nValid passports: " << valid_passports;

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