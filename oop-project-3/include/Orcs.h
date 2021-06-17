#ifndef ORCS
#define ORCS
#include "Faction.h"
#include <string>

using namespace std;

class Orcs: public Faction{
    public:
        Orcs(const string& ="",const int=0,const int=0,const int=0,const int=0);
        void PerformAttack();
        void ReceiveAttack(const string&,const int);
        int PurchaseWeapons(int wp);
        int PurchaseArmors(int ap);
        void Print();
};

#endif