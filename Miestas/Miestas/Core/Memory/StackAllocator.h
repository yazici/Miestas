#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H


namespace Miestas
{
	namespace Core
	{
		class StackAllocator
		{
		private:
			void* m_startPtr = nullptr;
			void* m_curPtr = nullptr;
			unsigned int m_Allocations = 0;

			StackAllocator() = default;

			StackAllocator(const StackAllocator& alloc) = delete;

			~StackAllocator();

			void init(std::size_t memorySize);

			template<typename T>
			T* allocate(std::size_t blockSize);

			void free(void* memoryBlock);

			void reset(); 
		};
	}
}

#endif