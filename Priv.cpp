#include "Priv.h"

BOOL CEnablePriv::SetRealTimePriority()
{
	if (!SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS))
	{
		return false;
	}

	return true;
}

//
// Elevate current process privileges function ("SeShutdownPrivilege" shutdown privilege)
//
// Returns: "false" on failure, "true" on success.
BOOL CEnablePriv::EnableShutdownPriv()
{
	HANDLE hToken;
	LUID shutdownPrivilegeValue;
	TOKEN_PRIVILEGES tkp;

	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return false;

	if (!LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &shutdownPrivilegeValue))
	{
		CloseHandle(hToken);
		return false;
	}

	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = shutdownPrivilegeValue;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof tkp, NULL, NULL))
		CloseHandle(hToken);

	return true;
}

//
// Elevate current process privileges function ("SeDebugPrivilege" read, write control privilege)
//
// Returns: "false" on failure, "true" on success.
BOOL CEnablePriv::EnableDebugPriv()
{
	HANDLE hToken;
	LUID debugPrivilegeValue;
	TOKEN_PRIVILEGES tkp;

	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return false;

	if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &debugPrivilegeValue))
	{
		CloseHandle(hToken);
		return false;
	}

	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = debugPrivilegeValue;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof tkp, NULL, NULL))
		CloseHandle(hToken);

	return true;
}

//
// Elevate current process privileges function ("SeBackupPrivilege" backup data privilege)
//
// Returns: "false" on failure, "true" on success.
BOOL CEnablePriv::EnableBackupPriv()
{
	HANDLE hToken;
	LUID backupPrivilegeValue;
	TOKEN_PRIVILEGES tkp;

	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return false;

	if (!LookupPrivilegeValue(NULL, SE_BACKUP_NAME, &backupPrivilegeValue))
	{
		CloseHandle(hToken);
		return false;
	}

	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = backupPrivilegeValue;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof tkp, NULL, NULL))
		CloseHandle(hToken);

	return true;
}

//
// Elevate current process privileges function ("SeRestorePrivilege" restore data privilege)
//
// Returns: "false" on failure, "true" on success.
BOOL CEnablePriv::EnableRestorePriv()
{
	HANDLE hToken;
	LUID restorePrivilegeValue;
	TOKEN_PRIVILEGES tkp;

	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return false;

	if (!LookupPrivilegeValue(NULL, SE_RESTORE_NAME, &restorePrivilegeValue))
	{
		CloseHandle(hToken);
		return false;
	}

	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = restorePrivilegeValue;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof tkp, NULL, NULL))
		CloseHandle(hToken);

	return true;
}
