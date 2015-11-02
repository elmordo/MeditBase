#ifndef MEDIT_MEDITBASE_TESTS_TESTSERVICECONTAINER_HPP
#define MEDIT_MEDITBASE_TESTS_TESTSERVICECONTAINER_HPP

#include <GTFO/TestCase.hpp>
#include <GTFO/asserts.hpp>

#include "../../src/medit/meditbase/di/ServiceContainer.hpp"

using namespace Sopka::GTFO;
using namespace Medit::MeditBase::DI;


namespace Medit
{
namespace MeditBase
{
namespace Tests
{

class MockService : public ServiceLocatorAware
{

public:

    static int destroyCounter;

    static int createCounter;

    MockService() { ++createCounter; }

    virtual ~MockService() { ++destroyCounter; }

};

int MockService::createCounter = 0;
int MockService::destroyCounter = 0;

typedef ServiceContainer<MockService> Container;

GTFO_TESTCASE(TestServiceContainer)

GTFO_TESTLIST

    GTFO_REGISTER_TEST(testInit1)
    GTFO_REGISTER_TEST(testInit2)
    GTFO_REGISTER_TEST(testInit3)
    GTFO_REGISTER_TEST(testInit4)

    GTFO_REGISTER_TEST(testCreateInstance1)
    GTFO_REGISTER_TEST(testCreateInstance2)

    GTFO_REGISTER_TEST(testShared)

    GTFO_REGISTER_TEST(testGetInstance1)
    GTFO_REGISTER_TEST(testGetInstance2)

GTFO_ENDTESTLIST

    void setUp()
    {
        MockService::createCounter = 0;
        MockService::destroyCounter = 0;
    }

    /**
     * @brief test empty constructor
     */
    void testInit1()
    {
        Container c;

        assertNull(c.getServiceLocator());
    }

    /**
     * @brief test constructor with service locator
     */
    void testInit2()
    {
        ServiceLocator locator;
        Container c(&locator);

        assertEqual(&locator, c.getServiceLocator());
    }

    /**
     * @brief test copytor of empty instance
     */
    void testInit3()
    {
        Container original;
        Container copy(original);

        assertNull(original.getServiceLocator());
        assertEqual(original.getServiceLocator(), copy.getServiceLocator());
    }

    /**
     * @brief test copytor with instance with locator
     */
    void testInit4()
    {
        ServiceLocator locator;
        Container original(&locator);
        Container copy(original);

        assertEqual(&locator, original.getServiceLocator());
        assertEqual(original.getServiceLocator(), copy.getServiceLocator());
    }

    /**
     * @brief test createInstance method (each call has to return different instance)
     *      container is not mark as shared
     */
    void testCreateInstance1()
    {
        Container c;

        ServiceLocatorAware *service1 = c.createInstance(),
                *service2 = c.createInstance();

        assertNotEqual(service1, service2, "Instances are equal");
        assertNull(service1->getServiceLocator());
        assertNull(service2->getServiceLocator());

        c.destroyInstance(service1);
        c.destroyInstance(service2);

        assertEqual(MockService::createCounter, 2, "Invalid create counter");
        assertEqual(MockService::destroyCounter, 2, "Invalid destroy counter");
    }

    /**
     * @brief test createInstance method (each call has to return different instance)
     *      container is not mark as shared
     */
    void testCreateInstance2()
    {
        ServiceLocator locator;
        Container c(&locator);

        ServiceLocatorAware *service1 = c.createInstance(),
                *service2 = c.createInstance();

        assertNotEqual(service1, service2, "Instances are equal");
        assertEqual(service1->getServiceLocator(), &locator);
        assertEqual(service2->getServiceLocator(), &locator);

        c.destroyInstance(service1);
        c.destroyInstance(service2);

        assertEqual(MockService::createCounter, 2, "Invalid create counter");
        assertEqual(MockService::destroyCounter, 2, "Invalid destroy counter");
    }

    /**
     * @brief test shared flag setter and getter
     */
    void testShared()
    {
        Container c;

        bool oldVal = c.getShared();
        c.setShared(!oldVal);

        assertNotEqual(oldVal, c.getShared());
    }

    /**
     * @brief get instance on not shared container
     */
    void testGetInstance1()
    {
        Container c;
        ServiceLocatorAware *service1 = c.getInstance();
        ServiceLocatorAware *service2 = c.getInstance();

        assertNotEqual(service1, service2);

        c.destroyInstance(service1);
        c.destroyInstance(service2);
    }

    /**
     * @brief get instance on not shared container
     */
    void testGetInstance2()
    {
        Container c;

        c.setShared(true);

        ServiceLocatorAware *service1 = c.getInstance();
        ServiceLocatorAware *service2 = c.getInstance();

        assertEqual(service1, service2);
    }

GTFO_ENDCASE


}
}
}


#endif
