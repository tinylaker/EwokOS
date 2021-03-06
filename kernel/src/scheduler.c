#include <proc.h>
#include <timer.h>
#include <irq.h>
#include <hardware.h>

static int roundRobinIndex;

void schedule(void)
{
	ProcessT *proc;
	proc = NULL;
	for (int i = 0; i < PROCESS_COUNT_MAX; i++) {
		proc = &_processTable[roundRobinIndex];

		roundRobinIndex++;
		if (roundRobinIndex == PROCESS_COUNT_MAX) {
			roundRobinIndex = 0;
		}

		if (proc->state == READY) {
			if(_currentProcess != proc) {
				_currentProcess = proc;
				procStart(proc);
			}
			else {
				return;
			}
		}
	}

	/* no process? DEAD!!! */
	while(1);
}

void handleTimer(void)
{
	timerClearInterrupt();
	schedule();
}

#define SCHEDULE_TIME 10 /*0.01 sec*/

void schedulerInit(void)
{
	roundRobinIndex = 0;
	timerSetInterval(SCHEDULE_TIME);
	registerInterruptHandler(getTimerIrq(), handleTimer);
}

