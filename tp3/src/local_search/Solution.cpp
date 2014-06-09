#include "Solution.h"

bool Solution::operator == (const Solution &other) const
{
    return totalOmega2 == other.totalOmega2;
}	

bool Solution::operator < (const Solution &other) const
{
    return totalOmega2 < other.totalOmega2;
}	

bool Solution::operator > (const Solution &other) const
{
    return totalOmega2 > other.totalOmega2;
}	