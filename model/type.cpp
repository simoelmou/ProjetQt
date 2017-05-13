#include "model/type.h"

int Type::getId() const
{
    return id;
}

void Type::setId(int value)
{
    id = value;
}

QString Type::getLabel() const
{
    return label;
}

void Type::setLabel(const QString &value)
{
    label = value;
}

Type::Type()
{


}

Type::Type(int id, QString label)
{
    this->id = id;
    this->label = label;
}
