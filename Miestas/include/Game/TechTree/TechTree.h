#ifndef TECH_TREE_H
#define TECH_TREE_H

#include "Technology.h"

#include<unordered_map>
#include<vector>

namespace Miestas
{
	namespace Game
	{
		class TechTree
		{
		private:
			std::unordered_map<Technology, std::vector<Technology>> m_techTree; // stores the dependencies of each technology
		
		public:

			TechTree() = default;

			void insert(const Technology& techKey, const std::vector<Technology>& techDepen);

			void insert(const Technology&& techKey, const std::vector<Technology>&& techDepen);

			void addDependency(const Technology& key, const Technology& techToAdd);

			const std::vector<Technology>& getDependencies(const Technology& tech);

			bool isUnlockable(const Technology& tech) const;
		};
	}
}

#endif