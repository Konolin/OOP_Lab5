#include "CSVFileRepository.h"


using Repository::CSVRepository;


CSVRepository::CSVRepository(const string &_fileName) {
    fileName = _fileName;
}

void CSVRepository::add(const Scooter &newObject) {
    // TODO - implementation
}

void CSVRepository::remove(const Scooter &removedObject) {
    // TODO - implementation
}

vector<Scooter> CSVRepository::getAll() {
    // TODO - implementation
}

Scooter CSVRepository::getById(const string &objectId) {
    // TODO - implementation
}

void CSVRepository::update(const Scooter &updatedEntity) {
    // TODO - implementation
}
