#pragma once

class Bloc
{
public:
    enum BlocType {
        EMPTY,
        DOT,
        GUM
    };

protected:
    BlocType type;

public:
    Bloc();
    Bloc(const Bloc& blocIn);
    ~Bloc();

    Bloc(BlocType typeIn);

    void onPacmanPresence();

    Bloc& operator=(const Bloc& blocIn);
};