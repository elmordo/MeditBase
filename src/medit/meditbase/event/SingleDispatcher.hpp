/*
 * SingleDispatcher.hpp
 *
 *  Created on: 27. 2. 2015
 *      Author: petr
 */

#ifndef MEDIT_MEDITBASE_EVENT_SINGLEDISPATCHER_HPP_
#define MEDIT_MEDITBASE_EVENT_SINGLEDISPATCHER_HPP_

#include <list>
#include "AbstractDispatcher.hpp"
#include "Event.hpp"

namespace Medit
{
namespace MeditBase
{
namespace Event
{

template<class E>
class SingleDispatcher: public AbstractDispatcher<E>
{

    bool inDispatchProcess;
    
    void propagateEvent(E *event)
    {
        typename AbstractDispatcher<E>::HandlerList::iterator pos = this->handlers.begin(),
                end = this->handlers.end();
        
        while (pos != end && event->getPropagate())
        {
            (*pos)->handle(event);
        }
    }

    void processQueue()
    {
        if (!inDispatchProcess) 
        {
            while (this->eventQueue.size())
            {
                E *event = this->eventQueue.front();
                propagateEvent(event);

                // pop event from list
                this->eventQueue.pop_front();

                // destroy event if switch is on
                if (event->getAutoDestroy())
                    AbstractDispatcher<E>::destroyEvent(event);
            }
        }
    }
    
public:

    /**
     * create instance
     */
    SingleDispatcher()
    {
        inDispatchProcess = false;
    }

    /**
     * destroy instance
     */
    virtual ~SingleDispatcher()
    {
    }

    /**
     * add event handler
     * @param handler event handler to add
     */
    virtual void addHandler(typename AbstractDispatcher<E>::HandlerPrt handler)
    {
        this->handlers.push_back(handler);
    }

    /**
     * dispatch event
     */
    virtual void dispatchEvent(typename AbstractDispatcher<E>::Event *e)
    {
        this->eventQueue.push_back(e);

        processQueue();
    }

    /**
     * return set of handlers registered in instance
     */
    virtual typename AbstractDispatcher<E>::HandlerList getHandlers()
    {
        return this->handlers;
    }

    /**
     * remove handler from instance
     * @param handler handler to remove
     */
    virtual void removeHandler(
            typename AbstractDispatcher<E>::HandlerPrt handler)
    {
        // remove handler from list
        this->handlers.remove(handler);
    }

    /**
     * remove all handlers from instance
     */
    virtual void removeAllHandlers()
    {
        this->handlers.clear();
    }
};

} /* namespace Event */
} /* namespace MeditBase */
} /* namespace Medit */

#endif /* MEDIT_MEDITBASE_EVENT_SINGLEDISPATCHER_HPP_ */
