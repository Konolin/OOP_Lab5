#include "Scooter.h"

using Domain::Scooter;

Scooter::Scooter(const string &_id, const string &_model, Scooter::Date _commissionDate, int _mileage,
                 const string &_lastLocation, Scooter::Status _status) {
    id = _id;
    model = _model;
    commissionDate = _commissionDate;
    mileage = _mileage;
    lastLocation = _lastLocation;
    status = _status;
}