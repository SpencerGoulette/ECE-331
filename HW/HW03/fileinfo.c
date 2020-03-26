#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

void fileinfo(char file[]);

int main(int argc, char *argv[])
{
	if(argc == 2) {
		fileinfo(argv[1]);
	}
	else {
		printf("Usage: ./fileinfo (Filename)\n");
	}
}

void fileinfo(char file[])
{
	struct stat sfile;
	if (stat(file, &sfile) == -1) {
		printf("Error reading file info!\n");
	}
	
	printf("\nFile Type\n");	
	printf(S_ISBLK(sfile.st_mode)?"Block Special File":"");
	printf(S_ISCHR(sfile.st_mode)?"Character Special File":"");
	printf(S_ISDIR(sfile.st_mode)?"Directory":"");
	printf(S_ISFIFO(sfile.st_mode)?"Pipe or FIFO Special File":"");
	printf(S_ISREG(sfile.st_mode)?"Regular File":"");
	printf(S_ISLNK(sfile.st_mode)?"Symbolic Link":"");
	printf("\n");

	printf("\nFile Permissions User\n");
	printf((sfile.st_mode & S_IRUSR)? "r":"-");
	printf((sfile.st_mode & S_IWUSR)? "w":"-");
	printf((sfile.st_mode & S_IXUSR)? "x":"-");
	printf("\n");
	printf("\nFile Permissions Group\n");
	printf((sfile.st_mode & S_IRGRP)? "r":"-");
	printf((sfile.st_mode & S_IWGRP)? "w":"-");
	printf((sfile.st_mode & S_IXGRP)? "x":"-");
	printf("\n");
	printf("\nFile Permissions Other\n");
	printf((sfile.st_mode & S_IROTH)? "r":"-");
	printf((sfile.st_mode & S_IWOTH)? "w":"-");
	printf((sfile.st_mode & S_IXOTH)? "x":"-");
	printf("\n");

	printf("\nPermissions\n");
	printf(S_ISBLK(sfile.st_mode)?"b":"");
	printf(S_ISCHR(sfile.st_mode)?"c":"");
	printf(S_ISDIR(sfile.st_mode)?"d":"");
	printf(S_ISFIFO(sfile.st_mode)?"p":"");
	printf(S_ISREG(sfile.st_mode)?"-":"");
	printf(S_ISLNK(sfile.st_mode)?"l":"");
	printf((sfile.st_mode & S_IRUSR)? "r":"-");
	printf((sfile.st_mode & S_IWUSR)? "w":"-");
	printf((sfile.st_mode & S_IXUSR)? "x":"-");
	printf((sfile.st_mode & S_IRGRP)? "r":"-");
	printf((sfile.st_mode & S_IWGRP)? "w":"-");
	printf((sfile.st_mode & S_IXGRP)? "x":"-");
	printf((sfile.st_mode & S_IROTH)? "r":"-");
	printf((sfile.st_mode & S_IWOTH)? "w":"-");
	printf((sfile.st_mode & S_IXOTH)? "x":"-");
	printf("\n");

	return;
}
