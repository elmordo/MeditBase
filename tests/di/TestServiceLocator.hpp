#ifndef TESTSERVICELOCATOR_HPP
#define TESTSERVICELOCATOR_HPP

#include <GTFO/TestCase.hpp>

#include "TestServiceContainer.hpp"
#include "../../src/medit/meditbase/di/ServiceLocator.hpp"
#include "../../src/medit/meditbase/di/ServiceLocatorAware.hpp"
#include "../../src/medit/meditbase/di/ServiceContainer.hpp"

using namespace Sopka::GTFO;
using namespace Medit::MeditBase::DI;


namespace Medit
{
namespace MeditBase
{
namespace Tests
{


GTFO_TESTCASE(TestServiceLocator)

GTFO_TESTLIST

GTFO_REGISTER_TEST(testInit1);
GTFO_REGISTER_TEST(testInit2);

GTFO_REGISTER_TEST(testParent1);
GTFO_REGISTER_TEST(testParent2);

GTFO_REGISTER_TEST(testGet1);
GTFO_REGISTER_TEST(testGet2);
GTFO_REGISTER_TEST(testGet3);
GTFO_REGISTER_TEST(testGet4);

GTFO_REGISTER_TEST(testGetServiceContainer1);
GTFO_REGISTER_TEST(testGetServiceContainer2);
GTFO_REGISTER_TEST(testGetServiceContainer3);
GTFO_REGISTER_TEST(testGetServiceContainer4);

GTFO_REGISTER_TEST(testGetServiceContainerC1);
GTFO_REGISTER_TEST(testGetServiceContainerC2);
GTFO_REGISTER_TEST(testGetServiceContainerC3);
GTFO_REGISTER_TEST(testGetServiceContainerC4);

GTFO_REGISTER_TEST(testGetRegisteredServices1);
GTFO_REGISTER_TEST(testGetRegisteredServices2);

GTFO_ENDTESTLIST

/**
 * @brief test constructor
 */
void testInit1()
{
    ServiceLocator locator;

    assertEqual(locator.getRegisteredServices().size(), 0);
    assertEqual<ServiceLocator*, ServiceLocator*>(locator.getParent(), 0x0);
}

/**
 * @brief test constructor with parent
 */
void testInit2()
{
    ServiceLocator parent;
    ServiceLocator child(&parent);

    assertEqual(child.getRegisteredServices().size(), 0);
    assertEqual(child.getParent(), &parent);
}

void testParent1()
{
    ServiceLocator parent;
    ServiceLocator child(&parent);

    child.setParent(0x0);

    assertEqual(child.getParent(), (ServiceLocator*)0);
}

void testParent2()
{
    ServiceLocator parent;
    ServiceLocator child;

    child.setParent(&parent);

    assertEqual(child.getParent(), &parent);
}

/**
 * @brief tries to get unexisting service
 */
void testGet1()
{
    ServiceLocator locator;

    try
    {
        locator.get(1);
    }
    catch (ServiceLocatorException &e)
    {
        return;
    }

    fail("No exception raised");
}

/**
 * @brief try to get existing service
 */
void testGet2()
{
    ServiceLocator locator;
    ServiceContainer<MockService>::Allocator alloc;
    ServiceContainer<MockService> *container = alloc.allocateAndConstruct(1);

    locator.registerService(1, container);

    ServiceLocatorAware *service = locator.get(1);

    // test instance
    assertInstanceOf<MockService>(service);

    ServiceLocatorAware::Allocator alloc2;
    alloc2.destroyAndDeallocate(service);
}

/**
 * @brief try to get service from parent container (where does not exist)
 */
void testGet3()
{
    ServiceLocator parent;
    ServiceLocator child(&parent);

    try
    {
        child.get(1);
    }
    catch (ServiceLocatorException &)
    {
        return;
    }

    fail("No exception raised");
}

/**
 * @brief try to get existing service from parent locator
 */
void testGet4()
{
    ServiceLocator parent;
    ServiceLocator child(&parent);

    ServiceContainer<MockService>::Allocator alloc;
    ServiceContainer<MockService> *container = alloc.allocateAndConstruct(1);

    parent.registerService(1, container);

    ServiceLocatorAware *service = 0x0;

    try
    {
        service = child.get(1);
    }
    catch (ServiceLocatorException &)
    {
        fail("Service not found");
    }

    assertInstanceOf<MockService>(service, "Invalid service class");

    // deallocate service
    ServiceLocatorAware::Allocator allocSer;
    allocSer.destroyAndDeallocate(service);
}

/**
 * @brief try to get not existing service container
 */
void testGetServiceContainer1()
{
    ServiceLocator locator;
    AbstractServiceContainer *container = locator.getServiceContainer(1);

    assertNull(container, "Container has to be NULL");
}

/**
 * @brief try to get existing service container
 */
void testGetServiceContainer2()
{
    ServiceLocator locator;
    typedef ServiceContainer<MockService> MockContainer;

    MockContainer::Allocator alloc;
    MockContainer *container = alloc.allocateAndConstruct(1);

    locator.registerService(1, container);
    AbstractServiceContainer *g = locator.getServiceContainer(1);

    assertEqual(g, container, "Invalid container given.");
}

/**
 * @brief try to get not existing service container from parent locator
 */
void testGetServiceContainer3()
{
    ServiceLocator parent;
    ServiceLocator locator(&parent);
    AbstractServiceContainer *container = locator.getServiceContainer(1);

    assertNull(container, "Container has to be NULL");
}

/**
 * @brief try to get existing service container from parent locator
 */
void testGetServiceContainer4()
{
    ServiceLocator parent;
    ServiceLocator locator(&parent);
    typedef ServiceContainer<MockService> MockContainer;

    MockContainer::Allocator alloc;
    MockContainer *container = alloc.allocateAndConstruct(1);

    parent.registerService(1, container);
    AbstractServiceContainer *g = locator.getServiceContainer(1);

    assertEqual(g, container, "Invalid container given.");
}

/**
 * @brief try to get not existing service container (const version)
 */
void testGetServiceContainerC1()
{
    ServiceLocator locator;
    const ServiceLocator &cLocator = locator;

    const AbstractServiceContainer *container = cLocator.getServiceContainer(1);

    assertNull(container, "Container has to be NULL");
}

/**
 * @brief try to get existing service container (const version)
 */
void testGetServiceContainerC2()
{
    ServiceLocator locator;
    const ServiceLocator &cLocator = locator;

    typedef ServiceContainer<MockService> MockContainer;

    MockContainer::Allocator alloc;
    MockContainer *container = alloc.allocateAndConstruct(1);

    locator.registerService(1, container);
    const AbstractServiceContainer *g = cLocator.getServiceContainer(1);

    assertEqual(g, container, "Invalid container given.");
}

/**
 * @brief try to get not existing service container from parent locator (const version)
 */
void testGetServiceContainerC3()
{
    ServiceLocator parent;
    ServiceLocator locator(&parent);

    const ServiceLocator &cLocator = locator;
    const AbstractServiceContainer *container = cLocator.getServiceContainer(1);

    assertNull(container, "Container has to be NULL");
}

/**
 * @brief try to get existing service container from parent locator (const version)
 */
void testGetServiceContainerC4()
{
    ServiceLocator parent;
    ServiceLocator locator(&parent);
    const ServiceLocator &cLocator = locator;

    typedef ServiceContainer<MockService> MockContainer;

    MockContainer::Allocator alloc;
    MockContainer *container = alloc.allocateAndConstruct(1);

    parent.registerService(1, container);
    const AbstractServiceContainer *g = cLocator.getServiceContainer(1);

    assertEqual(g, container, "Invalid container given.");
}

/**
 * @brief try to get registered services on empty instance
 */
void testGetRegisteredServices1()
{
    ServiceLocator locator;
    ServiceLocator::ServiceMap services = locator.getRegisteredServices();

    assertEqual(services.size(), 0);
}

/**
 * @brief try to get registered services on not empty instance
 */
void testGetRegisteredServices2()
{
    ServiceLocator locator;

    typedef ServiceContainer<MockService> MockContainer;
    MockContainer::Allocator alloc;
    MockContainer *container = alloc.allocateAndConstruct(1);
    locator.registerService(1, container);

    ServiceLocator::ServiceMap services = locator.getRegisteredServices();

    assertEqual(services.size(), 1);
}

GTFO_ENDCASE


}
}
}

#endif // TESTSERVICELOCATOR_HPP
