#include <iostream>
#include <string>
#include "Merchant.h"
#include "Faction.h"
#include <string>

using namespace std;

Merchant::Merchant(const int s_wp, const int s_ap){
    start_wp_pt=s_wp;
    start_ar_pt=s_ap;
    revenue=0;
    wp_pt_left=start_wp_pt;
    ar_pt_left=start_ar_pt;
}

void Merchant::AssignFactions(Faction* f_f, Faction* s_f, Faction* t_f){
    f_faction=f_f;
    s_faction=s_f;
    t_faction=t_f;
}

bool Merchant::SellWeapons(const string& buyer, int amount){
    bool rt=true;
    if(amount<=wp_pt_left){
        if(buyer==f_faction->get_name()){
            if(f_faction->IsAlive()){
                revenue += f_faction->PurchaseWeapons(amount);
                wp_pt_left-=amount;
                cout<<"Weapons sold!"<<endl;
            }else{
                cout<<"The faction you want to sell weapons is dead!"<<endl;
                rt=false;
            }
        }else if(buyer==s_faction->get_name()){
            if(s_faction->IsAlive()){
                revenue += s_faction->PurchaseWeapons(amount);
                wp_pt_left-=amount;
                cout<<"Weapons sold!"<<endl;
            }else{
                cout<<"The faction you want to sell weapons is dead!"<<endl;
                rt=false;
            }
        }else if(buyer==t_faction->get_name()){
            if(t_faction->IsAlive()){
                revenue += t_faction->PurchaseWeapons(amount);
                wp_pt_left-=amount;
                cout<<"Weapons sold!"<<endl;
            }else{
                cout<<"The faction you want to sell weapons is dead!"<<endl;
                rt=false;
            }
        }
    }else{
        cout<<"You try to sell more weapons than you have in possession."<<endl;
        rt=false;
    }
    return rt;
}

bool Merchant::SellArmors(const string& buyer, int amount){
    bool rt=true;
    if(amount<=ar_pt_left){
        if(buyer==f_faction->get_name()){
            if(f_faction->IsAlive()){
                revenue += f_faction->PurchaseArmors(amount);
                ar_pt_left-=amount;
                cout<<"Armors sold!"<<endl;
            }else{
                cout<<"The faction you want to sell weapons is dead!"<<endl;
                rt=false;
            }
        }else if(buyer==s_faction->get_name()){
            if(s_faction->IsAlive()){
                revenue += s_faction->PurchaseArmors(amount);
                ar_pt_left-=amount;
                cout<<"Armors sold!"<<endl;
            }else{
                cout<<"The faction you want to sell weapons is dead!"<<endl;
                rt=false;
            }
        }else if(buyer==t_faction->get_name()){
            if(t_faction->IsAlive()){
                revenue += t_faction->PurchaseArmors(amount);
                ar_pt_left-=amount;
                cout<<"Armors sold!"<<endl;
            }else{
                cout<<"The faction you want to sell weapons is dead!"<<endl;
                rt=false;
            }
        }
    }else{
        cout<<"You try to sell more armors than you have in possession."<<endl;
        rt=false;
    }
    return rt;
}

void Merchant::EndTurn(){
    wp_pt_left=start_wp_pt;
    ar_pt_left=start_ar_pt;
}
