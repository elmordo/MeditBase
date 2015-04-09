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
#include "Event.hpp"
#include "../base.hpp"

using namespace std;

namespace Medit
{
namespace MeditBase
{
namespace Event
{

MEDIT_CREATE_EXCEPTION(Medit::MeditBase::BaseException, DispatcherException);

template<class E>
class AbstractDispatcher
{
public:

    /**
     * event type
     */
    typedef E Event;
    
    typedef Event* EventPrt;

    /**
     * base class of all handlers that can be registered in dispatcher
     */
    typedef EventHandler<E>  Handler;

    /**
     * handler pointer
     */
    typedef Handler* HandlerPrt;

    /**
     * list of handlers
     */
    typedef list<HandlerPrt> HandlerList;

protected:

    /**
     * type of event queue
     */
    typedef list<EventPrt> EventList;

    /**
     * events in queue waiting to dispatch
     */
    EventList eventQueue;

    /**
     * set of handlers registered in dispatcher
     */
    HandlerList handlers;

public:

    /**
     * create instance
     */
    AbstractDispatcher()
    {

    }

    /**
     * destroy instance
     */
    virtual ~AbstractDispatcher()
    {
    }

    /**
     * add event handler
     * @param handler event handler to add
     */
    virtual void addHandler(HandlerPrt handler) = 0;

    /**
     * dispatch event
     */
    virtual void dispatchEvent(Event* e) = 0;

    /**
     * return set of handlers registered in instance
     */
    virtual HandlerList getHandlers() = 0;

    /**
     * remove handler from instance
     * @param handler handler to remove
     */
    virtual void removeHandler(HandlerPrt handler) = 0;

    /**
     * remove all handlers from instance
     */
    virtual void removeAllHandlers() = 0;

    /**
     * create new event
     * @return new event
     */
    static E *createEvent()
    {
        return new Event();
    }

    /**
     * destroy existing event
     * @param event event to destroy
     */
    static void destroyEvent(E *event)
    {
        delete event;
    }

};

} /* namespace Event */
} /* namespace MeditBase */
} /* namespace Medit */

#endif /* DISPATCHERBASE_HPP_ */
