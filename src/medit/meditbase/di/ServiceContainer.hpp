#ifndef MEDIT_MEDITBASE_DI_SERVICECONTAINER_HPP
#define MEDIT_MEDITBASE_DI_SERVICECONTAINER_HPP

#include "ServiceLocatorAware.hpp"


namespace Medit
{
namespace MeditBase
{
namespace DI
{

class ServiceContainer : public ServiceLocatorAware
{

    ServiceLocatorAware *instance;

    bool shared;

public:
    ServiceContainer();

    ServiceContainer(ServiceLocator *locator);

};

} // namespace DI
} // namespace MeditBase
} // namespace Medit

#endif // MEDIT_MEDITBASE_DI_SERVICECONTAINER_HPP
