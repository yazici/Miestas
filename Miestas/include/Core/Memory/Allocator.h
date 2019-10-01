#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include<cstddef>

namespace Miestas
{
	namespace Core
	{
		struct Allocator
		{

			Allocator() {}

			virtual ~Allocator() = default;

			virtual void* allocate(std::size_t blockSize, std::size_t alignment = 8) = 0;

			virtual void free(void* memoryBlock) = 0;


		};
	}
}

#endif