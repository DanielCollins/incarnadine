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

#ifndef SHARED_LOG_H
#define SHARED_LOG_H

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

enum LogLevel {	LOG_ALL   = 0,
                LOG_DEBUG = 1,
                LOG_INFO  = 2,
                LOG_WARNING = 3,
                LOG_ERROR = 4,
                LOG_NONE  = 5};

class Logger
{
	protected:
		fstream* logStream;
		LogLevel loggingLevel;
		LogLevel stdoutLevel;
	
	public:
		Logger(string* filename, LogLevel levelLog, LogLevel levelOut);
		Logger(char* filename, int fnLength, LogLevel levelLog, LogLevel levelOut);
		~Logger();
		
		void log(LogLevel level, const char* message, int msgLength);
		void log(LogLevel level, string* message);
		
		LogLevel getLoggingLevel();
		void setLoggingLevel(LogLevel level);
		LogLevel getStdoutLevel();
		void setStdoutLevel(LogLevel level);
};

#endif //SHARED_LOG_H

