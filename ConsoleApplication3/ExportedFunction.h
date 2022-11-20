// ExportedFunction Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <string>
#include <vector>
struct _IMAGE_DOS_HEADER;
class ExportedFunction {
	const char* AddressOfName        ;
	int      (* AddressOfFunction )();
	bool        isCpp                ;
	std::string name                 ;
	static std::string ExtractCppFunctionName(const char* AddressOfName);
public:
	ExportedFunction
	( const char* AddressOfName        
	, int      (* AddressOfFunction )()
	) noexcept;
	std::string Name() const;
	int (*Address() const)();
	bool IsCpp() const noexcept;
	static std::vector<ExportedFunction> MakeVector(const _IMAGE_DOS_HEADER& imageHeader);
};
