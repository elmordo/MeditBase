#include "AbstractServiceContainer.hpp"

namespace Medit
{
namespace MeditBase
{
namespace DI
{


bool AbstractServiceContainer::getShared() const
{
    return shared;
}

void AbstractServiceContainer::setShared(bool value)
{
    shared = value;
}
AbstractServiceContainer::AbstractServiceContainer()
{
}

void AbstractServiceContainer::destroyInstance(ServiceLocatorAware *instance, size_t n)
{
    ServiceAllocator alloc;
    alloc.destroyAndDeallocate(instance, n);
}

ServiceLocatorAware *AbstractServiceContainer::getInstance()
{
    // return value
    ServiceLocatorAware *retVal;

    if (shared)
    {
        // instance is shared - return shared instance
        if (instance == 0x0)
        {
            // instance is not created yet
            instance = createInstance();
        }

        // set instance to ret val
        retVal = instance;
    }
    else
    {
        // create new instance
        retVal = createInstance();
    }

    // return value
    return retVal;
}

void AbstractServiceContainer::clearSharedInstance()
{
    if (instance)
    {
        Allocator<ServiceLocatorAware> alloc;
        alloc.destroyAndDeallocate(instance, 1);
        instance = 0x0;
    }
}

} // namespace DI
} // namespace MeditBase
} // namespace Medit
