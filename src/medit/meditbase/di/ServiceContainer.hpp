#ifndef MEDIT_MEDITBASE_DI_SERVICECONTAINER_HPP
#define MEDIT_MEDITBASE_DI_SERVICECONTAINER_HPP

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
__PF::__PF()
{
}

__TPL
__PF::__PF(ServiceLocator *locator) : AbstractServiceContainer(locator)
{
}

__TPL
__PF::__PF(const __PF &original) : AbstractServiceContainer(original)
{
}

__TPL
__PF::~__PF()
{
}

__TPL
__PF &__PF::operator =(const __PF &original)
{
    AbstractServiceContainer::operator =(orignal);
    return *this;
}

__TPL
__PF:: __PF::createService()

#undef __TPL
#undef __PF


} // namespace DI
} // namespace MeditBase
} // namespace Medit

#endif // MEDIT_MEDITBASE_DI_SERVICECONTAINER_HPP
