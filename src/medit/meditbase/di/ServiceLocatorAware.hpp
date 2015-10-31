#ifndef MEDIT_MEDITBASE_DI_SERVICELOCATORAWARE_HPP
#define MEDIT_MEDITBASE_DI_SERVICELOCATORAWARE_HPP

namespace Medit
{
namespace MeditBase
{
namespace DI
{

class ServiceLocator;


class ServiceLocatorAware
{

    ServiceLocator *serviceLocator;

public:

    ServiceLocatorAware();

    ServiceLocatorAware(ServiceLocator *locator);

    virtual ~ServiceLocatorAware();
};

} // namespace DI
} // namespace MeditBase
} // namespace Medit

#endif // MEDIT_MEDITBASE_DI_SERVICELOCATORAWARE_HPP
