#ifndef FACTION
#define FACTION

#include <iostream>
#include <string>

using namespace std;

class Faction{//abstract base class for dwarwes,elves and orcs.
    protected:
        string name;
        Faction* f_en;//pointer to first enemy
        Faction* s_en;//pointer to secon enemy
        int num_units;//number of units
        int attack_p;//attack points
        int health_p;//health points
        int unit_reg;//unit regeneration number
        int total_h;//total health
        bool is_alive;//flag to control alive/defeated status
    public:
        Faction(const string& ="",/*Faction* =NULL,Faction* =NULL,*/const int=0,const int=0,const int=0,const int=0);
        void AssignEnemies(Faction*,Faction*);
        virtual void PerformAttack()=0;
        virtual void ReceiveAttack(const string&,const int)=0;
        virtual int PurchaseWeapons(int wp)=0;
        virtual int PurchaseArmors(int ap)=0;
        virtual void Print();
        void EndTurn();

        bool get_is_alive(){
            return is_alive;
        }
        string get_name(){
            return name;
        }
        int get_attack_p(){
            return attack_p;
        }
        int get_num_units(){
            return num_units;
        }
        bool IsAlive(){
            return is_alive;
        }
};


#endif