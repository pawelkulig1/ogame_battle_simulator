

struct resources
{
	int metal;
	int crystal;
	int deuter;
	resources()
	{
		metal = 0;
		crystal = 0;
		deuter = 0;
	}
	resources(int m, int c, int d)
	{
		metal = m;
		crystal = c;
		deuter = d;
	};
	resources operator + (const resources& p)
	{
	  resources temp;
	  temp.metal = metal + p.metal;
	  temp.crystal = crystal + p.crystal;
	  temp.deuter = deuter + p.deuter;
	  return temp;
	}
    resources operator - (const resources& p)
	{
      resources temp;
      temp.metal = metal - p.metal;
      temp.crystal = crystal - p.crystal;
	  temp.deuter = deuter - p.deuter;
      return temp;
    }
};
