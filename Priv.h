#pragma once

#include <windows.h>

class CEnablePriv
{
public:  // Public (externally accessible) interfaces

	//
	// Set the current process priority to the highest (real-time)
	//
	BOOL SetRealTimePriority();

	//
	// Elevate current process privileges ("SeShutdownPrivilege" shutdown privilege)
	//
	BOOL EnableShutdownPriv();

	//
	// Elevate current process privileges ("SeDebugPrivilege" read and write control privilege)
	//
	BOOL EnableDebugPriv();

	//
	// Elevate current process privileges ("SeBackupPrivilege" registry backup privilege)
	//
	BOOL EnableBackupPriv();

	//
	// Elevate current process privileges ("SeRestorePrivilege" restore data privilege)
	//
	BOOL EnableRestorePriv();

private:  // Private (internally used) interfaces

};
