#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
public:
    BoxOfDonuts();
    virtual ~BoxOfDonuts();
    virtual void Description() const override;
    virtual void Use() override;

private:
    int m_count;
};
