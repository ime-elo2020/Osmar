#include "utils/commandline.h"

extern CommandLine cmdline;


uint16_t cmd_name(uint16_t argc, uint8_t *argv8[]){
	const char **argv=(const char **)argv8;
	uint16_t size=0;
	char* buffer=(char*)argv[0];

	if(argc==1){
		size+=sprintf(buffer+size, "OSMAR MUDOU ESSE CODIGO!\r\n");
	} else {
		size+=sprintf(buffer+size, "Comando errado\r\n");
	}
	return size;
}

CommandLine cmdline({"name"},
					{cmd_name});
