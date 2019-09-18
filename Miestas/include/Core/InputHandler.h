#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Core/Event/Observable.h"
#include "Core/Event/EventQueue.h"


namespace Miestas
{
	namespace Core
	{
		class InputHandler: public Observable
		{
		private:
			EventQueue* m_eventQueue;
		public:

			void init();

			virtual void onEvent(std::shared_ptr<Event> event) override;

			virtual void setEventQueue(EventQueue* eq) override;

			virtual void emitEvent(std::shared_ptr<Event> event) override;
		};
	}
}


#endif