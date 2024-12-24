#pragma once

#include <traceloggingprovider.h>
#include <winmeta.h>

void RecordApplicationStart();
void RecordOnRendered();
void RecordAnimationComplete();
void RegisterTraceLogger();
void RecordLowPriorityTask();
void RecordOnUserControlRendered();