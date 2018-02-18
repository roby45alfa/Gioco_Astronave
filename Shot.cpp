#include "stdafx.h"
#include "Shot.h"
#include "Entita.h"

Shot::Shot(Entita A) : Damage(5 * A.GetLVL()) {}


Shot::~Shot()
{
}
