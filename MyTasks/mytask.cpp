/*******************************************************************************
* Filename  	: mytask.cpp
* 
* Details   	: Implementation of Execute() of MyTask class
*
* Author        : Sergey Kolody
*******************************************************************************/
#include "mytask.hpp"
#include "../main.hpp"
#include "../Rtos/wrapper/thread.hpp"
#include "../CMSIS/stm32f411xe.h"
#include "../Rtos/wrapper/mailbox.hpp"

extern OsWrapper::MailBox<int, 10> queue;
void MyTask::Execute()
{ 
  while(true) 
  {
    using OsWrapper::operator""ms ;
    if (event.Wait() != 0)
    {
      GPIOC->ODR ^= (1 << 9);
      SleepUntil(500ms);
      int p = 0;
      queue.Get(p, 1000ms);
      p = p +10;
      queue.Get(p, 1000ms);
      p = p +10;
    }
  }
} ;