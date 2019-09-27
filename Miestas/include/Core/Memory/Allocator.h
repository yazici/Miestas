#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include<cstddef>

namespace Miestas
{
	namespace Core
	{
		class Allocator
		{
		private:
			std::size_t m_memorySize;
			std::size_t m_memoryUsed;

		public:

			Allocator(std::size_t memorySize) : m_memorySize(memorySize), m_memoryUsed(0)
			{}

			virtual ~Allocator() = default;

			virtual void* allocate(std::size_t blockSize, std::size_t alignment) = 0;

			virtual void free(void* memoryBlock) = 0;


		};
	}
}

#endif