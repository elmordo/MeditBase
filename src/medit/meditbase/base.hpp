/*
 * base.hpp
 *
 *  Created on: 15. 3. 2015
 *      Author: petr
 */

#ifndef SRC_MEDIT_MEDITBASE_BASE_HPP_
#define SRC_MEDIT_MEDITBASE_BASE_HPP_

#include <exception>
#include <string>

/*
 * prefix for windows to inform compiler
 * about class export to public interface of DLL
 */
#ifndef SHARED_EXPORT
#define SHARED_EXPORT
#endif

#ifndef MEDIT_CREATE_EXCEPTION_E
#define MEDIT_CREATE_EXCEPTION_E(BASE_EXCEPTION,NEW_EXCEPTION) class NEW_EXCEPTION : public BASE_EXCEPTION {\
    public:\
        NEW_EXCEPTION() throw() {}\
        NEW_EXCEPTION(const std::string& msg, int code=1) throw() : BASE_EXCEPTION(msg, code) {}\
        NEW_EXCEPTION(const std::string& msg, int code, std::string file, int line, std::string fn) throw() : BASE_EXCEPTION(msg, code, file, line, fn) {}\
        NEW_EXCEPTION(const BaseException& original) throw() : BASE_EXCEPTION(original){} \
        virtual ~NEW_EXCEPTION() throw() {}\
    enum EXCEPTION_TYPE:int\
    {

#define MEDIT_END_EXCEPTION_E };\
}
#endif

#ifndef MEDIT_CREATE_EXCEPTION
#define MEDIT_CREATE_EXCEPTION(BASE_EXCEPTION,NEW_EXCEPTION) MEDIT_CREATE_EXCEPTION_E(BASE_EXCEPTION,NEW_EXCEPTION) MEDIT_END_EXCEPTION_E
#endif

#ifndef MEDIT_THROW_SIMPLE
#define MEDIT_THROW_SIMPLE(EXCEPTION) MEDIT_THROW("",1)
#endif

#ifndef MEDIT_THROW
#define MEDIT_THROW(EXCEPTION,MSG,CODE) throw EXCEPTION(MSG, CODE, __FILE__, __LINE__, __func__)
#endif


namespace Medit
{
namespace MeditBase
{

class BaseException : public std::exception
{

    int line;

    std::string file;

    std::string msg;

    int code;

    std::string fn;

public:

    /**
     * @brief create instance with empty message end code 1
     */
    BaseException() throw();

    /**
     * @brief create instance with message and code
     * @param msg error message
     * @param code error code
     */
    BaseException(const std::string& msg, int code=1) throw();

    /**
     * @brief create full specified instance
     * @param msg error message
     * @param code error code
     * @param file file name where exception was thrown
     * @param line line in file where exception was thrown
     * @param fn function or method name where exception was thrown 
     */
    BaseException(const std::string& msg, int code, std::string file, int line, std::string fn) throw();

    /**
     * @brief copytor
     * @param original instance with original data
     */
    BaseException(const BaseException& original) throw();

    /**
     * @brief actualy do nothing
     */
    virtual ~BaseException() throw();

    /**
     * @brief return error message like a C string
     * @return C-string error messaged
     */
    const char* what() throw();

    /**
     * @brief return message
     * @return error message
     */
    const std::string& getMessage() const throw();

    /**
     * @brief return number of line
     * @return line number
     */
    int getLine() const throw();

    /**
     * @brief return error code
     * @return error code
     */
    int getCode() const throw();

    /**
     * @brief return file name
     * @return file name
     */
    const std::string& getFile() const throw();

    /**
     * @brief return function or method name
     * @return function or method name
     */
    const std::string& getFn() const throw();

};

namespace Event
{
MEDIT_CREATE_EXCEPTION(BaseException, EventException);
}

}
}

#endif /* SRC_MEDIT_MEDITBASE_BASE_HPP_ */
