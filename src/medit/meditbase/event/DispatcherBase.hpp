/*
 * DispatcherBase.hpp
 *
 *  Created on: Feb 26, 2015
 *      Author: petr
 */

#ifndef MEDIT_MEDITBASE_EVET_DISPATCHERBASE_HPP_
#define MEDIT_MEDITBASE_EVET_DISPATCHERBASE_HPP_

#include <list>

#include "EventHandler.hpp"

using namespace std;

namespace Medit
{
namespace MeditBase
{
namespace Event
{

template<class E>
class AbstractDispatcher
{
public:

    /**
     * event type
     */
    typedef E Event;

    typedef EventHandler<E>  Handler;

    typedef Handler* HandlerPrt;

    typedef list<HandlerPrt> HandlerList;

protected:

    /**
     * type of event queue
     */
    typedef list<Event> EventList;

    /**
     * events in queue waiting to dispatch
     */
    EventList eventQueue;

public:

    AbstractDispatcher()
    {
    }

    virtual ~AbstractDispatcher()
    {
    }

    virtual void dispatchEvent(Event e) = 0;
};

} /* namespace Event */
} /* namespace MeditBase */
} /* namespace Medit */

#endif /* DISPATCHERBASE_HPP_ */
