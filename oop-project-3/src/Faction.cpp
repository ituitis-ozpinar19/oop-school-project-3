#include "Faction.h"
#include <iostream>
#include <string>

using namespace std;

Faction::Faction(const string& n_name,const int n_unit,const int a_pt,const int h_pt ,const int un_reg){
    name=n_name;
    num_units=n_unit;
    attack_p=a_pt;
    health_p=h_pt;
    unit_reg=un_reg;
    total_h=n_unit*h_pt;
    is_alive=true;
}

void Faction::AssignEnemies(Faction* first_en, Faction* second_en){
    f_en=first_en;
    s_en=second_en;
}

void Faction::Print(){
    cout<<"Faction Name: "<<name<<endl;
    if(is_alive==true){
        cout<<"Status: "<<"Alive"<<endl;
    }else{
        cout<<"Status: "<<"Defeated"<<endl;
    }
    cout<<"Number of Units: "<<num_units<<endl;
    cout<<"Attack Point: "<<attack_p<<endl;
    cout<<"Health Point: "<<health_p<<endl;
    cout<<"Unit Regen Number: "<<unit_reg<<endl;
    cout<<"Total Faction Health: "<<total_h<<endl;
}

void Faction::EndTurn(){
    if(num_units<0){
        num_units=0;
    }
    if(num_units==0){
        is_alive=false;
    }
    if(IsAlive()){
        num_units+=unit_reg;
    }
    total_h=num_units*health_p;
}