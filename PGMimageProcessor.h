#ifndef __PGMimage__
#define __PGMimage__

namespace DCHCAS001 // The name of this namespace should normally be your student number for assignments
{


class PGMimageProcessor
{
	// Local Variables
	int row, col;
	char *id;
	
	public: // All class members are private by default.
	// The public keyword allows us to make any method and/or attributes
	// that follow public.
	
	PGMimageProcessor(); // Default Constructor
	PGMimageProcessor(const int row, const int col, const char id); // Custom Constructor
	
	~PGMimageProcessor(); // Destructor
	
	PGMimageProcessor(const PGMimageProcessor& p); // Copy Constructor
	PGMimageProcessor(PGMimageProcessor && p); // Move constructor
	
	PGMimageProcessor& operator=(const PGMimageProcessor& rhs); // Copy Assignment Operator
	
	PGMimageProcessor& operator=(PGMimageProcessor&& rhs); //Move Assignment Operator
	
	};
}
#endif
