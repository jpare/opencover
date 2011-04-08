#include "..\schema\opencover.profiler.xsd.h"
#pragma once

/// <summary>Handles communication back to the profiler host</summary>
/// <remarks>Currently this is handled by using the WebServices API</remarks>
class ProfilerCommunication
{
private:
    int _port;

    void Initialise();
    void Cleanup();
    void PrintError(HRESULT errorCode, WS_ERROR* error);
    WS_ERROR* error;
    WS_HEAP* heap;
    WS_SERVICE_PROXY* proxy;


public:
    ProfilerCommunication(int port);
    ~ProfilerCommunication(void);

public:
    void Start();
    void Stop();
    BOOL TrackAssembly(WCHAR* pModuleName, WCHAR* pAssemblyName);
    BOOL GetSequencePoints(mdToken functionToken, WCHAR* pModuleName, unsigned int* pNumPoints, InstrumentPoint*** pppInstrumentPoints);
};
