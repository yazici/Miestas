#include "TechTree.h"

namespace Miestas
{
	namespace Game
	{
		void TechTree::insert(const Technology & techKey, const std::vector<Technology>& techDepen)
		{
			m_techTree[techKey] = techDepen;
		}

		void TechTree::insert(const Technology && techKey, const std::vector<Technology>&& techDepen)
		{
			m_techTree[techKey] = std::move(techDepen);
		}

		void TechTree::addDependency(const Technology & key, const Technology & techToAdd)
		{
			m_techTree[key].push_back(techToAdd);
		}

		const std::vector<Technology>& TechTree::getDependencies(const Technology & tech)
		{
			return m_techTree[tech];
		}

		bool TechTree::isUnlockable(const Technology & tech) const
		{
			if (m_techTree.find(tech) == m_techTree.end())
				return false;

			const auto& depen = m_techTree.find(tech)->second;

			for (const auto& t : depen)
			{
				if (!t.m_isUnlocked)
					return false;
			}

			return true;
		}







	}
}