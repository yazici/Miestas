#ifndef SOUND_LIBRARY_H
#define SOUND_LIBRARY_H

#include "Core/Event/Observable.h"
#include "Core/Event/Event.h"

#include<unordered_map>
#include<string>
#include<memory>

#include "irrKlang/irrKlang.h"

namespace Miestas
{
	namespace Core
	{
		class SoundLibrary : public Observable
		{
		private:
			irrklang::ISoundEngine* m_Engine;
			std::unordered_map<std::string, std::string> m_Sounds;
			EventQueue* m_eventQueue;

		public:

			~SoundLibrary();

			void init();

			void addSongToLibrary(const std::string& soundName, const std::string& soundFile);

			void destroy();

			void onEvent(std::shared_ptr<Event> event);

			void setEventQueue(EventQueue* eq);

			void emitEvent(std::shared_ptr<Event> event);

		private:

			void playSound(const std::string& sound, bool looped = false);

		};
	}
}

#endif