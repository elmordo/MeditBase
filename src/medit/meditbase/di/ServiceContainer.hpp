#ifndef MEDIT_MEDITBASE_DI_SERVICECONTAINER_HPP
#define MEDIT_MEDITBASE_DI_SERVICECONTAINER_HPP

#include "../Allocator.hpp"
#include "AbstractServiceContainer.hpp"


namespace Medit
{
namespace MeditBase
{
namespace DI
{

template<class T>
class ServiceContainer : public AbstractServiceContainer
{

public:

    typedef T Service;

    /**
     * @brief pointer to type
     */
    typedef Service* ServicePtr;

    /**
     * @brief create empty instance
     */
    ServiceContainer();

    /**
     * @brief initialize instance with service locator
     * @param locator service locator set
     */
    ServiceContainer(ServiceLocator *locator);

    /**
     * @brief copytor
     * @param original instance with original data
     */
    ServiceContainer(const ServiceContainer &original);

    /**
     * @brief destroy instance
     */
    virtual ~ServiceContainer();

    /**
     * @brief assign operator
     * @param original instance with original data
     * @return reference to self
     */
    ServiceContainer &operator =(const ServiceContainer &original);

    // AbstractServiceContainer interface
public:
    virtual ServiceLocatorAware *createInstance();
};


#define __TPL template<class T>
#define __PF ServiceContainer<T>

__TPL
__PF::ServiceContainer()
{
}

__TPL
__PF::ServiceContainer(ServiceLocator *locator) : AbstractServiceContainer(locator)
{
}

__TPL
__PF::ServiceContainer(const __PF &original) : AbstractServiceContainer(original)
{
}

__TPL
__PF::~ServiceContainer()
{
    clearSharedInstance();
}

__TPL
__PF &__PF::operator =(const __PF &original)
{
    AbstractServiceContainer::operator =(original);
    return *this;
}

__TPL
ServiceLocatorAware *__PF::createInstance()
{
    Allocator<T> alloc;
    T *service = alloc.allocateAndConstruct(1);
    service->setServiceLocator(getServiceLocator());

    return service;
}

#undef __TPL
#undef __PF


} // namespace DI
} // namespace MeditBase
} // namespace Medit

#endif // MEDIT_MEDITBASE_DI_SERVICECONTAINER_HPP
