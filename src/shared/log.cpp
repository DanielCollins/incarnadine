//========================================================================
//
// Copyright (c) 2010 David Forrest
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

Logger::Logger(char* filename, LogLevel loggingl = LOG_WARNING, LogLevel stdoutl = LOG_ALL)// : logginglevel(loggingl), stdoutlevel(stdoutl)
{
	logfile = fopen(filename, "a");
	logginglevel = loggingl;
	stdoutlevel = stdoutl;
}

Logger::~Logger()
{
	fclose(logfile);
	delete logfile;
}

void Logger::log(LogLevel level, char* message)
{
	if(level >= logginglevel || level >= stdoutlevel)
	{
		time_t rawtime;
		struct tm * timeinfo;
		char timebuffer [21], typestr [9];

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(timebuffer, 21, "(%y/%m/%d %H:%M:%S) ", timeinfo);

		switch(level)
		{
			case LOG_ALL:
				strcpy(typestr, "ALL     ");
				break;
			case LOG_TRACE:
				strcpy(typestr, "TRACE   ");
				break;
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
			case LOG_FATAL:
				strcpy(typestr, "FATAL   ");
				break;
			case LOG_NONE:
				strcpy(typestr, "NONE    ");
				break;
		}


		if(level >= logginglevel)
		{
			fputs(timebuffer, logfile);
			fputs(typestr,    logfile);
			fputs(message,    logfile);
			fputs("\n",       logfile);
		}
		if(level >= stdoutlevel)
		{
			fputs(timebuffer, stdout);
			fputs(typestr,    stdout);
			fputs(message,    stdout);
			fputs("\n",       stdout);
		}
	}
}

LogLevel Logger::getLogLevel()
{
	return logginglevel;
}

void Logger::setLogLevel(LogLevel level)
{
	logginglevel = level;
}

