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

    /**
     * event handler type
     */
    typedef EventHandler<E> Handler;

    /**
     * handler pointer
     */
    typedef Handler* HandlerPrt;

    /**
     * list of handler pointers
     */
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

    /**
     * list of registered handlers
     */
    HandlerList handlers;

public:

    AbstractDispatcher()
    {
    }

    virtual ~AbstractDispatcher()
    {
    }

    /**
     * add handler into instance
     * @param handler pointer on handler instance to add
     */
    virtual void addHandler(HandlerPrt hander) = 0;

    /**
     * dispatch event
     * @param e event to dispatch
     */
    virtual void dispatchEvent(Event& e) = 0;

    /**
     * get all handlers in list
     */
    virtual HandlerList getHandlers() const = 0;

    /**
     * remove handler from instance
     * @param handler pointer on handler to remove
     */
    virtual void removeHandler(HandlerPrt handler) = 0;

    /**
     * remove all handlers from list
     */
    virtual void removeAllHandlers() = 0;
};

} /* namespace Event */
} /* namespace MeditBase */
} /* namespace Medit */

#endif /* DISPATCHERBASE_HPP_ */
