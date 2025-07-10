#include "../Headers/FileProcess.h"

static char executeFile(FileProcess*, int, const char*, void (*)(char*, int), char*);
static int recoverDescriptor(FileProcess*);

void FileProcess_Construct(FileProcess* object) {
	object->reservedDescriptor = -1;
	object->currentDescriptor = -1;
	object->pf_executeFile = executeFile;
	object->pf_recoverDescriptor = recoverDescriptor;
}

void FileProcess_Destruct(FileProcess* object) {
	object->pf_recoverDescriptor(object);
	object->reservedDescriptor = -1;
	object->currentDescriptor = -1;
	object->pf_recoverDescriptor = NULL;
	object->pf_executeFile = NULL;
}

static char executeFile(FileProcess* object, int currentDescriptor, const char* fileName, void (*executedFunction)(char*, int), char* string) {
	if (object->reservedDescriptor != currentDescriptor) {
		object->currentDescriptor = currentDescriptor;
		object->reservedDescriptor = dup(currentDescriptor);
		if (object->reservedDescriptor == -1) {
			fprintf(stderr, "Function Dup Error!\n");
			return 0x0;
		}
	}

	int fileFileDescriptor = open(fileName, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fileFileDescriptor == -1) {
        fprintf(stderr, "File Opened Error!\n");
        close(object->reservedDescriptor);
		object->reservedDescriptor = -1;
        return 0x0;
    }

	if (dup2(fileFileDescriptor, currentDescriptor) == -1) {
		fprintf(stderr, "Function Dup2 Error!\n");
        close(fileFileDescriptor);
        close(object->reservedDescriptor);
		fileFileDescriptor = -1;
		object->reservedDescriptor = -1;
        return 0x0;
    }

	close(fileFileDescriptor);
	fileFileDescriptor = -1;

	executedFunction(string, currentDescriptor);
	return 0x1;
}
static int recoverDescriptor(FileProcess* object) {
	if (object->reservedDescriptor != -1) {
		if (dup2(object->reservedDescriptor, object->currentDescriptor) == -1) {
			fprintf(stderr, "Function Dup2 Error!\n");
			close(object->reservedDescriptor);
			object->reservedDescriptor = -1;
			return 0;
		} else {
			close(object->reservedDescriptor);
			object->reservedDescriptor = -1;
		}
	}
	return 1;
}