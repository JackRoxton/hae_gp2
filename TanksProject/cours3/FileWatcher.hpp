#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

class FileWatcher {
public:
	struct _stat buf;
	int result = 0;
	char timeBuf[26];
	const char* filename = "res/ui.txt";
	errno_t err;
	__time64_t lastChangeTime = 0;


	bool hasChanged();
};