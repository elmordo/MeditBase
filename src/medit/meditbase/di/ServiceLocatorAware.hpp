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

    /**
     * @brief stored service locator
     */
    ServiceLocator *serviceLocator;

public:

    /**
     * @brief create empty instance
     */
    ServiceLocatorAware();

    /**
     * @brief create instance with locator
     * @param locator service locator to set
     */
    ServiceLocatorAware(ServiceLocator *locator);

    /**
     * @brief destructor
     */
    virtual ~ServiceLocatorAware();

    /**
     * @brief return current service locator
     * @return current service locator
     */
    ServiceLocator *getServiceLocator() const;

    /**
     * @brief set new service locator
     * @param value locator to set
     */
    void setServiceLocator(ServiceLocator *value);

};

} // namespace DI
} // namespace MeditBase
} // namespace Medit

#endif // MEDIT_MEDITBASE_DI_SERVICELOCATORAWARE_HPP
