#include "Timer.h"
#include "Logger/Logger.h"

namespace Miestas
{
	namespace Core
	{
		void Timer::reset()
		{
			m_startTime = std::chrono::high_resolution_clock::now();
		}

		void Timer::stop()
		{
			auto endTime = std::chrono::high_resolution_clock::now();

			auto castedStartTime = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTime).time_since_epoch().count();
			auto castedEndTime = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();

			auto castedDuration = castedEndTime - castedStartTime;

			MIESTAS_LOG_INFO("Seconds per frame: {0} milliseconds", castedDuration * 0.001)

		}
	}
}
