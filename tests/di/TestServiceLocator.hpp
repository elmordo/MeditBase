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
    ServiceLocatorAware::Allocator alloc2;
    alloc2.destroyAndDeallocate(service);
}

GTFO_ENDCASE


}
}
}

#endif // TESTSERVICELOCATOR_HPP
