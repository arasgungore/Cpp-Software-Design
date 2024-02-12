#include "Calculator.h"
#include <utility>

void Calculator::compute( std::unique_ptr<CalculatorCommand> command )
{
   current_ = command->execute( current_ );
   stack_.push( std::move(command) );
}

void Calculator::undoLast()
{
   if( stack_.empty() ) return;

   auto command = std::move(stack_.top());
   stack_.pop();

   current_ = command->undo(current_);
}

int Calculator::result() const
{
   return current_;
}

void Calculator::clear()
{
   current_ = 0;
   CommandStack{}.swap( stack_ );  // Clearing the stack
}