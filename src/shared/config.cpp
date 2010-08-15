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

#include "config.h"

ConfigManager::ConfigManager()
{
}

ConfigManager::~ConfigManager()
{
	// Free any items that have memory allocated.
	std::map<std::string, ConfigItem>::iterator iter;
	for (iter = configItems.begin(); iter != configItems.end(); iter++)
	{
		freeItem(iter);
	}

}

int ConfigManager::getInteger(const std::string& name, int defaultValue)
{
	std::map<std::string, ConfigItem>::iterator item = configItems.find(name);

	if (item == configItems.end() || item->second.type != CONFIG_TYPE_INTEGER)
		return defaultValue;
	else
		return item->second.value.intValue;
}


double ConfigManager::getDouble(const std::string& name, double defaultValue)
{
	std::map<std::string, ConfigItem>::iterator item = configItems.find(name);

	if (item == configItems.end() || item->second.type != CONFIG_TYPE_DOUBLE)
		return defaultValue;
	else
		return item->second.value.doubleValue;
}

bool ConfigManager::getBoolean(const std::string& name, bool defaultValue)
{
	std::map<std::string, ConfigItem>::iterator item = configItems.find(name);

	if (item == configItems.end() || item->second.type != CONFIG_TYPE_BOOLEAN)
		return defaultValue;
	else
		return item->second.value.booleanValue;
}


std::string ConfigManager::getString(const std::string& name, const std::string& defaultValue)
{
	std::map<std::string, ConfigItem>::iterator item = configItems.find(name);

	if (item == configItems.end() || item->second.type != CONFIG_TYPE_STRING)
		return defaultValue;
	else
		return *item->second.value.stringValue;
}

void ConfigManager::setInteger(const std::string& name, int value)
{
	ConfigItem newItem;
	newItem.type = CONFIG_TYPE_INTEGER;
	newItem.value.intValue = value;

	// If the item already exists, then free the existing item and change the type
	// to the new type. Otherwise, just insert the new item.
	std::map<std::string, ConfigItem>::iterator item = configItems.find(name);
	if (item != configItems.end())
	{
		freeItem(item);
		item->second = newItem;
	}
	else
	{
		configItems[name] = newItem;
	}
}

void ConfigManager::setDouble(const std::string& name, double value)
{
	ConfigItem newItem;
	newItem.type = CONFIG_TYPE_DOUBLE;
	newItem.value.doubleValue = value;

	// If the item already exists, then free the existing item and change the type
	// to the new type. Otherwise, just insert the new item.
	std::map<std::string, ConfigItem>::iterator item = configItems.find(name);
	if (item != configItems.end())
	{
		freeItem(item);
		item->second = newItem;
	}
	else
	{
		configItems[name] = newItem;
	}
}


void ConfigManager::setBoolean(const std::string& name, bool value)
{
	ConfigItem newItem;
	newItem.type = CONFIG_TYPE_BOOLEAN;
	newItem.value.booleanValue = value;

	// If the item already exists, then free the existing item and change the type
	// to the new type. Otherwise, just insert the new item.
	std::map<std::string, ConfigItem>::iterator item = configItems.find(name);
	if (item != configItems.end())
	{
		freeItem(item);
		item->second = newItem;
	}
	else
	{
		configItems[name] = newItem;
	}
}

void ConfigManager::setString(const std::string& name, const std::string& value)
{
	ConfigItem newItem;
	newItem.type = CONFIG_TYPE_STRING;
	newItem.value.stringValue = new std::string(value);

	// If the item already exists, then free the existing item and change the type
	// to the new type. Otherwise, just insert the new item.
	std::map<std::string, ConfigItem>::iterator item = configItems.find(name);
	if (item != configItems.end())
	{
		freeItem(item);
		item->second = newItem;
	}
	else
	{
		configItems[name] = newItem;
	}
}

ConfigManager::const_iterator ConfigManager::getIteratorBegin() const
{
	return configItems.begin();
}

ConfigManager::const_iterator ConfigManager::getIteratorEnd() const
{
	return configItems.end();
}

void ConfigManager::remove(const std::string& name)
{
	std::map<std::string, ConfigItem>::iterator item = configItems.find(name);
	if (item != configItems.end())
	{
		freeItem(item);
		configItems.erase(item);
	}
}

CONFIG_TYPE ConfigManager::getItemType(const std::string& name)
{
	std::map<std::string, ConfigItem>::iterator item = configItems.find(name);
	if (item != configItems.end())
	{
		return item->second.type;
	}
	else
	{
		return CONFIG_INVALID;
	}
}

void ConfigManager::freeItem(std::map<std::string, ConfigItem>::iterator iter)
{
	// If the item is a string, release any memory it's using. Otherwise, do nothing.
	if (iter->second.type == CONFIG_TYPE_STRING && iter->second.value.stringValue != NULL)
	{
		delete iter->second.value.stringValue;
		iter->second.value.stringValue = NULL;
	}
}

bool ConfigManager::isValidKey(const std::string& name, std::string::size_type offset)
{
	if (name.length() < 1 || offset > name.length() - 1)
		return false;

	// First character should be alphabetic or '_'.
	if (isalpha(name.at(offset)) || name.at(offset) == '_')
	{
		// Subsequent characters can be alphanumeric and include a '_'.
		// Also, a '.' character can appear as a section separator, and follows
		// the same rules.
		for (std::string::size_type i = offset + 1; i < name.length(); i++)
		{
			if (name[i] == '.')
			{
				// Recursively validate the subsection key.
				return isValidKey(name, i + 1);
			}
			else if (!isalnum(name[i]) && name[i] != '_')
			{
				// Invalid key.
				return false;
			}
		}

		// Key is valid if we reach here.
		return true;
	}

	return false;
}

void ConfigManager::debugDump()
{
	std::map<std::string, ConfigItem>::iterator iter;
	for (iter = configItems.begin(); iter != configItems.end(); iter++)
	{
		std::cout << "Key = " << iter->first << ", Value = ";
		switch (iter->second.type)
		{
		case CONFIG_TYPE_INTEGER:
			std::cout << iter->second.value.intValue;
			break;
		case CONFIG_TYPE_DOUBLE:
			std::cout << iter->second.value.doubleValue;
			break;
		case CONFIG_TYPE_BOOLEAN:
			if (iter->second.value.booleanValue)
				std::cout << "true";
			else
				std::cout << "false";
			break;
		case CONFIG_TYPE_STRING:
			std::cout << "\"" << *iter->second.value.stringValue << "\"";
		}
		std::cout << std::endl;
	}
}
