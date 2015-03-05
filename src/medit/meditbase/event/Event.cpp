/*
 * Event.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: petr
 */

#include "Event.hpp"

namespace Medit
{
namespace MeditBase
{
namespace Event
{

Event::Event()
{
    sender = 0x0;
    propagate = true;
    autoDestroy = true;
}

Event::Event(void* sender) : Event()
{
    this->sender = sender;
}

Event::Event(const Event& other)
{
    sender = other.sender;
    propagate = other.propagate;
    autoDestroy = other.autoDestroy;
}

Event::~Event()
{
    // do nothing
}

} /* namespace Event */
} /* namespace MeditBase */
} /* namespace Medit */
