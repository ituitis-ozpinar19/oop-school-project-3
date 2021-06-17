#ifndef ELVES
#define ELVES
#include "Faction.h"
#include <string>

using namespace std;

class Elves: public Faction{
    public:
        Elves(const string& ="",const int=0,const int=0,const int=0,const int=0);
        void PerformAttack();
        void ReceiveAttack(const string&,const int);
        int PurchaseWeapons(int wp);
        int PurchaseArmors(int ap);
        void Print();
};

#endif