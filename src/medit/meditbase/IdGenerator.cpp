#include "IdGenerator.hpp"

namespace Medit
{

namespace MeditBase
{

size_t currId = 0;

size_t generateUniqueId()
{
    return ++currId;
}

size_t getCurrentId()
{
    return currId;
}


} // namespace MeditBase
} // namespace Medit
