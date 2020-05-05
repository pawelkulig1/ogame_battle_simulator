#include "structure.h"
#include <algorithm>
#include "static_structure.h"

Structure::Structure(StaticStructure *ststructure)
{
    m_ststructure_ptr = ststructure;
    m_hull = ststructure->get_hull();
    m_shield = ststructure->get_shield();

    m_exploded = false;
}

int Structure::get_rapid_fire(Structure &another)
{
    return m_ststructure_ptr->get_rapid_fire(another.m_ststructure_ptr->get_id());
}

bool Structure::attack(Structure &another)
{
    const Structure::default_type another_default_hull = another.m_ststructure_ptr->get_hull();
    const Structure::default_type another_default_shield = another.m_ststructure_ptr->get_shield();
    const int threshold = static_cast<double>(0.7 * another_default_hull);
    int attack = m_ststructure_ptr->get_attack();
    bool will_shot_again = false;
    int rapid_fire = get_rapid_fire(another);

    if ((rapid_fire - 1) < ((rand() % rapid_fire) + 1))
    {
        will_shot_again = true;
    }

    if (attack <= 0.01 * static_cast<double>(another_default_shield))
    {
        return will_shot_again;
    }

    if (another.m_shield <= attack)
    {
        attack -= another.m_shield;
        another.m_shield = 0;
    }
    else
    {
        another.m_shield -= attack;
        return will_shot_again;
    }    
    
    another.m_hull = std::max_element(another.m_hull - attack, 0);

    if (another.m_hull < threshold)
    {
        if ((rand() % another_default_hull) > another.m_hull)
        {
            m_exploded = true;
        }
    }
}

bool Structure::is_exploding() const
{
    return m_exploded;
}
