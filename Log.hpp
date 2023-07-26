#pragma once

class Log {
public:
	enum LogLevels: unsigned char {
		LEVEL_ERROR,
		LEVEL_WARNING,
		LEVEL_INFO
	};

public:
	void SetLevel(LogLevels level);
	void Warn(const char* message);
	void Error(const char* message);
	void Info(const char* message);

private:
	LogLevels m_LogLevel = LEVEL_ERROR;
};