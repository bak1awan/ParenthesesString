#include <iostream>
#include <map>
#include <string>
#include <cctype> // for tolower function
#include <cstdint> // for fixed width integer types

constexpr int32_t AMOUNT_OF_TESTS = 10;
constexpr int32_t STRING_LENGTH = 10;

// Returns new parentheses string
std::string getParenthesesString(const std::string& input)
{
	// Initialize map for counting the amount of times each element has occured in the input string
	std::map<char, int> charCounter{};
	for (const auto& ch : input)
	{
		++charCounter[tolower(ch)];
	}

	// Result string which will be returned
	std::string result;
	// Beforehand reserve proper length of the output string
	result.reserve(input.size());

	for (const auto& ch : input)
	{
		if (charCounter[tolower(ch)] > 1)
		{
			result.append(")");
		}
		else
		{
			result.append("(");
		}
	}

	return result;
}

// Converts input string to parentheses string
void convertToParenthesesString(std::string& input)
{
	// Initialize map for counting the amount of times each element has occured in the input string
	std::map<char, int> charCounter{};
	for (const auto& ch : input)
	{
		++charCounter[tolower(ch)];
	}

	// replace each letter according to its frequency in the string, in C++ std::string is changeable
	for (auto& ch : input)
	{
		if (charCounter[tolower(ch)] > 1)
		{
			ch = ')';
		}
		else
		{
			ch = '(';
		}
	}
}

// Generates random string with length `length`
std::string generateRandomString(const int32_t length) {
	const std::string alphanum("0123456789" //
							   "ABCDEFGHIJKLMNOPQRSTUVWXYZ" //
							   "abcdefghijklmnopqrstuvwxyz");
	std::string result;
	result.reserve(length);

	for (int i = 0; i < length; ++i) {
		result += alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	return result;
}

// Makes `amount` tests, generating string with length `stringLength`
void makeTests(int32_t amount, int32_t stringLength) 
{
	std::cout << "\n===== MAKING " << amount << " TESTS =====\n";
	for (int i = 0; i < amount; ++i)
	{
		std::string randomString = generateRandomString(stringLength);
		std::string newParenthesesString = getParenthesesString(randomString);
		printf("Test #%d: generated string: %s, new parentheses string: %s, converted initial string: ",
			i + 1,
			randomString.c_str(),
			newParenthesesString.c_str());

		// we should do it later because we are changing inital string in convert function
		convertToParenthesesString(randomString);
		std::cout << randomString << ".\n";
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	makeTests(AMOUNT_OF_TESTS, STRING_LENGTH);
}