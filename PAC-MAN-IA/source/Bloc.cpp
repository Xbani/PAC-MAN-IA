#include "Bloc.h"

Bloc::Bloc()
{
	type = EMPTY;
}



Bloc::Bloc(const Bloc& blocIn)
{
	type = blocIn.type;
}

Bloc::~Bloc()
{
}

Bloc::Bloc(BlocType typeIn, std::shared_ptr<Entity> contenuIn)
{
	type = typeIn;
}

Bloc::BlocType Bloc::onPacmanPresence()
{
	if (type != EMPTY && type != WALL) {
		BlocType typeOut = type;
		type = EMPTY;
		return typeOut;
	} else {
		return type;
	}
}

Bloc& Bloc::operator=(const Bloc& blocIn)
{
	type = blocIn.type;
}
