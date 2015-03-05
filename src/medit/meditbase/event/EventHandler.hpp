/*
 * EventHandler.hpp
 *
 *  Created on: Feb 26, 2015
 *      Author: petr
 */

#ifndef EVENTHANDLER_HPP_
#define EVENTHANDLER_HPP_

namespace Medit
{
namespace MeditBase
{
namespace Event
{

template<class E>
class EventHandler
{
public:

    typedef int Event;

    EventHandler()
    {
    }

    virtual ~EventHandler()
    {
    }

    virtual void handle(E* e) = 0;
};

} /* namespace Event */
} /* namespace MeditBase */
} /* namespace Medit */

#endif /* EVENTHANDLER_HPP_ */
