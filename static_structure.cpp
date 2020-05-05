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

int StaticStructure::get_id() const
{
    return m_id;
}

int StaticStructure::get_rapid_fire(int id) const
{
    int rapid = 0;
    std::map<const int, int>::const_iterator rapid_pos = m_rapid_fire.find(id);
    if (rapid_pos != m_rapid_fire.end())
    {
        rapid = rapid_pos->second;
    }
    return rapid;
}