#ifndef TESTSERVICELOCATOR_HPP
#define TESTSERVICELOCATOR_HPP

#include <GTFO/TestCase.hpp>

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



GTFO_ENDTESTLIST

/**
 * @brief test constructor
 */
void testInit()
{
    ServiceLocator locator;

    assertEqual(locator.getRegisteredServices().size(), 0);
}

GTFO_ENDCASE


}
}
}

#endif // TESTSERVICELOCATOR_HPP
