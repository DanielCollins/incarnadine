//========================================================================
//
// Copyright (c) 2010 Daniel Flahive
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#include "config_conf.h"

bool ConfigConfParser::loadConf(const std::string& filename, ConfigManager& config)
{
	std::ifstream configFile;
	int linenum;
	std::string line;
	std::string key;
	std::string value;
	CONFIG_TYPE valuetype;
	ConfigValue actualvalue;
	std::string::size_type equalsPos;

	configFile.open(filename.c_str(), std::ios::in);
	if (configFile.is_open())
	{
		linenum = 0;
		while (!configFile.eof())
		{
			linenum++;
			std::getline(configFile, line);

			stripWhitespace(line);
			stripComments(line);
			
			if (line.length() < 1)
				continue;

			// Split the key and value.
			equalsPos = line.find_first_of('=');
			if (equalsPos == std::string::npos || (equalsPos < 1 || equalsPos == line.length() - 1))
			{
				std::cerr << "Parse error on line " << linenum << ": Expected key-value pair." << std::endl;
				continue;
			}

			key = line.substr(0, equalsPos);
			value = line.substr(equalsPos + 1, line.length() - (equalsPos + 1));

			// Strip whitespace from either side of the key and value.
			stripWhitespace(key);
			stripWhitespace(value);

			if (key.length() < 1 || value.length() < 1)
			{
				std::cerr << "Parse error on line " << linenum << ": Key or value not specified." << std::endl;
				continue;
			}

			if (!config.isValidKey(key))
			{
				std::cerr << "Parse error on line " << linenum << ": Invalid key name." << std::endl;
				continue;
			}

			valuetype = getType(value, actualvalue);

			if (valuetype == CONFIG_INVALID)
			{
				std::cerr << "Parse error on line " << linenum << ": Invalid value." << std::endl;
			}
			else
			{
				// Add the item to the configuration manager. If the item is a string, free it after it has
				// been copied into the config manager (because it was allocated by the 'getType' function).
				switch (valuetype)
				{
				case CONFIG_TYPE_INTEGER:
					config.setInteger(key, actualvalue.intValue);
					break;
				case CONFIG_TYPE_DOUBLE:
					config.setDouble(key, actualvalue.doubleValue);
					break;
				case CONFIG_TYPE_BOOLEAN:
					config.setBoolean(key, actualvalue.booleanValue);
					break;
				case CONFIG_TYPE_STRING:
					config.setString(key, *actualvalue.stringValue);
					delete actualvalue.stringValue;
					break;
				}

			}

		}

		configFile.close();
		return true;
	}
	
	return false;
}

bool ConfigConfParser::saveConf(const std::string& filename, ConfigManager& config)
{
	// Save the configuration to file.
	// TODO: Make it so that any impact on user formatting is minimal. Currently, it
	// just overwrites the whole file, so that means comments and formatting is lost, which is bad.
	std::ofstream configFile;
	ConfigManager::const_iterator iter;

	configFile.open(filename.c_str(), std::ios::out);
	if (configFile.is_open())
	{
		for (iter = config.getIteratorBegin(); iter != config.getIteratorEnd(); iter++)
		{
			switch (iter->second.type)
			{
			case CONFIG_TYPE_INTEGER:
				configFile << iter->first << " = " << iter->second.value.intValue << std::endl;
				break;
			case CONFIG_TYPE_DOUBLE:
				configFile << iter->first << " = " << iter->second.value.doubleValue << std::endl;
				break;
			case CONFIG_TYPE_BOOLEAN:
				if (iter->second.value.booleanValue)
					configFile << iter->first << " = true" << std::endl;
				else
					configFile << iter->first << " = false" << std::endl;
				break;
			case CONFIG_TYPE_STRING:
				configFile << iter->first << " = " << *iter->second.value.stringValue << std::endl;
				break;
			}
		}

		configFile.close();
		return true;
	}

	return false;
}

void ConfigConfParser::stripWhitespace(std::string& str)
{
	// Remove spaces and tabs from the beginning and end of the string.
	std::string::iterator pos;

	if (str.length() < 1)
		return;
	
	// Find out where the whitespace ends (from the start of the string).
	for (pos = str.begin(); pos < str.end(); pos++)
	{
		if ((*pos) != ' ' && (*pos) != '\t')
			break;
	}

	if (pos == str.end())
	{
		// Entire string consists of whitespace.
		str.clear();
		return;
	}

	str.erase(str.begin(), pos);

	// Find out where the whitespace starts (from the end of the string).
	for (pos = str.end() - 1; pos >= str.begin(); pos--)
	{
		if ((*pos) != ' ' && (*pos) != '\t')
			break;
	}

	str.erase(pos + 1, str.end());
}

void ConfigConfParser::stripComments(std::string& str)
{
	// Any '#' comment symbol that is encountered, that is not within a quoted segment, will
	// cause the rest of the line to be ignored after that point.
	std::string::iterator iter;
	bool inQuote = false;
	bool inEscape = false;

	for (iter = str.begin(); iter != str.end(); iter++)
	{
		if ((*iter) == '\"' && !inEscape)
			inQuote = !inQuote;
		else if ((*iter) == '\\' && !inEscape)
			inEscape = true;
		else if ((*iter) == '#' && !inQuote)
			break;
		else
			inEscape = false;
	}

	if (iter != str.end())
		str.erase(iter, str.end());
}

CONFIG_TYPE ConfigConfParser::getType(const std::string& value, ConfigValue& outValue)
{
	// Try to validate the value type given.
	if (value.length() < 1)
		return CONFIG_INVALID;

	// Integer?
	if ((value.at(0) == '-' && value.length() > 1) || isdigit(value.at(0)))
	{
		// Make sure the rest of the string is comprised of only digits.
		bool valid = true;
		std::string::const_iterator iter;
		for (iter = value.begin() + 1; iter != value.end(); iter++)
		{
			if (!isdigit((*iter)))
			{
				valid = false;
				break;
			}
		}

		if (valid)
		{
			outValue.intValue = atoi(value.c_str());
			return CONFIG_TYPE_INTEGER;
		}
	}

	// Double?
	if ((value.at(0) == '-' && value.length() > 1) || (value.at(0) == '.' && value.length() > 1) || isdigit(value.at(0)))
	{
		// Make sure the rest of the string is comprised only of digits, and just one '.'.
		bool hasFloatPortion = value.at(0) == '.';
		bool valid = true;
		std::string::const_iterator iter;
		for (iter = value.begin() + 1; iter != value.end(); iter++)
		{
			if ((*iter) == '.' && hasFloatPortion)
			{
				valid = false;
				break;
			}
			else if ((*iter) == '.' && !hasFloatPortion)
			{
				hasFloatPortion = true;
			}
			else if (!isdigit((*iter)))
			{
				valid = false;
				break;
			}
		}

		if (valid)
		{
			outValue.doubleValue = atof(value.c_str());
			return CONFIG_TYPE_DOUBLE;
		}
	}

	// Boolean?
	if (value == "true")
	{
		outValue.booleanValue = 1;
		return CONFIG_TYPE_BOOLEAN;
	}
	else if (value == "false")
	{
		outValue.booleanValue = 0;
		return CONFIG_TYPE_BOOLEAN;
	}

	// String?
	if (value.at(0) == '\"')
	{
		// Make sure there's only one quote at the start and end of the value, and
		// no unescaped quotes in-between.
		std::string::const_iterator iter;
		bool inQuote = false;
		bool inEscape = false;

		for (iter = value.begin(); iter != value.end(); iter++)
		{
			if ((*iter) == '\"' && !inEscape && !inQuote)
				inQuote = true;
			else if ((*iter) == '\"' && !inEscape && inQuote)
			{
				inQuote = false;
				break;
			}
			else if ((*iter) == '\\' && !inEscape)
				inEscape = true;
			else if ((*iter) == '#' && !inQuote)
				break;
			else
				inEscape = false;
		}

		if (iter >= value.end() - 1 && !inQuote)
		{
			outValue.stringValue = new std::string(value.substr(1, value.length() - 2));
			return CONFIG_TYPE_STRING;
		}
	}

	return CONFIG_INVALID;
}
