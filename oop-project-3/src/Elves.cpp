#include <iostream>
#include <string>
#include "Faction.h"
#include "Elves.h"

using namespace std;

Elves::Elves(const string& n_name,const int n_unit,const int a_pt,const int h_pt ,const int un_reg):Faction(n_name,n_unit,a_pt,h_pt,un_reg){

}

void Elves::PerformAttack(){
    if(f_en->get_is_alive()==true && s_en->get_is_alive()==false){//first alive, second defeated
        if(f_en->get_name()=="Dwarves"){
            f_en->ReceiveAttack("Elves",num_units*(3/2));//When attacking Dwarves, attack point attack point of elves is increased to 150%.
        }else{
            f_en->ReceiveAttack("Elves",num_units);
        }
    }else if(f_en->get_is_alive()==false && s_en->get_is_alive()==true){//second, alive first defeated
        if(s_en->get_name()=="Dwarves"){
            s_en->ReceiveAttack("Elves",num_units*(3/2));//When attacking Dwarves, attack point attack point of elves is increased to 150%.
        }else{
            s_en->ReceiveAttack("Elves",num_units);
        }
    }else if(f_en->get_is_alive()==true && s_en->get_is_alive()==true){//both alive
        if(f_en->get_name()=="Orcs"){
            f_en->ReceiveAttack("Elves",num_units*60/100);
            s_en->ReceiveAttack("Elves",(num_units-num_units*60/100)*(3/2));//When attacking Dwarves, attack point attack point of elves is increased to 150%.
        }else{
            f_en->ReceiveAttack("Elves",(num_units-num_units*60/100)*(3/2));//When attacking Dwarves, attack point attack point of elves is increased to 150%.
            s_en->ReceiveAttack("Elves",num_units*60/100);
        }
    }

}

void Elves::ReceiveAttack(const string& attacker,const int units){
    int att_pt=0;//incoming attack point
    int total_damage=0;
    if(attacker== "Orcs"){//elves attacked by orcs
        if(f_en->get_name()=="Orcs"){
            att_pt=(f_en->get_attack_p()*5)/4;//If attacking faction is Orcs, incoming attack point is increased to 125% of its original value.
            total_damage=att_pt*(units);
        }else if(s_en->get_name()=="Orcs"){
            att_pt=(s_en->get_attack_p()*5)/4;//If attacking faction is Orcs, incoming attack point is increased to 125% of its original value.
            total_damage=att_pt*(units);
        }
    }else if(attacker=="Dwarves"){//elves attacked by dwarves
        if(f_en->get_name()=="Dwarves"){
            att_pt=(f_en->get_attack_p()*3)/4;//If attacking faction is Dwarves, incoming attack point is reduced to 75% of its original value.
            total_damage=att_pt*(units);
        }else if(s_en->get_name()=="Dwarves"){
            att_pt=(s_en->get_attack_p()*3)/4;//If attacking faction is Dwarves, incoming attack point is reduced to 75% of its original value.
            total_damage=att_pt*(units);
        }
    }
    num_units=num_units-(total_damage/health_p);
}

int Elves::PurchaseWeapons(int wp){
    int earning=0;
    attack_p+=2*wp;
    earning=15*wp;
    return earning;
}

int Elves::PurchaseArmors(int ap){
    int earning=0;
    health_p+=4*ap;
    earning=5*ap;
    return earning;
}

void Elves::Print(){
    cout<<"You cannot reach our elegance."<<endl;
    Faction::Print();
}