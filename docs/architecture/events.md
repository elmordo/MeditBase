Events
======

Comunication between parts of system is provided by event system.
Event system has parts:

1. event dispatcher
2. event
3. handler class

Event dispatcher
================

Dispatchers are responsible for propagating events to target listeners. Listeners are managed by methods:

* addHandler - add specified listener into list
* removeHandler - remove listener form listener list
* removeAllHandlers - remove all listeners from list
* getHandlers - return all listeners

Dispatcher is template class with one argument. This argument is type of event to dispatch.
When event is dispatched, it is handled by handlers on order how they came into list. Handling continues while there is some unhandled handler or propagation of event is stopped.

Event
=====

All events have to derive from basic class Event. This class contains some common information about instance:

* sender - instance who created event
* propagate - switch if event should be propagated

When propagate switch is set to false, propagation of event to handlers is stopped. 

Handler classes
===============

Base handler classes are template with argument defining type of event to handle. These classes are pure virtual and have role as interfaces. Interfaces are defined in dispatcher class concretization and direvied by real handlers, implementing abstract handling method.
