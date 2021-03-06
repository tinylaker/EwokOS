#ifndef PROTO_H
#define PROTO_H

#include "types.h"
#include "kstring.h"

#define PROTO_BUFFER 128

typedef struct {
	void *data;
	uint32_t size;
	uint32_t totalSize;
	uint32_t offset;
	bool readOnly;
}ProtoT;

void protoInit(ProtoT* proto, void* data, uint32_t size);

ProtoT* protoNew(void* data, uint32_t size);

void protoAdd(ProtoT* proto, void* item, uint32_t size);

void protoAddInt(ProtoT* proto, int32_t v);

void protoAddStr(ProtoT* proto, const char* v);

void* protoRead(ProtoT* proto, uint32_t *size);

int32_t protoReadInt(ProtoT* proto);

const char* protoReadStr(ProtoT* proto);

void protoClear(ProtoT* proto);

void protoFree(ProtoT* proto);

#endif
