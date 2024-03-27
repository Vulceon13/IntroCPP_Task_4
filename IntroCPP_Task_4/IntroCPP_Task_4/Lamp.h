#pragma once
#include "Item.h"

class Lamp : public Item
{
public:
    Lamp();
    virtual ~Lamp();
    virtual void Description() const override;
    virtual void Use() override;

private:
    bool m_turnedOn;
};