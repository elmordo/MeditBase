#include "base.hpp"

namespace Medit
{
namespace MeditBase
{


BaseException::BaseException() throw()
{
    line = 0;
    code = 1;
}

BaseException::BaseException(const std::string& msg, int code) throw()
{
    this->msg = msg;
    this->code = code;
}

BaseException::BaseException(const std::string& msg, int code, std::string file, int line, std::string fn) throw()
{
    this->msg = msg;
    this->code = code;
    this->file = file;
    this->line = line;
    this->fn = fn;
}

BaseException::BaseException(const BaseException& original) throw()
{
    msg = original.msg;
    code = original.code;
    file = original.file;
    line = original.line;
    ln = original.ln;
}

const char* BaseException::what() throw()
{
    return msg.c_str();
}

const std::string& BaseException::getMessage() throw()
{
    return msg;
}

int BaseException::getCode() const throw()
{
    return code;
}

int BaseException::getLine() const throw()
{
    return line;
}

const string& BaseException::getFile() const throw()
{
    return file;
}

const string& BaseException::getFn() const throw()
{
    return fn;
}

}
}