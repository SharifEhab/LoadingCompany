#include "Truck.h"
#include"PriQ.h"
#include "Cargo.h"
Truck::Truck()
{
	TruckID++;
	setTruckType('N');
	setTruckCapacity(0);
	setTruckMaintenanceTime(0);
	setTruckSpeed(0);
	SetNoOfJourneys(0);
	TruckID = 0;
	DeliveredCargosByTruck = 0;
	setTruckMoveTime(0, 0);
	TruckTotalActiveTimeH=0;
	TruckTotalActiveTimeD=0;
	TruckUtilization = 0;
	TruckDeliveryIntervalH = 0;
	TruckDeliveryIntervalD = 0;
}

Truck::Truck(char type, int speed, int capacity, int noOfJourneys, int CheckupTime, int id)
{
	setTruckType(type);
	setTruckSpeed(speed);
	setTruckCapacity(capacity);
	SetNoOfJourneys(noOfJourneys);
	setTruckMaintenanceTime(CheckupTime);
	SetTruckID(id);
}

void Truck::setTruckType(char type)
{
	TruckType = type;
}

void Truck::setTruckCapacity(int capacity)
{
	TruckCapacity = capacity;
}

void Truck::setTruckMaintenanceTime(int time)
{
	TruckMaintenanceTime = time;
}

void Truck::setTruckSpeed(int speed)
{
	TruckSpeed = speed;
}

void Truck::SetNoOfJourneys(int number)
{
	TruckNoOfJourneys = number;
}
void Truck::SetTruckID(int id)
{
	TruckID = id;
}
void Truck::getDeliveredCargosByTruck()
{
	DeliveredCargosByTruck= TruckCapacity* TruckNoOfJourneys;
}

void Truck::incrementTruckTotalActiveTime()
{
	TruckTotalActiveTimeH++;
	while (TruckTotalActiveTimeH > 23)
	{
		TruckTotalActiveTimeH = TruckTotalActiveTimeH - 23;
		TruckTotalActiveTimeD++;
	}
}

void Truck::AddJourney()
{
	TruckNoOfJourneys++;
}

double Truck::CalculateTruckUtilization() //NEEDED TO BE FIXED ,(CALLED  AT THE END OF SIMULATION)
{
	TruckUtilization = getNoDeliveredCargosByTruck() / (DeliveredCargosByTruck * TruckNoOfJourneys) * TruckTotalActiveTimeH + (TruckTotalActiveTimeD * 24);
	return 0;
}

void Truck::setTruckMoveTime(int h, int d)
{
	TruckMoveTimeHour = h;
	TruckMoveTimeDay = d;
}

char Truck::getTruckType() const
{
	return TruckType;
}

int Truck::getTruckCapacity() const
{
	return TruckCapacity;
}

int Truck::getTruckMaintenanceTime() const
{
	return TruckMaintenanceTime;
}

int Truck::getTruckSpeed() const
{
	return TruckSpeed;
}

int Truck::getTruckDeliveryIntervalHours() //------------------->NEEDS CONTINUTATION
{
	Cargo* c;
	PriQ <Cargo*> LoadingCargos = getLoadedCargosInTruck();
	c=LoadingCargos.getLastNode();
	int comeD;
	int comeH;
	getTimeToComeBack(comeH, comeD);
	int FurthestCargoDeliveryDistance=c->getDeliveringDistance();
	TruckDeliveryIntervalH = FurthestCargoDeliveryDistance / getTruckSpeed() + getNoDeliveredCargosByTruck() +comeH;//+ time to come back;
	while (TruckDeliveryIntervalH > 23)
	{
		TruckDeliveryIntervalH = TruckDeliveryIntervalH - 23;
		TruckDeliveryIntervalD++;
	}
	return TruckDeliveryIntervalH;
}

int Truck::getTruckDeliveryIntervalDays()
{
	return TruckDeliveryIntervalD;
}

int Truck::getNoOfJourneys() const
{
	return TruckNoOfJourneys;
}
int Truck::getTruckID() const
{
	return TruckID;
}
int Truck::getNoDeliveredCargosByTruck() const
{
	return DeliveredCargosByTruck;
}
void Truck::getTruckMoveTime(int& h, int& d)
{
	h = TruckMoveTimeHour;
	d = TruckMoveTimeDay;
}
void Truck::LoadCargos(Cargo* c)
{
	c->setCargoDeliveryTime(TruckMoveTimeHour, TruckMoveTimeDay, TruckSpeed);//OPTION2
	LoadingCargos.enqueueDescending(c, c->getDeliveringDistance());//---->check descending or ascending
	//c->setTruckLoadedOn(this); //OPTION1
}

PriQ<Cargo*> Truck::getLoadedCargosInTruck() const
{
	return LoadingCargos;
}
void Truck::getTimeToComeBack(int &hour, int &day)
{
	Cargo* lastnode = LoadingCargos.getLastNode();
	int furthestdistance =lastnode->getDeliveringDistance();
	TimeToComeBackH = furthestdistance / TruckSpeed;
	while (TimeToComeBackH > 24)
	{
		TimeToComeBackH = TimeToComeBackH - 24;
		TimeToComeBackD++;
	}
}
Truck::~Truck()
{
}

ostream& operator<<(ostream& output, Truck* t)
{
	output << t->getTruckID();
	return output;
}
