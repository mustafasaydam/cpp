#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

# include <iomanip>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange
{
private:
	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange &srcBEx );
	~BitcoinExchange( void );

	BitcoinExchange	&operator=( const BitcoinExchange &srcBEx );

	static void	checkDatabase( std::ifstream &db );

	static void	checkFormatInput( std::ifstream &in, std::map<std::string, float> &info );
	static void	checkValue( std::string value );

	static bool	saveDatabase( std::ifstream &db, std::map<std::string, float> &info );
	static bool	checkFile( std::ifstream &in, std::string file, std::map<std::string, float> &info );

	static void	checkDate( std::string date );
	static void	checkYear( const std::string date );
	static void	checkMonth( const std::string date );
	static void	checkDay( const std::string date );

public:
	static void	exchange( std::string file );
	
};

#endif