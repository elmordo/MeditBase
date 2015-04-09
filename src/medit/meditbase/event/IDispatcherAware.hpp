/*
 * IDispatcherAware.hpp
 *
 *  Created on: 30. 3. 2015
 *      Author: petr
 */

#ifndef SRC_MEDIT_MEDITBASE_EVENT_IDISPATCHERAWARE_HPP_
#define SRC_MEDIT_MEDITBASE_EVENT_IDISPATCHERAWARE_HPP_

#include "AbstractDispatcher.hpp"

namespace Medit
{
namespace MeditBase
{
namespace Event
{

MEDIT_CREATE_EXCEPTION(DispatcherException, DispatcherIndexOutOfRangeException);

template<class E>
class IDispatcherAware
{

public:

    virtual ~IDispatcherAware()
    {
    }

    /**
     * return reference to dispatcher
     * @param index index or id of dispatcher
     */
    virtual AbstractDispatcher<E>& getDispatcher(int index)
            throw (DispatcherIndexOutOfRangeException) = 0;

    /**
     * return constant reference to dispatcher by given index
     * @param index index or id of dispatcher
     */
    virtual const AbstractDispatcher<E>& getDispatcher(int index) const
            throw (DispatcherIndexOutOfRangeException) = 0;

};

}
}
}

#endif /* SRC_MEDIT_MEDITBASE_EVENT_IDISPATCHERAWARE_HPP_ */
