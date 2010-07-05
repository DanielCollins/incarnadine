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

Logger::Logger(string* filename, LogLevel levelLog = LOG_WARNING, LogLevel levelOut = LOG_ALL)
{
	logStream.open(filename->c_str(), ios::in | ios::out | ios::app);
	loggingLevel = levelLog;
	stdoutLevel = levelOut;
}

Logger::~Logger()
{
	logStream.close();
}

void Logger::log(LogLevel level, const char* message, int msgLength)
{
	if(level >= loggingLevel || level >= stdoutLevel)
	{
		const int timestampLength = 21;		
		time_t rawTime;
		struct tm* timeInfo;
		char timeBuffer [timestampLength], typestr [9];

		time(&rawTime);
		timeInfo = localtime(&rawTime);
		strftime(timeBuffer, timestampLength, "%y/%m/%d %H:%M:%S ", timeInfo);

		switch(level)
		{
			case LOG_DEBUG:
				strcpy(typestr, "DEBUG   ");
				break;
			case LOG_INFO:
				strcpy(typestr, "INFO    ");
				break;
			case LOG_WARNING:
				strcpy(typestr, "WARNING ");
				break;
			case LOG_ERROR:
				strcpy(typestr, "ERROR   ");
				break;
			default:
				return;
		}


		if(level >= loggingLevel)
		{
			logStream<<timeBuffer<<typestr<<message<< "\n";
		}
		if(level >= stdoutLevel)
		{
			fputs(timeBuffer, stdout);
			fputs(typestr,    stdout);
			fputs(message,    stdout);
			fputs("\n",       stdout);
		}
	}
}
void Logger::log(LogLevel level, string* message)
{
	log(level, message->c_str(), message->length()+1);
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

