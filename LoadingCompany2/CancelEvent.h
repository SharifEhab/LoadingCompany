#pragma once
#include"Event.h"
class CancelEvent : public Event
{
public:

    CancelEvent(int EventTimeHours = 1, int EventTimeDays = 1, int CargoID = 0);
    void Execute();
    ~CancelEvent();

    // CancelEvent();?
    //void IsLetter(char x);   ?
  //  void CancelIDNormal(Cargo c);   ?


};

