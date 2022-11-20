// ExportedFunction Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include "ExportedFunction.h"
#include <string.h>
#include <Windows.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

ExportedFunction::ExportedFunction
( const char* AddressOfName        
, int      (* AddressOfFunction )()
) noexcept
	: AddressOfName     { AddressOfName         }
	, AddressOfFunction { AddressOfFunction     }
	, isCpp             { *AddressOfName == '?' }
	, name              { isCpp ? ExtractCppFunctionName(AddressOfName) : AddressOfName }
{
}
std::string ExportedFunction::ExtractCppFunctionName(const char* AddressOfName)
{
	const char* first = &AddressOfName[1];
	return { first, static_cast<size_t>(strchr(first, '@') - first) };
}
std::string ExportedFunction::Name() const
{
	return name;
}
int (*ExportedFunction::Address() const)()
{
	return AddressOfFunction;
}
bool ExportedFunction::IsCpp() const noexcept
{
	return isCpp;
}
std::vector<ExportedFunction> ExportedFunction::MakeVector(const _IMAGE_DOS_HEADER& imageHeader)
{
	const auto & export_directory = *PIMAGE_EXPORT_DIRECTORY      (&LPCSTR(&imageHeader)[PIMAGE_NT_HEADERS(&LPCSTR(&imageHeader)[imageHeader.e_lfanew])->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress]);
	const auto AddressOfNames     = reinterpret_cast<const DWORD*>(&LPCSTR(&imageHeader)[export_directory.AddressOfNames    ]);
	const auto AddressOfFunctions = reinterpret_cast<const DWORD*>(&LPCSTR(&imageHeader)[export_directory.AddressOfFunctions]);
	std::vector<ExportedFunction> retval; 
	retval.reserve(export_directory.NumberOfNames);
	for (DWORD i = 0; i < export_directory.NumberOfNames; ++i) {
		retval.push_back(
			{                            &LPCSTR(&imageHeader)[AddressOfNames    [i]] 
			, reinterpret_cast<int(*)()>(&LPCSTR(&imageHeader)[AddressOfFunctions[i]])
			});
	}
	std::sort(retval.begin(), retval.end(), [](const ExportedFunction& lhs, const ExportedFunction& rhs)->bool
		{
			return lhs.Name() < rhs.Name();
		});
	return retval;
}
