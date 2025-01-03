#pragma once
#include "pch.h"
#include "trace.h"

#define TRACE_LEVEL_INFORMATION 4

namespace {
    int NumberOfRender = 0;
    bool registered = false;
}

constexpr int64_t MICROSOFT_KEYWORD_MEASURES = 0x0000400000000000;      // Bit 46

TRACELOGGING_DEFINE_PROVIDER(g_NotepadTraceProvider, "Microsoft.NotepadApp",
    (0xa96df2b1, 0xd494, 0x5b42, 0x45, 0x3e, 0xb1, 0x1a, 0x1e, 0xe2, 0xb3,
        0x1b), // Unique providerID {a96df2b1-d494-5b42-453e-b11a1ee2b31b}
    TraceLoggingOptionGroup(0x4f50731a, 0x89cf, 0x4782, 0xb3, 0xe0, 0xdc, 0xe8, 0xc9, 0x4,
        0x76, 0xba));

#define NotepadTraceInfoMeasures(eventName, ...)                                                                       \
    TraceLoggingWrite(g_NotepadTraceProvider, eventName, TraceLoggingLevel(TRACE_LEVEL_INFORMATION),                   \
                      TraceLoggingKeyword(MICROSOFT_KEYWORD_MEASURES));

void RecordApplicationStart() {
    NotepadTraceInfoMeasures("XamlWinUI3.ApplicationStart");
}

void RecordOnRendered() {
    NumberOfRender++;
    if (NumberOfRender == 2)
    {
        NotepadTraceInfoMeasures("XamlWinUI3.OnRendered");
    }
}

void RecordOnUserControlRendered() {
    NotepadTraceInfoMeasures("XamlWinUI3.UserControlOnRendered");
}

void RecordAnimationComplete() {
    NotepadTraceInfoMeasures("XamlWinUI3.AnimationComplete");
    NotepadTraceInfoMeasures("XamlWinUI3.ApplicationClose");
}

void RecordLowPriorityTask() {
    NotepadTraceInfoMeasures("XamlWinUI3.LowPriorityTask");
}

void RegisterTraceLogger() {
    if (!registered) {
        registered = true;
        TraceLoggingRegister(g_NotepadTraceProvider);
    }
}