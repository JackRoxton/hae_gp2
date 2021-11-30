#include "pch.h"
#include "FileWatcher.hpp"

bool FileWatcher::hasChanged() {
	result = _stat(filename, &buf);
	if (result != 0) {
		//printf("res error");
		return false;
	}
	err = ctime_s(timeBuf, 26, &buf.st_mtime);
	if (err) {
		//printf("err error");
		return false;
	}


	//printf("%s\n", timeBuf);
	if (buf.st_mtime != lastChangeTime) {
		lastChangeTime = buf.st_mtime;
		//printf("true");
		return true;
	}
	//printf("false");
	return false;
}