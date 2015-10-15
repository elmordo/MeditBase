#ifndef MEDIT_MEDITBASE_IDGENERATOR_HPP
#define MEDIT_MEDITBASE_IDGENERATOR_HPP

#include <cstddef>

using namespace std;

namespace Medit
{
namespace MeditBase
{

/**
 * @brief generate new unique id
 * @return unique id
 */
size_t generateUniqueId();

/**
 * @brief return last returned id
 * @return last returned id
 */
size_t getCurrentId();

} // namespace MeditBase
} // namespace Medit

#endif // MEDIT_MEDITBASE_IDGENERATOR_HPP
