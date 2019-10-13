#ifndef LOGGER_H
#define LOGGER_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

#ifdef DEBUG_BUILD
	
	#define MIESTAS_LOG_INFO(...)  spdlog::info(__VA_ARGS__);
	#define MIESTAS_LOG_WARN(...) spdlog::warn(__VA_ARGS__);
	#define MIESTAS_LOG_ERROR(...) spdlog::error(__VA_ARGS__);
	#define MIESTAS_LOG_CRITICAL(...) spdlog::critical(__VA_ARGS__);

#else

	#define MIESTAS_LOG_INFO(...) 
	#define MIESTAS_LOG_WARN(...) 
	#define MIESTAS_LOG_ERROR(...) 
	#define MIESTAS_LOG_CRITICAL(...) 

#endif // DEBUG_BUILD


#ifdef DEBUG_BUILD

	#define MIESTAS_ASSERT(CONDITION, ...)   if(!CONDITION){ MIESTAS_LOG_ERROR("Assert failure at line {0} in file {1}: {2} ",__LINE__, __FILE__, __VA_ARGS__) __debugbreak();}
	#define MIESTAS_FAILURE(...) MIESTAS_LOG_CRITICAL("Exception occured at line {0} in file {1}: {2}", __LINE__, __FILE__, __VA_ARGS__) __debugbreak();
#else

	#define MIESTAS_ASSERT(CONDITION, ...)  
	#define MIESTAS_FAILURE(...) 
#endif // DEBUG_BUILD




#endif // LOGGER_H