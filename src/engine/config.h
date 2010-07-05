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

#ifndef ENGINE_CONFIG_H
#define ENGINE_CONFIG_H

#include <map>
#include <string>

enum CONFIG_TYPE { CONFIG_NOTFOUND, CONFIG_TYPE_INTEGER, CONFIG_TYPE_DOUBLE, CONFIG_TYPE_BOOLEAN, CONFIG_TYPE_STRING };

typedef union
{
	int intValue;
	double doubleValue;
	bool booleanValue;
	std::string* stringValue;
} ConfigValue;

typedef struct
{
	CONFIG_TYPE type;
	ConfigValue value;
} ConfigItem;


class ConfigManager
{
public:
	ConfigManager();
	~ConfigManager();

	int getInteger(const std::string& name, int defaultValue);
	double getDouble(const std::string& name, double defaultValue);
	bool getBoolean(const std::string& name, bool defaultValue);
	std::string getString(const std::string& name, const std::string& defaultValue);

	void setInteger(const std::string& name, int value);
	void setDouble(const std::string& name, double value);
	void setBoolean(const std::string& name, bool value);
	void setString(const std::string& name, const std::string& value);

	void remove(const std::string& name);
	CONFIG_TYPE getItemType(const std::string& name);
	

private:
	inline void freeItem(std::map<std::string, ConfigItem>::iterator iter);
	std::map<std::string, ConfigItem> configItems;
};


#endif // ENGINE_CONFIG_H
