#ifndef TIMER_H
#define TIMER_H

#include<chrono>

namespace Miestas
{
	namespace Core
	{
		class Timer
		{
		private:
			std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
		public:
			
			Timer() = default;

			void reset();

			void stop();

		};
	}
}

#endif