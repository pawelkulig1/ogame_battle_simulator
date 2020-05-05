#include "structure_builder.h"
#include <string>

StructureBuilder::StructureBuilder()
{
    build_structures();
}

void StructureBuilder::build_structures()
{
    std::map<int, int> rapid_fire;
    //SMALL CARGO
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    static_structure_arr[ID::SMALL_CARGO] = StaticStructure(rapid_fire, 5, 400, 10);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
    
    //LARGE CARGO
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    static_structure_arr[ID::LARGE_CARGO] = StaticStructure(rapid_fire, 5, 1200, 25);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
    
    //LIGHT_FIGHTER
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    static_structure_arr[ID::LIGHT_FIGHTER] = StaticStructure(rapid_fire, 50, 400, 10);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());

    //TODO
}

Structure StructureBuilder::get_structure(ID id) 
{   
    return Structure(&static_structure_arr[id]);
}