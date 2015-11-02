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

AbstractServiceContainer &AbstractServiceContainer::operator =(const AbstractServiceContainer &original)
{
    clearSharedInstance();
    shared = original.shared;
    setServiceLocator(original.getServiceLocator());

    return *this;
}
AbstractServiceContainer::AbstractServiceContainer()
{
    shared = false;
    instance = 0x0;
}

AbstractServiceContainer::AbstractServiceContainer(ServiceLocator *locator) : ServiceLocatorAware(locator)
{
    shared = false;
    instance = 0x0;
}

AbstractServiceContainer::AbstractServiceContainer(const AbstractServiceContainer &original) : ServiceLocatorAware(original)
{
    instance = 0;
    shared = original.shared;
}

AbstractServiceContainer::~AbstractServiceContainer()
{
    clearSharedInstance();
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
        destroyInstance(instance, 1);
        instance = 0x0;
    }
}

} // namespace DI
} // namespace MeditBase
} // namespace Medit
