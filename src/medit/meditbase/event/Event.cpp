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

}

Event::Event(void* sender) : Event()
{
    this->sender = sender;
}

Event::Event(const Event& other)
{
    sender = other.sender;
    propagate = other.propagate;
}

Event::~Event()
{
    // do nothing
}

} /* namespace Event */
} /* namespace MeditBase */
} /* namespace Medit */
