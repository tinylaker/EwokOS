#include <unistd.h>
#include <pmessage.h>
#include <syscall.h>
#include <stdlib.h>
#include <kstring.h>
#include <kserv/devserv.h>
#include <stdio.h>

void _start() {
	DeviceT dev;
	devInit(&dev);
	devMount(1, "/dev/tty1");

	if(!devServRun("kserv.tty", &dev))
		exit(0);
}