
#include <map>

enum ID {
	SMALL_CARGO = 0,
	LARGE_CARGO = 1,
	
};


int main() {
    std::map<int, int> rr;
    r[8]  = 5;
    r[10] = 5;
    StaticObj small_cargo(ID::SMALL_CARGO, 20, 200, 20, rr);
    StaticObj large_cargo(ID::LARGE_CARGO, 20, 200, 20, rr);

    battle.addStructure(ATTACKER, small_cargo, 100);
    battle.addStructure(DEFENDER, small_cargo, 100);
    battle.simulate();
    for (int i = 0; i < 6; i++)
    {
		for (Structure s: attacking)
		{
			bool can_attack = true;
			while(can_attack)
			{
			int attacker_pos = rand() % defending.length();
			can_attack = o.attack(d);
			}
		}
		for (Structure s: defending) // for (int i=0;i<defending.length(); i++) s == defending[i]
		{
			bool can_attack = true;
			while(can_attack)
			{
			int attacker_pos = rand() % attacker.length();
			can_attack = s.attack(another[attacker_pos]);
			}
		}

		for (int ) {
			defending.remove(defending.begin() + i);
		}
    }





    return 0;
}
