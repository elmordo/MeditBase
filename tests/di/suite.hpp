#ifndef MEDIT_MEDITBASE_TESTS_SUITE_HPP
#define MEDIT_MEDITBASE_TESTS_SUITE_HPP

#include <GTFO/TestSuite.hpp>

#include "TestServiceLocatorAware.hpp"
#include "TestServiceContainer.hpp"

namespace Medit
{
namespace MeditBase
{
namespace Tests
{

GTFO_TESTSUITE(DiSuite)

GTFO_REGISTER_TESTCASE(TestServiceLocatorAware);
GTFO_REGISTER_TESTCASE(TestServiceContainer);

GTFO_ENDTESTSUITE


}
}
}


#endif // MEDIT_MEDITBASE_TESTS_SUITE_HPP
