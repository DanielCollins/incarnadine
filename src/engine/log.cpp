//========================================================================
//
// Copyright (c) 2010 David Forrest, Daniel Collins
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

#include "log.h"

Logger::Logger(string filename, LogLevel levelLog = LOG_WARNING, LogLevel levelOut = LOG_ALL)
{
	logStream.open(filename->c_str(), ios::in | ios::out | ios::app);
	loggingLevel = levelLog;
	stdoutLevel = levelOut;
}

Logger::~Logger()
{
	logStream.close();
}

void Logger::log(LogLevel level, string message)
{
	if(level >= loggingLevel || level >= stdoutLevel)
	{
		const int timestampLength = 21;		
		time_t rawTime;
		struct tm* timeInfo;
		char timeString[timestampLength];
		string typestr;	
		time(&rawTime);
		timeInfo = localtime(&rawTime);
		strftime(timeString, timestampLength, "%y/%m/%d %H:%M:%S ", timeInfo);
		switch(level)
		{
			case LOG_DEBUG:
				typestr = "DEBUG   ";
				break;
			case LOG_INFO:
				typestr = "INFO    ";
				break;
			case LOG_WARNING:
				typestr = "WARNING ";
				break;
			case LOG_ERROR:
				typestr = "ERROR   ";
				break;
			default:
				return;
		}
		if(level >= stdoutLevel)
			cout<<timeString<<typestr<<message<<endl;
		if(level >= loggingLevel && logStream.is_open())
			logStream<<timeString<<typestr<<message<<endl;
	}
}

LogLevel Logger::getLoggingLevel()
{
	return loggingLevel;
}

void Logger::setLoggingLevel(LogLevel level)
{
	loggingLevel = level;
}

LogLevel Logger::getStdoutLevel()
{
	return stdoutLevel;
}

void Logger::setStdoutLevel(LogLevel level)
{
	stdoutLevel = level;
}
