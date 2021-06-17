#include <iostream>
#include <string>
#include "Faction.h"
#include "Orcs.h"

using namespace std;

Orcs::Orcs(const string& n_name,const int n_unit,const int a_pt,const int h_pt ,const int un_reg):Faction(n_name,n_unit,a_pt,h_pt,un_reg){

}

void Orcs::PerformAttack(){
    if(f_en->get_is_alive()==true && s_en->get_is_alive()==false){//first alive, second defeated
        f_en->ReceiveAttack("Orcs",num_units);
    }else if(f_en->get_is_alive()==false && s_en->get_is_alive()==true){//second, alive first defeated
        s_en->ReceiveAttack("Orcs",num_units);
    }else if(f_en->get_is_alive()==true && s_en->get_is_alive()==true){//both alive
        if(f_en->get_name()=="Elves"){//If both enemy factions are alive, attacks Elves with 70% of its units with attack
            f_en->ReceiveAttack("Orcs",num_units*70/100);//point and attacks Dwarves with rest of the units with attack point.
            s_en->ReceiveAttack("Orcs",num_units-(num_units*70/100));
        }else{
            f_en->ReceiveAttack("Orcs",num_units-(num_units*70/100));
            s_en->ReceiveAttack("Orcs",num_units*70/100);
        }
    }

}

void Orcs::ReceiveAttack(const string& attacker,const int units){
    int att_pt=0;//incoming attack point
    int total_damage=0;
    if(attacker== "Elves"){//orcs attacked by elves
        if(f_en->get_name()=="Elves"){
            att_pt=(f_en->get_attack_p()*3)/4;//If attacking faction is Elves, incoming attack point is reduced to 75% of its original value.
            total_damage=att_pt*(units);
        }else if(s_en->get_name()=="Elves"){
            att_pt=(s_en->get_attack_p()*3)/4;//If attacking faction is Elves, incoming attack point is reduced to 75% of its original value.
            total_damage=att_pt*(units);
        }
    }else if(attacker=="Dwarves"){//orcs attacked by dwarves
        if(f_en->get_name()=="Dwarves"){
            att_pt=(f_en->get_attack_p()*4)/5;//If attacking faction is Dwarves, incoming attack point is reduced to 80% of its original value.
            total_damage=att_pt*(units);
        }else if(s_en->get_name()=="Dwarves"){
            att_pt=(s_en->get_attack_p()*4)/5;//If attacking faction is Dwarves, incoming attack point is reduced to 80% of its original value.
            total_damage=att_pt*(units);
        }
    }
    num_units=num_units-(total_damage/health_p);
}

int Orcs::PurchaseWeapons(int wp){
    int earning=0;
    attack_p+=2*wp;
    earning=20*wp;
    return earning;
}

int Orcs::PurchaseArmors(int ap){
    int earning=0;
    health_p+=3*ap;
    earning=ap;
    return earning;
}

void Orcs::Print(){
    cout<<"Stop running, you’ll only die tired!"<<endl;
    Faction::Print();
}