#include "ServiceLocator.hpp"
#include "AbstractServiceContainer.hpp"
#include "ServiceLocatorAware.hpp"

namespace Medit
{
namespace MeditBase
{
namespace DI
{

ServiceLocator::ServiceLocator()
{
}

ServiceLocator::~ServiceLocator()
{
    // destroy all services
    Allocator<AbstractServiceContainer> alloc;

    for (ServiceMap::value_type item : services)
    {
        alloc.destroyAndDeallocate(item.second);
    }
}

ServiceLocatorAware *ServiceLocator::get(size_t id)
{
    if (!hasService(id))
    {
        MEDIT_THROW(ServiceLocatorException, "Service was not found",
                    ServiceLocatorException::SERVICE_NOT_FOUND);
    }

    return services[id]->getInstance();
}

AbstractServiceContainer *ServiceLocator::getServiceContainer(size_t id)
{
    if (!hasService(id))
    {
        return 0x0;
    }

    return services[id];
}

const AbstractServiceContainer *ServiceLocator::getServiceContainer(size_t id) const
{
    if (!hasService(id))
    {
        return 0x0;
    }

    return services.find(id)->second;
}

bool ServiceLocator::hasService(size_t id) const
{
    return services.find(id) != services.end();
}

void ServiceLocator::registerService(size_t id, AbstractServiceContainer *container)
{
    unregisterService(id);

    services[id] = container;
}

void ServiceLocator::unregisterService(size_t id)
{
    ServiceMap::iterator pos = services.find(id);

    if (pos != services.end())
    {
        services.erase(pos);
    }
}

ServiceLocator::ServiceMap ServiceLocator::getRegisteredServices() const
{
    return services;
}

} // namespace DI
}

// namespace MeditBase
} // namespace Medit
