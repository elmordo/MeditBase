/*
 * test.cpp
 *
 *  Created on: 27. 2. 2015
 *      Author: petr
 */

#include "SingleDispatcher.hpp"
#include "Event.hpp"

#include <iostream>

using namespace std;
using namespace Medit::MeditBase::Event;

int main()
{
    SingleDispatcher<Event> dispatcher;

    Event *e = dispatcher.createEvent();
    dispatcher.dispatchEvent(e);

    cout << "prdel";
    return 0;
}

