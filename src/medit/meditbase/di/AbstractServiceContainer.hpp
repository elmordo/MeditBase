#ifndef MEDIT_MEDITBASE_DI_ABSTRACTSERVICECONTAINER_HPP
#define MEDIT_MEDITBASE_DI_ABSTRACTSERVICECONTAINER_HPP

#include "ServiceLocatorAware.hpp"
#include "../Allocator.hpp"


namespace Medit
{
namespace MeditBase
{
namespace DI
{

class AbstractServiceContainer : public ServiceLocatorAware
{
public:

    /**
     * @brief allocator used to destroying instances
     */
    typedef MeditBase::Allocator<ServiceLocatorAware> ServiceAllocator;

private:

    /**
     * @brief stored shared instance
     */
    ServiceLocatorAware *instance;

    /**
     * @brief true if instance should be shared
     */
    bool shared;

public:

    /**
     * @brief create empty container
     */
    AbstractServiceContainer();

    /**
     * @brief create instance initialized with service locator
     * @param locator service locator to set
     */
    AbstractServiceContainer(ServiceLocator *locator);

    /**
     * @brief copytor
     * @param original instance with original data
     */
    AbstractServiceContainer(const AbstractServiceContainer &original);

    /**
     * @brief destructor
     */
    virtual ~AbstractServiceContainer();

    /**
     * @brief create new instance of service
     * @return
     */
    virtual ServiceLocatorAware *createInstance() = 0;

    /**
     * @brief destroy and deallocate instance
     * @param instance to deallocate
     * @param n number of instances
     */
    virtual void destroyInstance(ServiceLocatorAware *instance, size_t n = 1);

    /**
     * @brief return shared instace or new isntance of service
     * @return
     */
    ServiceLocatorAware *getInstance();

    /**
     * @brief destroy stored instance
     */
    virtual void clearSharedInstance();

    /**
     * @brief return shared flag value
     * @return
     */
    bool getShared() const;

    /**
     * @brief set new shared flag value
     * @param value new flag value
     */
    void setShared(bool value);

    /**
     * @brief assing original instance to current one
     * @param original instance with original data
     * @return reference to self
     */
    AbstractServiceContainer &operator =(const AbstractServiceContainer &original);
};

} // namespace DI
} // namespace MeditBase
} // namespace Medit

#endif // MEDIT_MEDITBASE_DI_ABSTRACTSERVICECONTAINER_HPP
