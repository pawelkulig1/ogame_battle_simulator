#include "structure_builder.h"
#include <string>

StructureBuilder::StructureBuilder()
{
    build_structures();
}

void StructureBuilder::build_structures()
{
    //SMALL CARGO
    std::map<int, int> rapid_fire;
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    static_structure_arr[ID::SMALL_CARGO] = StaticStructure(rapid_fire, 5, 400, 10);
    
    //LARGE CARGO
    std::map<int, int> rapid_fire;
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    static_structure_arr[ID::LARGE_CARGO] = StaticStructure(rapid_fire, 5, 1200, 25);
    
    //LIGHT_FIGHTER
    std::map<int, int> rapid_fire;
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    static_structure_arr[ID::LIGHT_FIGHTER] = StaticStructure(rapid_fire, 50, 400, 10);

    //TODO
}

Structure StructureBuilder::get_structure(ID id) 
{   
    return Structure(&static_structure_arr[id]);
}