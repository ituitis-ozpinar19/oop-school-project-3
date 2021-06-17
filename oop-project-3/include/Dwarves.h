#ifndef DWARVES
#define DWARVES
#include "Faction.h"
#include <string>

using namespace std;

class Dwarves: public Faction{
    public:
        Dwarves(const string& ="",const int=0,const int=0,const int=0,const int=0);
        void PerformAttack();
        void ReceiveAttack(const string&,const int);
        int PurchaseWeapons(int wp);
        int PurchaseArmors(int ap);
        void Print();
};

#endif