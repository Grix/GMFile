#include "nfd/nfd.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define GMEXPORT extern "C" __declspec (dllexport)
#else
    #define GMEXPORT extern "C"
#endif

#define GMFile_ERROR -1.
#define GMFile_OK 1.

//Copies file or folder.
GMEXPORT double GMFile_Copy(char* oldLocation, char* newLocation);

//Show open file dialog and return chosen path
GMEXPORT char* GMFile_GetOpenFilename(char* filterList, char* defaultPath);

//Show save file dialog and return chosen path
GMEXPORT char* GMFile_GetSaveFilename(char* filterList, char* defaultPath);

//Show folder selection dialog and return chosen path
GMEXPORT char* GMFile_GetFolder(char* defaultPath);