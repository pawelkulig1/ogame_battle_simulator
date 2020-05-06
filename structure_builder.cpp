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
    rapid_fire[ID::CRAWLER] = 5;
    static_structure_arr[ID::LIGHT_FIGHTER] = StaticStructure(rapid_fire, 50, 400, 10);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());

    //HEAVY_FIGHTER = 3
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    rapid_fire[ID::CRAWLER] = 5;
    rapid_fire[ID::SMALL_CARGO] = 3;
    static_structure_arr[ID::HEAVY_FIGHTER] = StaticStructure(rapid_fire, 150, 1000, 25);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());

  	//CRUISER = 4,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    rapid_fire[ID::CRAWLER] = 5;
    rapid_fire[ID::LIGHT_FIGHTER] = 6;
    rapid_fire[ID::ROCKET_LAUNCHER] = 10;
    static_structure_arr[ID::CRUISER] = StaticStructure(rapid_fire, 400, 2700, 50);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//BATTLESHIP = 5,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    rapid_fire[ID::CRAWLER] = 5;
    static_structure_arr[ID::BATTLESHIP] = StaticStructure(rapid_fire, 1000, 6000, 200);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//BATTLECRUISER = 6,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    rapid_fire[ID::CRAWLER] = 5;
    rapid_fire[ID::SMALL_CARGO] = 3;
    rapid_fire[ID::LARGE_CARGO] = 3;
    rapid_fire[ID::CRUISER] = 4;
    rapid_fire[ID::BATTLESHIP] = 7;
    static_structure_arr[ID::BATTLECRUISER] = StaticStructure(rapid_fire, 700, 7000, 400);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//BOMBER = 7,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    rapid_fire[ID::CRAWLER] = 5;
    rapid_fire[ID::ROCKET_LAUNCHER] = 20;
    rapid_fire[ID::LIGHT_LASER] = 20;
    rapid_fire[ID::HEAVY_LASER] = 10;
    rapid_fire[ID::ION_CANNON] = 10;
    static_structure_arr[ID::BOMBER] = StaticStructure(rapid_fire, 1000, 7500, 500);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//DESTROYER = 8,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    rapid_fire[ID::CRAWLER] = 5;
    rapid_fire[ID::BATTLECRUISER] = 2;
    rapid_fire[ID::LIGHT_LASER] = 10;
    static_structure_arr[ID::DESTROYER] = StaticStructure(rapid_fire, 2000, 11000, 500);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
    //DEATHSTAR = 9,
    rapid_fire[ID::ESPIONAGE_PROBE] = 1250;
    rapid_fire[ID::SOLAR_SATELLITE] = 1250;
    rapid_fire[ID::SMALL_CARGO] = 250;
    rapid_fire[ID::LARGE_CARGO] = 250;
    rapid_fire[ID::LIGHT_FIGHTER] = 200;
    rapid_fire[ID::HEAVY_FIGHTER] = 100;
    rapid_fire[ID::CRUISER] = 33;
    rapid_fire[ID::BATTLESHIP] = 30;
    rapid_fire[ID::BATTLECRUISER] = 15;
    rapid_fire[ID::BATTLESHIP] = 30;
    rapid_fire[ID::BOMBER] = 30;
    rapid_fire[ID::DESTROYER] = 5;
    rapid_fire[ID::REAPER] = 10;
    rapid_fire[ID::PATHFINDER] = 30;
    rapid_fire[ID::COLONY_SHIP] = 250;
    rapid_fire[ID::CRAWLER] = 1250;
    rapid_fire[ID::ROCKET_LAUNCHER] = 200;
    rapid_fire[ID::LIGHT_LASER] = 200;
    rapid_fire[ID::HEAVY_LASER] = 100;
    rapid_fire[ID::ION_CANNON] = 100;
    rapid_fire[ID::GAUSS_CANNON] = 50;
    static_structure_arr[ID::DEATHSTAR] = StaticStructure(rapid_fire, 200000, 900000, 50000);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//REAPER = 10,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    rapid_fire[ID::CRAWLER] = 5;
    rapid_fire[ID::BATTLESHIP] = 7;
    rapid_fire[ID::BOMBER] = 4;
    rapid_fire[ID::DESTROYER] = 3;
    static_structure_arr[ID::REAPER] = StaticStructure(rapid_fire, 2800, 14000, 700);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//PATHFINDER = 11,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    rapid_fire[ID::CRAWLER] = 5;
    static_structure_arr[ID::PATHFINDER] = StaticStructure(rapid_fire, 200, 2300, 100);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//RECYCLER = 12,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    rapid_fire[ID::CRAWLER] = 5;
    static_structure_arr[ID::RECYCLER] = StaticStructure(rapid_fire, 1, 1600, 10);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//ESPIONAGE_PROBE = 13,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    static_structure_arr[ID::LIGHT_FIGHTER] = StaticStructure(rapid_fire, 0.01, 100, 0.01);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//SOLAR_SATELLITE = 14,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    static_structure_arr[ID::SOLAR_SATELLITE] = StaticStructure(rapid_fire, 1, 200, 1);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//COLONY_SHIP = 15,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    rapid_fire[ID::CRAWLER] = 5;
    static_structure_arr[ID::COLONY_SHIP] = StaticStructure(rapid_fire, 100, 3000, 50);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//CRAWLER = 16,
    rapid_fire[ID::ESPIONAGE_PROBE] = 5;
    rapid_fire[ID::SOLAR_SATELLITE] = 5;
    static_structure_arr[ID::CRAWLER] = StaticStructure(rapid_fire, 2, 1160, 2);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());

  	//DEFENCE

  	//ROCKET_LAUNCHER = 17,
    static_structure_arr[ID::ROCKET_LAUNCHER] = StaticStructure(rapid_fire, 80, 200, 20);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//LIGHT_LASER = 18,
    static_structure_arr[ID::LIGHT_LASER] = StaticStructure(rapid_fire, 100, 200, 25);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//HEAVY_LASER = 19,
    static_structure_arr[ID::HEAVY_LASER] = StaticStructure(rapid_fire, 250, 800, 100);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//ION_CANNON = 20,
    static_structure_arr[ID::ION_CANNON] = StaticStructure(rapid_fire, 150, 800, 500);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//GAUSS_CANNON = 21,
    static_structure_arr[ID::GAUSS_CANNON] = StaticStructure(rapid_fire, 1100, 3500, 200);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//PLASMA_TURRET = 22,
    static_structure_arr[ID::PLASMA_TURRET] = StaticStructure(rapid_fire, 3000, 2000, 300);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//SMALL_DOME_SHIELD = 23,
    static_structure_arr[ID::SMALL_DOME_SHIELD] = StaticStructure(rapid_fire, 1, 10000, 2000);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
  	//LARGE_DOME_SHIELD = 24,
    static_structure_arr[ID::LARGE_DOME_SHIELD] = StaticStructure(rapid_fire, 1, 1160, 10000);
    rapid_fire.erase(rapid_fire.begin(), rapid_fire.end());
}

Structure StructureBuilder::get_structure(ID id)
{
    return Structure(&static_structure_arr[id]);
}
