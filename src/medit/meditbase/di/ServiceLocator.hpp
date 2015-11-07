#ifndef MEDIT_MEDITBASE_DI_SERVICELOCATOR_HPP
#define MEDIT_MEDITBASE_DI_SERVICELOCATOR_HPP

#include <map>

#include "../Allocator.hpp"
#include "../base.hpp"

using namespace std;


namespace Medit
{
namespace MeditBase
{
namespace DI
{

class AbstractServiceContainer;
class ServiceLocatorAware;


MEDIT_CREATE_EXCEPTION_E(BaseException, ServiceLocatorException)
    SERVICE_NOT_FOUND,
MEDIT_END_EXCEPTION_E;

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

    /**
     * @brief parent locator for hierarchy structure of locators
     */
    ServiceLocator *parent;

    /**
     * @brief return true if service is registered in current instance
     * @param id identifier of service
     * @return true if service is registered
     */
    bool isServiceRegistered(size_t id) const;

public:

    /**
     * @brief create empty service
     */
    ServiceLocator();

    /**
     * @brief initialize locator with parent
     * @param parent
     */
    ServiceLocator(ServiceLocator *parent);

    /**
     * @brief destroy instance
     */
    virtual ~ServiceLocator();

    /**
     * @brief return instance of service
     * @param id id of service
     * @return instance of service
     */
    ServiceLocatorAware *get(size_t id);

    /**
     * @brief get container of service
     * @param id identification number of container
     * @return pointer to container
     */
    AbstractServiceContainer *getServiceContainer(size_t id);

    /**
     * @brief get container of service
     * @param id identification number of container
     * @return constant pointer to container
     */
    const AbstractServiceContainer *getServiceContainer(size_t id) const;

    /**
     * @brief return all registered services
     * @return
     */
    ServiceMap getRegisteredServices() const;

    /**
     * @brief return true if service is registered
     * @param id identification number of service
     * @return true if service is registered
     */
    bool hasService(size_t id) const;

    /**
     * @brief register new service container into locator
     * @param id identification number of service
     * @param container pointer to container
     */
    void registerService(size_t id, AbstractServiceContainer *container);

    /**
     * @brief unregister service. If service does not exists, shit happened
     * @param id id of service
     */
    void unregisterService(size_t id);

    /**
     * @brief return current parent service locator
     * @return current parent
     */
    ServiceLocator *getParent() const;

    /**
     * @brief set new parent service locator
     * @param value new parent
     */
    void setParent(ServiceLocator *value);
};

} // namespace DI
} // namespace MeditBase
} // namespace Medit

#endif // MEDIT_MEDITBASE_DI_SERVICELOCATOR_HPP
