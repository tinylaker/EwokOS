#ifndef SYSTEM_H
#define SYSTEM_H

#include <types.h>

void __setTranslationTableBase(uint32_t v);
void __switchToContext(int *context);

void cli(); //disable interrupts
void sti(); //enable interrupts

#endif

