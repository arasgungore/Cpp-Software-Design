#ifndef DRAW_STRATEGY_H
#define DRAW_STRATEGY_H

template< typename T >
class DrawStrategy
{
 public:
   virtual ~DrawStrategy() = default;
   virtual void draw( T const& ) const = 0;
};

#endif