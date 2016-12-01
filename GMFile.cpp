#include "GMFile.h"

GMEXPORT double GMFile_Copy(char* oldPath, char* newPath)
{
    return GMFile_OK;
}

GMEXPORT char* GMFile_GetOpenFilename(char* filters, char* defaultPath)
{
    if (defaultPath == "")
        defaultPath = NULL;
    if (filters == "")
        filters = NULL;

    nfdchar_t* path;
    nfdresult_t result = NFD_OpenDialog(filters, defaultPath, &path);
    if (result == NFD_OKAY)
        return path;
    else
        return "";
}

GMEXPORT char* GMFile_GetSaveFilename(char* filterList, char* defaultPath)
{
    return "";
}