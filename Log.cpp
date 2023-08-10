#include "Log.hpp"
#include <iostream>

Log::LogLevels Log::m_LogLevel = Log::LEVEL_ERROR;

void Log::SetLevel(LogLevels level) {
	m_LogLevel = level;
}

void Log::Warn(const char* message) {
	if(m_LogLevel >= LEVEL_WARNING)
		std::cout << "[WARNING]: " << message << std::endl;
}

void Log::Error(const char* message) {
	if (m_LogLevel >= LEVEL_ERROR)
		std::cout << "[ERROR]: " << message << std::endl;
}

void Log::Info(const char* message) {
	if (m_LogLevel >= LEVEL_INFO)
		std::cout << "[INFO]: " << message << std::endl;
}