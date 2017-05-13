#include "model/consultation.h"

Consultation::Consultation()
{

}

Consultation::Consultation(int id, int idPatient, int idRessource)
{
    setId(id);
    setIdPatient(idPatient);
    setIdRessource(idRessource);
}

int Consultation::getId() const
{
    return id;
}

void Consultation::setId(int value)
{
    id = value;
}

int Consultation::getIdPatient() const
{
    return idPatient;
}

void Consultation::setIdPatient(int value)
{
    idPatient = value;
}

int Consultation::getIdRessource() const
{
    return idRessource;
}

void Consultation::setIdRessource(int value)
{
    idRessource = value;
}
