#include "text_loader.h"
#include <string>
#include <fstream>

void TextLoader::Load_Unprocessed(std::string data) noexcept
{
	std::ifstream file(data);
	std::string line = "\0";

	while (std::getline(file, line))
	{
		m_DataList.push_back(line);
	}
}

void TextLoader::Load_All(std::string data) noexcept
{
	std::ifstream file(data);
	std::string line = "\0";

	while (std::getline(file, line))
	{
		if (!line.empty())
		{
			m_DataList.push_back(line);
		}
	}
}

void TextLoader::Load_OnlyNumeric(std::string data) noexcept
{
	std::ifstream file(data);
	std::string line = "\0";
	std::string num = "\0";
	char c = '\0';

	while (std::getline(file, line))
	{
		num = "\0";

		for (int i = 0; i < (int)line.size(); ++i)
		{
			c = line[i];

			if (c == '-' || c == '.'
				|| c >= '0' && c <= '9')
			{
				num = line.substr(i);

				break;
			}
		}

		if (this->to_long_double(num) != LDBL_MIN)
		{
			m_DataList.push_back(num);
		}
	}
}

void TextLoader::Load_OnlyAlphabet(std::string data) noexcept
{
	std::ifstream file(data);
	std::string line = "\0";
	std::string alphabet = "\0";
	char c = '\0';

	while (std::getline(file, line))
	{
		alphabet = "\0";

		for (int i = 0; i < (int)line.size(); ++i)
		{
			c = line[i];

			if (c == '-' || c == '.'
				|| c == '!' || c == '?'
				|| c == '&' || c == '%'
				|| c == '#' || c == '+'
				|| c == '(' || c == ')'
				|| c == '@' || c == '*'
				|| c == '$' || c == '\\'
				|| c == ',' || c == '\"'
				|| c == '/' || c == '_'
				|| c == '<' || c == '>'
				|| c == '=' || c == ':'
				|| c >= 'A' && c <= 'z')
			{
				alphabet.push_back(c);
			}
		}

		if (!alphabet.empty())
		{
			m_DataList.push_back(alphabet);
		}
	}
}

void TextLoader::Load_OnlyJapanese(std::string data) noexcept
{
	std::ifstream file(data);
	std::string line = "\0";
	std::string jpnese = "\0";
	char c = '\0';

	while (std::getline(file, line))
	{
		jpnese = "\0";

		for (int i = 0; i < (int)line.size(); ++i)
		{
			c = line[i];

			if (c != '-' && c != '.'
				&& c != ',' && c != '\"'
				&& c != '/' && c != '_'
				&& c != '^' && c != '\''
				&& c != '=' && c != '`'
				&& !(c >= 'A' && c <= 'z')
				&& !(c >= '0' && c <= '9'))
			{
				jpnese.push_back(c);
			}
		}

		if (!jpnese.empty())
		{
			m_DataList.push_back(jpnese);
		}
	}
}

void TextLoader::Load_AlphabetAndNumeric(std::string data) noexcept
{
	std::ifstream file(data);
	std::string line = "\0";
	std::string alphabet = "\0";
	char c = '\0';

	while (std::getline(file, line))
	{
		alphabet = "\0";

		for (int i = 0; i < (int)line.size(); ++i)
		{
			c = line[i];

			if (c == '-' || c == '.'
				|| c == '!' || c == '?'
				|| c == '&' || c == '%'
				|| c == '#' || c == '+'
				|| c == '(' || c == ')'
				|| c == '@' || c == '*'
				|| c == '$' || c == '\\'
				|| c == ',' || c == '\"'
				|| c == '/' || c == '_'
				|| c == '<' || c == '>'
				|| c >= 'A' && c <= 'z'
				|| c >= '0' && c <= '9')
			{
				alphabet.push_back(c);
			}
		}

		if (!alphabet.empty())
		{
			m_DataList.push_back(alphabet);
		}
	}
}

std::vector<std::string> TextLoader::GetLoadData(void)
{
	return m_DataList;
}

void TextLoader::DeleteLoadData(void)
{
	auto it = m_DataList.begin();
	auto end = m_DataList.end();

	while (it != end)
	{
		(*it).clear();

		it = m_DataList.erase(it);

		end = m_DataList.end();
	}

	m_DataList.clear();
}

long double TextLoader::to_long_double(std::string str)
{
	long double value = LDBL_MIN;
	long double tmp = 1.0f;

	if (!str.empty())
	{
		if (str.size() < 15)
		{
			if (str[0] == '-')
			{
				tmp = -1.0;
				str.erase(str.begin());
			}
			else if(str.size() >= 14)
			{
				return LDBL_MIN;
			}

			int k = (int)str.size() - 1;
			value = 0;
			for (int i = 0; i < str.size(); ++i)
			{
				if (str[i] == '.')
				{
					k = i - 1;
					break;
				}
			}

			for (int i = 0; i < str.size(); ++i)
			{
				char c = str[i];

				if (c == '.') continue;

				if (c >= '0' && c <= '9')
				{
					value += (long double)atoi(&c) * std::pow(10.0, k) * tmp;
				}
				else
				{
					return LDBL_MIN;
				}
			}
		}
	}

	return value;
}
