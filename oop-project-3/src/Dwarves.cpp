#include <iostream>
#include <string>
#include "Faction.h"
#include "Dwarves.h"

using namespace std;

Dwarves::Dwarves(const string& n_name,const int n_unit,const int a_pt,const int h_pt ,const int un_reg):Faction(n_name,n_unit,a_pt,h_pt,un_reg){

}

void Dwarves::PerformAttack(){
    if(f_en->get_is_alive()==true && s_en->get_is_alive()==false){//first alive, second defeated
        f_en->ReceiveAttack("Dwarves",num_units);
    }else if(f_en->get_is_alive()==false && s_en->get_is_alive()==true){//second, alive first defeated
        s_en->ReceiveAttack("Dwarves",num_units);
    }else if(f_en->get_is_alive()==true && s_en->get_is_alive()==true){//both alive
        f_en->ReceiveAttack("Dwarves",num_units/2);//If both enemy factions are alive, attacks each enemy faction with half of its units with attack point.
        s_en->ReceiveAttack("Dwarves",num_units-num_units/2);
    }
}    

void Dwarves::ReceiveAttack(const string& attacker,const int units){
    int att_pt=0;//incoming attack point
    int total_damage=0;
    if(attacker== "Elves"){//dwarves attacked by elves
        if(f_en->get_name()=="Elves"){
            att_pt=f_en->get_attack_p();
            total_damage=att_pt*(units);
            //num_units=num_units-((f_en->get_attack_p()*(f_en->get_num_units()*percent/100))/health_p);
        }else if(s_en->get_name()=="Elves"){
            att_pt=s_en->get_attack_p();
            total_damage=att_pt*(units);
            //num_units=num_units-((s_en->get_attack_p()*(s_en->get_num_units()*percent/100))/health_p);
        }
    }else if(attacker=="Orcs"){//dwarves attacked by orcs
        if(f_en->get_name()=="Orcs"){
            att_pt=f_en->get_attack_p();
            total_damage=att_pt*(units);
            //num_units=num_units-((f_en->get_attack_p()*(f_en->get_num_units()*percent/100))/health_p);
        }else if(s_en->get_name()=="Orcs"){
            att_pt=s_en->get_attack_p();
            total_damage=att_pt*(units);
            //num_units=num_units-((s_en->get_attack_p()*(s_en->get_num_units()*percent/100))/health_p);
        }
    }
    num_units=num_units-(total_damage/health_p);
}

int Dwarves::PurchaseWeapons(int wp){
    int earning=0;
    attack_p+=wp;
    earning=10*wp;
    return earning;
}

int Dwarves::PurchaseArmors(int ap){
    int earning=0;
    health_p+=2*ap;
    earning=3*ap;
    return earning;
}

void Dwarves::Print(){
    cout<<"Taste the power of our axes!"<<endl;
    Faction::Print();
}