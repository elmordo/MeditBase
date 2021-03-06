/*
 * Event.hpp
 *
 *  Created on: Feb 26, 2015
 *      Author: petr
 */

#ifndef MEDIT_MEDIT_BASE_EVENT_EVENT_HPP_
#define MEDIT_MEDIT_BASE_EVENT_EVENT_HPP_

#include "../base.hpp"

namespace Medit
{
namespace MeditBase
{
namespace Event
{

class SHARED_EXPORT Event
{

    /**
     * auto destroy of event after propagation
     */
    bool autoDestroy;

    /**
     * set false when propagation should stop
     */
    bool propagate;

    /**
     * sender of event
     */
    void *sender;

public:

    /**
     * create uninitialized instance
     */
    Event();

    /**
     * create initialized instance
     * @pram sender sender of event
     */
    Event(void *sender);

    /**
     * copytor
     * @param other original instance
     */
    Event(const Event& other);

    /**
     * destroy instance
     */
    virtual ~Event();

    /**
     * return auto destroy value
     */
    inline bool getAutoDestroy() const
    {
        return autoDestroy;
    }

    /**
     * set new auto destroy value
     * @param val new value for switch
     */
    inline void setAutoDestroy(bool val)
    {
        autoDestroy = val;
    }

    /**
     * return propagate status
     */
    inline bool getPropagate() const
    {
        return propagate;
    }

    /**
     * set new propagate status
     * @param val new propagate status
     */
    inline void setPropagate(bool val)
    {
        propagate = val;
    }

    /**
     * return sender
     */
    virtual void *getSender() const
    {
        return sender;
    }

};

} /* namespace Event */
} /* namespace MeditBase */
} /* namespace Medit */

#endif /* MEDIT_MEDIT_BASE_EVENT_EVENT_HPP_ */
