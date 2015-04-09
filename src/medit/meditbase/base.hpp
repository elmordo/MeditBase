/*
 * base.hpp
 *
 *  Created on: 15. 3. 2015
 *      Author: petr
 */

#ifndef SRC_MEDIT_MEDITBASE_BASE_HPP_
#define SRC_MEDIT_MEDITBASE_BASE_HPP_

#include <exception>

/*
 * prefix for windows to inform compiler
 * about class export to public interface of DLL
 * TODO windows prefix
 */
#ifndef SHARED_EXPORT
#define SHARED_EXPORT
#endif

#ifndef MEDIT_CREATE_EXCEPTION
#define MEDIT_CREATE_EXCEPTION(BASE_EXCEPTION,NEW_EXCEPTION) class NEW_EXCEPTION : BASE_EXCEPTION {\
public:\
    NEW_EXCEPTION() throw() {}\
    virtual ~NEW_EXCEPTION() throw() {}\
}
#endif

namespace Medit
{
namespace MeditBase
{

MEDIT_CREATE_EXCEPTION(std::exception, BaseException);

namespace Event
{
MEDIT_CREATE_EXCEPTION(BaseException, EventException);
}

}
}

#endif /* SRC_MEDIT_MEDITBASE_BASE_HPP_ */
