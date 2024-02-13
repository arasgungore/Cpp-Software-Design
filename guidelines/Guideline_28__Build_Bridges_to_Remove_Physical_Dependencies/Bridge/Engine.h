#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
 public:
   virtual ~Engine() = default;
   virtual void start() = 0;
   virtual void stop() = 0;
   // ... more engine-specific functions

 private:
   // ...
};

#endif