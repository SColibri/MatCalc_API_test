// MatCalc_API_test.cpp : Defines the entry point for the application.
//

#include <Windows.h>
#include <vector>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "MatCalc_API_test.h"
#include "include/API_matcalc_definitions.h"

int main()
{
#pragma region Dynamic_dll_load_using_windows_h
	// get the dll source folder
	std::filesystem::path fileP = "C:/Program Files/MatCalc 6/mc_core.dll";

	// Add path of dll to the searching patterns
	SetDllDirectoryA(TEXT(fileP.parent_path().string().c_str()));

	// load library
	HINSTANCE _library = LoadLibrary(TEXT("C:/Program Files/MatCalc 6/mc_core.dll"));
	AM_MCC_LIB_LOAD_ALL(_library);
	

	// MATCALC Feedback: use initialize external const char
	bool out_initialize = MCC_InitializeExternalConstChar("C: / Program Files / MatCalc 6", false);
	int out_openDatabase = MCC_OpenDatabaseFileChar("C:/Program Files/MatCalc 6/database/thermodynamic/mc_al.tdb", DBOC_EQUILIBRIUM, false);
	int out_readDatabase = MCC_ReadDatabaseFile(DBOC_EQUILIBRIUM, true, false);
	int elementName = MCC_GetElementIndex("AL");
	// NOTE: Please change the working directory and database paths inside the script!
	// When I set an invalid path out = 51
	// No error when out code is 50, but no work was done.
	// When setting a valid path exception is thrown 
	int out = MCCOL_RunScriptFileChar("Other/GM02_main_loop.mcs"); // Result is code 50.

	// Same problem arises when using the static library
#pragma endregion

	return 0;
}
