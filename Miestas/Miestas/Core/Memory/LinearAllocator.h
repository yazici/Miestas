#ifndef LINEAR_ALLOCATOR_H
#define LINEAR_ALLOCATOR_H

#include "Allocator.h"

#include<cstddef>
#include<cstdlib>

namespace Miestas
{
	namespace Core
	{
		class LinearAllocator : public Allocator
		{
		private:
			void* m_currentPointer;
			void* m_memoryStart;
			std::size_t m_memorySize;
			std::size_t m_memoryUsed;
			std::size_t m_numAllocations;
		
		public:

			LinearAllocator(std::size_t memorySize);

			virtual ~LinearAllocator() override;

			virtual void* allocate(std::size_t blockSize, std::size_t aligment) override;

			virtual void free(void* memoryBlock) override;

		private:


			void init();

			void destroy();
		};


	}
}

#endif