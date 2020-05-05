#pragma once

#include "static_structure.h"
#include "structure.h"
#include <array>

class StructureBuilder
{
    std::array<StaticStructure, ID::SIZE> static_structure_arr;
    void build_structures();
public:
    StructureBuilder();
    Structure get_structure(ID id);
};