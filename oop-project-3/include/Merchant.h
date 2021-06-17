#ifndef MERCHANT
#define MERCHANT

#include "Faction.h"
#include <string>

using namespace std;

class Merchant{
    private:
        Faction* f_faction;//first faction
        Faction* s_faction;//second faction
        Faction* t_faction;//third faction
        int start_wp_pt;//fixed starting weapon point
        int start_ar_pt;//fixed starting armor point
        int revenue;
        int wp_pt_left;//weapon points left for the day
        int ar_pt_left;//armor points left for the day
    public:
        Merchant(const int=0,const int=0);
        void AssignFactions(Faction*, Faction*, Faction*);
        bool SellWeapons(const string&,int);
        bool SellArmors(const string&,int);
        void EndTurn();
        int GetArmorPoints(){
            return ar_pt_left;
        }
        int GetWeaponPoints(){
            return wp_pt_left;
        }
        int GetRevenue(){
            return revenue;
        }
};

#endif