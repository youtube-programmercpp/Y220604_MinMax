// RedirectStdinToFile Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include "RedirectStdinToFile.h"
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <assert.h>
#include <sys/stat.h>
#include <stdexcept>
#include <sstream>

void RedirectStdinToFile(_In_z_ char const* _FileName)
{
	int fd;
	int e = /*_Check_return_wat_ _ACRTIMP errno_t __cdecl */_sopen_s
	( /*_Out_  int       * _FileHandle    */&fd
	, /*_In_z_ char const* _FileName      */_FileName
	, /*_In_   int         _OpenFlag      */_O_RDONLY | _O_TEXT
	, /*_In_   int         _ShareFlag     */_SH_DENYWR
	, /*_In_   int         _PermissionMode*/_S_IREAD
	);
	if (e)
		throw std::system_error(std::make_error_code(std::errc(e)), (std::ostringstream() << __FILE__ "(" _CRT_STRINGIZE(__LINE__) "): In " __FUNCTION__ ", _sopen_s(_FileName = '" << _FileName << "') failed").str());
	else {
		(void)_close(_fileno(stdin));
		const auto new_fd = _dup(fd);
		if (new_fd == -1) {
			e = errno;
			_close(fd);
			throw std::system_error(std::make_error_code(std::errc(e)), (std::ostringstream() << __FILE__ "(" _CRT_STRINGIZE(__LINE__) "): In " __FUNCTION__ ", _dup(fd = " << fd << ") failed").str());
		}
		else {
			assert(new_fd == _fileno(stdin));
			(void)_close(fd);
		}
	}
}
