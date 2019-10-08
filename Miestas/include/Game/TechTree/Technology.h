#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H

#include "Game/Resource/Resource.h"

#include<string>


namespace Miestas
{
	namespace Game
	{
		struct Technology
		{
			std::string m_Name;
			Resource m_toUnlock;
			bool m_isUnlocked;

			Technology() = default;

			Technology(const std::string& name, const Resource& resource, bool unlocked) :
				m_Name(name), m_toUnlock(resource), m_isUnlocked(unlocked)
			{

			}

			bool operator==(const Technology& tech) const
			{
				return m_Name == tech.m_Name;
			}
		};
	}
}

#endif