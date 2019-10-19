#include "StackAllocator.h"
#include "Logger/Logger.h"

#include<cstdlib>

namespace Miestas
{
	namespace Core
	{
		StackAllocator::~StackAllocator()
		{
			::free(m_startPtr);
			m_startPtr = nullptr;
			m_curPtr = nullptr;
			m_Allocations = 0;
		}

		void StackAllocator::init(std::size_t memorySize)
		{
			if (m_startPtr != nullptr)
				return;

			m_startPtr = ::malloc(memorySize);
			
			if (!m_startPtr)
			{
				MIESTAS_FAILURE("StackAllocator: Unable to allocate memory of size: {0} bytes.", memorySize)
			}

			m_curPtr = m_startPtr;

		}

		template<typename T>
		void* StackAllocator::allocate(std::size_t memorySize)
		{
			MIESTAS_ASSERT(memorySize > 0, "StackAllocator: Memory size should be greater than 0.")

			
		}

		void StackAllocator::free(void* memoryBlock)
		{
			// free doesn't do anything. All the memory will be reset at the start of every frame, after dispatching
			return; 
		}

		void StackAllocator::reset()
		{
			m_curPtr = m_startPtr;
			m_Allocations = 0;
		}
	}
}