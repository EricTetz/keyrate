#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

BOOL parseDword(const char* in, DWORD* out)
{
    char* end;
    long result = strtol(in, &end, 10);
    BOOL success = (errno == 0 && end != in);
    if (success)
    {
        *out = result;
    }
    return success;
}

int main(int argc, char* argv[])
{

    FILTERKEYS keys = { sizeof(FILTERKEYS) };

    if (argc == 3
        && parseDword(argv[1], &keys.iDelayMSec)
        && parseDword(argv[2], &keys.iRepeatMSec))
    {
        printf("Setting keyrate: delay: %d, rate: %d\n", (int) keys.iDelayMSec, (int) keys.iRepeatMSec);
        keys.dwFlags = FKF_FILTERKEYSON|FKF_AVAILABLE;
    }
    else if (argc == 1)
    {
        puts ("No parameters given: disabling.");
    }
    else
    {
        puts ("Usage: keyrate <delay ms> <repeat ms>\nCall with no parameters to disable.");
        return 0;
    }

    if (!SystemParametersInfo (SPI_SETFILTERKEYS, 0, (LPVOID) &keys, 0))
    {
        fprintf (stderr, "System call failed.\nUnable to set keyrate.");
    }

    return 0;
}
