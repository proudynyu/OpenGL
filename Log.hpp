#pragma once

class Log {
public:
	enum LogLevels: unsigned char {
		LEVEL_ERROR,
		LEVEL_WARNING,
		LEVEL_INFO
	};

public:
	static void SetLevel(LogLevels level);
	static void Warn(const char* message);
	static void Error(const char* message);
	static void Info(const char* message);

private:
	static LogLevels m_LogLevel;
};