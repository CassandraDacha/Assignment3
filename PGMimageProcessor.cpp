#include "PGMimageProcessor.h"


DCHCAS001::PGMimageProcessor::PGMimageProcessor() : row(0), col(0), id(nullptr)
{}

DCHCAS001::PGMimageProcessor::PGMimageProcessor(int row, int col, char id) : row(row), col(col),
id(new char(id))
{}

DCHCAS001::PGMimageProcessor::~PGMimageProcessor()
{
if(this->id != nullptr) // We have to make sure we're not trying
// to release a bit of memory that doesn't exist.
{
delete this->id;
}
}



DCHCAS001::PGMimageProcessor::PGMimageProcessor(const DCHCAS001::PGMimageProcessor & p) : row(p.row), col(p.col),
id(nullptr)
{
if(p.id != nullptr)
{
id = new char(*p.id);
}
}

DCHCAS001::PGMimageProcessor& DCHCAS001::PGMimageProcessor::operator=(const DCHCAS001::PGMimageProcessor & rhs)
{
if(this != &rhs) // Checks to make that we are not performing a self-assignment
{
this->row = rhs.row;
this->col = rhs.col;
if(this->id != nullptr)
{
delete this->id; // 'this' may already be managing a bit of
// memory so we must release it to prevent any memory leaks.
this->id = nullptr;
}
if(rhs.id != nullptr)
{
this->id = new char(*rhs.id);
}
}
return *this;
}
DCHCAS001::PGMimageProcessor::PGMimageProcessor(DCHCAS001::PGMimageProcessor && p) : row(p.row), col(p.col),
id(p.id)
{
p.id = nullptr;
}

DCHCAS001::PGMimageProcessor& DCHCAS001::PGMimageProcessor::operator=(DCHCAS001::PGMimageProcessor && rhs)
{
if(this != &rhs) // Checks to make that we are not performing a
// self-assignment
{
this->row = rhs.row;
this->col = rhs.col;
if(this->id != nullptr)
{
delete this->id; // 'this' may already be managing a bit
// of memory so we must release it to prevent any memory leaks.
this->id = nullptr;
}
if(rhs.id != nullptr)
{
this->id = rhs.id;
rhs.id = nullptr; // rhs is no longer responsible for the bit
// of memory 'rhs.id' points to so we set it to nullptr
}
}
return *this;
}
