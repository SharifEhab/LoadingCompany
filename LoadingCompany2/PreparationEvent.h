#pragma once
#include"Event.h"
class PreparationEvent :public Event
{
private:
    int CargoCost;
    int LoadTime;
    int DeliveryDistance;
    char CargoType;
    Cargo* CargoReady;

public:
    PreparationEvent();
    PreparationEvent(char CargoT, int EventTimeHours, int EventTimeDays, int CargoID, int CargoDist, int LoadTimeHours, int Cost);

    void Execute(CompanyClass*Event_Executed);
//void Execute(LinkedQueue<Cargo> Lspecial, LinkedQueue<Cargo> Lnormal, LinkedQueue<Cargo> Lvip, char type, int lt, int dc, int dd, int td, int th); //missing add to "appropriate list"
    int GetCargoCost() const;
    int GetLoadTime() const;
    int GetDeliveryDistance() const;
    char GetCargoType() const;

    void SetCost(int Cost);
    void SetLoadtime(int Loadt);
    void SetDeliveryDist(int Distance);
    void SetCargotype(char t);

    ~PreparationEvent();

   
  

};

