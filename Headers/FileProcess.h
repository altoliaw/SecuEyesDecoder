#pragma once
/** @file FileProcess.h
 * The file access
 *
 * @author Nick, Liao
 * @date 2025/07/09
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct FileProcess FileProcess;

struct FileProcess {
	int reservedDescriptor; // The reserved descriptor
	int currentDescriptor; // The current descriptor
	char (*pf_executeFile)(FileProcess*, int, const char*, void (*)(char*, int), char*); // The pointer to the function where executes the contents by using the suitable descriptor
	int (*pf_recoverDescriptor)(FileProcess*); // The pointer to the function where changes the stderr descriptor to original
};

void FileProcess_Construct(FileProcess*);
void FileProcess_Destruct(FileProcess*);