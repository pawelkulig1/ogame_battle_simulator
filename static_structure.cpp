#include "static_structure.h"

StaticStructure::default_type StaticStructure::get_attack() const
{
    return m_attack;
}

StaticStructure::default_type StaticStructure::get_hull() const
{
    return m_hull;
}

StaticStructure::default_type StaticStructure::get_shield() const
{
    return m_shield;
}