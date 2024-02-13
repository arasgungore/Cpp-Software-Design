#ifndef VISITOR_H
#define VISITOR_H

template< typename T >
class Visitor
{
 protected:
   virtual ~Visitor() = default;

 public:
   virtual void visit( T const& ) const = 0;
};

#endif