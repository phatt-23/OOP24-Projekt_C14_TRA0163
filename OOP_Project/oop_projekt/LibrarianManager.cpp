#include "LibrarianManager.h"

LibrarianManager::LibrarianManager() = default;
LibrarianManager::~LibrarianManager() = default;

std::shared_ptr<Librarian> LibrarianManager::addLibrarian(int keyID, const std::string& forename, const std::string& surname, int salary, const std::string& dateOfEmployment)
{
    this->librarian_list.emplace(keyID, std::make_shared<Librarian>(salary, dateOfEmployment, keyID, forename, surname));
    return this->librarian_list.at(keyID);
}

std::shared_ptr<Librarian> LibrarianManager::getLibrarian(int keyID)
{
    return this->librarian_list.at(keyID);
}

std::string LibrarianManager::toStr(int tabSize)
{
    std::stringstream ss;

    ss << tabs(tabSize) << "LibrarianManager " << "{" << std::endl;

    for (const auto& l : this->librarian_list) {
        ss << l.second->toStr(tabSize + 1) << std::endl;
    }

    ss << tabs(tabSize) << "}";

    return ss.str();
}