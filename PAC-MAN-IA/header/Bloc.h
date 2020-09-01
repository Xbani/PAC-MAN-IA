#pragma once

#include <memory>

#include "Controller.h"
#include "Entity.h"
#include "EntityBloc.h"

class Bloc : public Entity
{
public:
    enum BlocType {
        WALL,
        EMPTY,
        POINT,
        GUM
    };

protected:
    BlocType type;

public:
    Bloc();
    Bloc(const Bloc& blocIn);
    ~Bloc();

    Bloc(BlocType typeIn, std::shared_ptr<Entity> contenuIn);

    Bloc::BlocType onPacmanPresence();

    Bloc& operator=(const Bloc& blocIn);
};