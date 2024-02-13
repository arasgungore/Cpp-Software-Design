#ifndef OBSERVER_H
#define OBSERVER_H

template< typename Subject, typename StateTag >
class Observer
{
 public:
   virtual ~Observer() = default;

   virtual void update( Subject const& subject, StateTag property ) = 0;
};

#endif