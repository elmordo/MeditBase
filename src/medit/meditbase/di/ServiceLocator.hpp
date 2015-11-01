#ifndef MEDIT_MEDITBASE_DI_SERVICELOCATOR_HPP
#define MEDIT_MEDITBASE_DI_SERVICELOCATOR_HPP

#include <map>

using namespace std;


namespace Medit
{
namespace MeditBase
{
namespace DI
{

class AbstractServiceContainer;

class ServiceLocator
{
public:

    /**
     * @brief container for services
     */
    typedef map<size_t, AbstractServiceContainer*> ServiceMap;

private:

    /**
     * @brief set of registered services
     */
    ServiceMap services;

public:

    /**
     * @brief create empty service
     */
    ServiceLocator();

    /**
     * @brief copytor
     * @param original instance with original data
     */
    ServiceLocator(const ServiceLocator &original);

    /**
     * @brief destroy instance
     */
    virtual ~ServiceLocator();
};

} // namespace DI
} // namespace MeditBase
} // namespace Medit

#endif // MEDIT_MEDITBASE_DI_SERVICELOCATOR_HPP
