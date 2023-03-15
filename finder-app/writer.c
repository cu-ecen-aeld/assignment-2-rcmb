#include <stdio.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char* argv[]) {
	
	openlog(NULL,0,LOG_USER);

	if(argc !=3) {
		printf("Usage : %s <directory\\file> <string>\n",argv[0]);
		syslog(LOG_ERR,"Invalid number of arguments: %d",argc);
	}

	syslog(LOG_INFO,"Writing %s to %s",argv[2],argv[1]);

	FILE *file;
        file = fopen(argv[1],"w");
	if(file) {
		fprintf(file,"%s\n",argv[2]);
		fclose(file);
	} else {
		printf("Error creating file %s: %s\n",argv[2],strerror(errno));
		syslog(LOG_ERR,"Error creating file %s: %s",argv[2],strerror(errno));
	}

	closelog();

	return 0;
}
