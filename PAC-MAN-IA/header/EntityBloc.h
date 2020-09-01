#pragma once
#include "Entity.h"

class EntityBloc : public Entity
{
public:
    enum BlocEntity {
        POINT,
        GUM,
        NONE
    };

protected:
    BlocEntity type;

public:
    EntityBloc(BlocEntity typeIn);

    BlocEntity getType();
};

