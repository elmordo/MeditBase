#ifndef MEDIT_MEDITBASE_TESTS_TESTSERVICELOCATORAWARE_HPP
#define MEDIT_MEDITBASE_TESTS_TESTSERVICELOCATORAWARE_HPP

#include <GTFO/TestCase.hpp>
#include <GTFO/asserts.hpp>

#include "../../src/medit/meditbase/di/ServiceLocatorAware.hpp"

namespace Medit
{
namespace MeditBase
{
namespace Tests
{

using namespace Medit::MeditBase::DI;


GTFO_TESTCASE(TestServiceLocatorAware)

GTFO_TESTLIST

    GTFO_REGISTER_TEST(testInit1)
    GTFO_REGISTER_TEST(testInit2)

GTFO_ENDTESTLIST

    void testInit1()
    {
        ServiceLocatorAware aware;

        assertIsNull(aware.getServiceLocator());
    }

    void testInit2()
    {
        ServiceLocator locator;
        ServiceLocatorAware aware(&locator);

        assertEqual(&locator, aware.getServiceLocator());
    }

GTFO_ENDCASE


}
}
}

#endif // MEDIT_MEDITBASE_TESTS_TESTSERVICELOCATORAWARE_HPP
