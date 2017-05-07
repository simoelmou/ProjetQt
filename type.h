#ifndef TYPE_H
#define TYPE_H

#include <QString>

class Type
{

private:
    int id;
    QString label;
public:
    Type();
    Type(int id, QString label);

    int getId() const;
    void setId(int value);

    QString getLabel() const;
    void setLabel(const QString &value);
};

#endif // TYPE_H
