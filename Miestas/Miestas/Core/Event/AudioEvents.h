#ifndef AUDIO_EVENTS_H
#define AUDIO_EVENTS_H

#include "Event.h"

#include<string>

namespace Miestas
{
	namespace Core
	{
		struct PlaySoundEvent : public Event
		{
			REGISTER_TYPE(PlaySoundEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			std::string m_soundToPlay;

			PlaySoundEvent(const std::string& soundToPlay) : m_soundToPlay(soundToPlay)
			{}

			PlaySoundEvent(const std::string&& soundToPlay) : m_soundToPlay(std::move(soundToPlay))
			{}

			GET_TYPE(override)
			GET_CATEGORY(override)

		};
	}
}

#endif