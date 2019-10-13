#ifndef RESOURCE_H
#define RESOURCE_H

namespace Miestas
{
	namespace Game
	{
		using UInt = unsigned int;
		struct Resource
		{
			UInt m_Money;
			UInt m_Wood;
			UInt m_Diamond;
			UInt m_Food;

			Resource() = default;

			Resource(UInt money, UInt wood, UInt diamond, UInt food) : m_Money(money), m_Wood(wood), m_Diamond(diamond), m_Food(food)
			{}

			

		};
	}
}
#endif