#pragma once
#include "Item.h"

class Cat : public Item
{
public:
    Cat();
    virtual ~Cat();
    virtual void Description() const override;
    virtual void Use() override;

private:
    bool m_purring;
};
