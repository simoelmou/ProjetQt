#ifndef CONSULTATION_H
#define CONSULTATION_H

#include <iostream>

using namespace std;

class Consultation
{
public:
    Consultation();
    Consultation(int id, int idPatient, int idRessource);

    int getId() const;
    void setId(int value);

    int getIdPatient() const;
    void setIdPatient(int value);

    int getIdRessource() const;
    void setIdRessource(int value);

private:
    int id;
    int idPatient;
    int idRessource;
};

#endif // CONSULTATION_H
