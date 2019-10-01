#include "LinearAllocator.h"
#include "Logger/Logger.h"

namespace Miestas
{
	namespace Core
	{
		LinearAllocator::LinearAllocator(std::size_t memorySize): m_memoryStart(nullptr), m_memorySize(memorySize),
			m_memoryUsed(0), m_numAllocations(0), m_currentPointer(nullptr)
		{
			init();
		}

		LinearAllocator::~LinearAllocator()
		{
			MIESTAS_ASSERT(m_numAllocations == 0 && m_memoryUsed == 0, "Unable to destroy memory allocator. Memory is still being used.")
			destroy();
		}

		void * LinearAllocator::allocate(std::size_t blockSize, std::size_t alignment)
		{
			MIESTAS_ASSERT(blockSize >  0, "Requested memory size should be greater than 0.")
			MIESTAS_ASSERT((alignment & alignment - 1) == 0, "Alignment should be a power of two!")
			
			// Calculate adjustment
			auto actualBytesToAllocate = blockSize + alignment;

			auto curPtr = reinterpret_cast<uintptr_t>(m_currentPointer);
			auto unalignedAddress = reinterpret_cast<uintptr_t>(m_currentPointer);
			curPtr += actualBytesToAllocate;
			m_currentPointer = reinterpret_cast<void*>(curPtr);

			ptrdiff_t adjustment = alignment - (unalignedAddress & (alignment - 1));

			uintptr_t alignedAddress = unalignedAddress + adjustment;

			uint8_t* addressU8 = reinterpret_cast<uint8_t*>(alignedAddress);

			//addressU8[-1] = static_cast<uint8_t>(adjustment);

			return static_cast<void*>(addressU8);
		}

		void LinearAllocator::free(void * address)
		{
			// TODO: Right now, addresses being freed aren't allocated again. Need to change that.
			
			auto memoryBlock = reinterpret_cast<uint8_t*>(address);
			auto alignedAddress = reinterpret_cast<uintptr_t>(address);
			auto adjustment = static_cast<ptrdiff_t>(memoryBlock[-1]);

			auto unalignedAddress = alignedAddress - adjustment;

			auto memoryAddress = reinterpret_cast<void*>(unalignedAddress);
			
			// TODO: Figure out a way to reuse this block
		}

		

		void LinearAllocator::init()
		{
			m_memoryStart = ::malloc(m_memorySize);
			m_currentPointer = m_memoryStart;
			MIESTAS_LOG_INFO("Successfully created Linear Memory Allocator. Start: {0}, Size: {1}", m_memoryStart, m_memorySize)
		}

		void LinearAllocator::destroy()
		{
			free(m_memoryStart);
			MIESTAS_LOG_INFO("Successfully destroyed Linear Memory Allocator.")
		}
	}
}