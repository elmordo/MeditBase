#ifndef MEDIT_MEDITBASE_TESTS_TESTSERVICELOCATORAWARE_HPP
#define MEDIT_MEDITBASE_TESTS_TESTSERVICELOCATORAWARE_HPP

#include <GTFO/TestCase.hpp>
#include <GTFO/asserts.hpp>

#include "../../src/medit/meditbase/di/ServiceLocator.hpp"
#include "../../src/medit/meditbase/di/ServiceLocatorAware.hpp"
#include "../../src/medit/meditbase/di/AbstractServiceContainer.hpp"


namespace Medit
{
namespace MeditBase
{
namespace Tests
{

using namespace Medit::MeditBase::DI;
using namespace Sopka::GTFO;


GTFO_TESTCASE(TestServiceLocatorAware)

GTFO_TESTLIST

    GTFO_REGISTER_TEST(testInit1)
    GTFO_REGISTER_TEST(testInit2)
    GTFO_REGISTER_TEST(testInit3)
    GTFO_REGISTER_TEST(testInit4)
    GTFO_REGISTER_TEST(testServiceLocator)
    GTFO_REGISTER_TEST(testAssign1)
    GTFO_REGISTER_TEST(testAssign2)

GTFO_ENDTESTLIST

    void testInit1()
    {
        ServiceLocatorAware aware;

        assertNull(aware.getServiceLocator());
    }

    void testInit2()
    {
        ServiceLocator locator;
        ServiceLocatorAware aware(&locator);

        assertEqual(&locator, aware.getServiceLocator());
    }

    /**
     * @brief test copytor of empty instance
     */
    void testInit3()
    {
        ServiceLocatorAware aware1;
        ServiceLocatorAware aware2(aware1);

        assertNull(aware2.getServiceLocator());
    }

    /**
     * @brief test copytor with set instance
     */
    void testInit4()
    {
        ServiceLocator locator;
        ServiceLocatorAware aware1(&locator);
        ServiceLocatorAware aware2(aware1);

        assertEqual(aware1.getServiceLocator(), aware2.getServiceLocator());
    }

    /**
     * @brief test service locator setter and getter
     */
    void testServiceLocator()
    {
        ServiceLocator locator;
        ServiceLocatorAware aware;
        aware.setServiceLocator(&locator);

        assertEqual(&locator, aware.getServiceLocator());
    }

    /**
     * @brief test assign of empty instance to initialized
     */
    void testAssign1()
    {
        ServiceLocator locator;
        ServiceLocatorAware aware1, aware2(&locator);

        aware2 = aware1;

        assertNull(aware1.getServiceLocator());
    }

    /**
     * @brief test assign not empty instance to empty
     */
    void testAssign2()
    {
        ServiceLocator locator;
        ServiceLocatorAware aware1, aware2(&locator);

        aware1 = aware2;

        assertEqual(aware1.getServiceLocator(), aware2.getServiceLocator());
    }

GTFO_ENDCASE


}
}
}

#endif // MEDIT_MEDITBASE_TESTS_TESTSERVICELOCATORAWARE_HPP
