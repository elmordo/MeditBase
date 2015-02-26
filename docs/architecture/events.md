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

* addListener - add specified listener into list
* removeListener - remove listener form listener list
* removeAllListeners - remove all listeners from list
* getListeners - return all listeners

Dispatcher is template class with one argument. This argument is type of event to dispatch.
When event is dispatched, it is handled by handlers on order how they came into list. Handling continues while there is some unhandled handler or propagation of event is stopped.

Event
=====

All events have to derive 

Handler classes
===============
