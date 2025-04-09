#include <windows.h>
#include <stdio.h>

static BOOL My_CopyDirectory(LPCWSTR sourceDir, LPCWSTR destDir, BOOL overwrite = FALSE) {
  if (!sourceDir || !destDir) {
    return false;
  }

  if (!CreateDirectoryW(destDir, NULL)) {
    if (GetLastError() != ERROR_ALREADY_EXISTS) {
      return false;
    }
  }

  WIN32_FIND_DATAW findData;

  WCHAR searchPath[MAX_PATH];
  wcscpy_s(searchPath, sourceDir);
  wcscat_s(searchPath, L"\\*");

  HANDLE handle = FindFirstFileW(searchPath, &findData);
  if (handle == INVALID_HANDLE_VALUE) {
    return false;
  }

  do {
    if (wcscmp(findData.cFileName, L".") == 0 || wcscmp(findData.cFileName, L"..") == 0) {
      continue;
    }

    WCHAR destFilePath[MAX_PATH];
    wcscpy_s(destFilePath, destDir);
    wcscat_s(destFilePath, L"\\");
    wcscat_s(destFilePath, findData.cFileName);

    WCHAR sourceFilePath[MAX_PATH];
    wcscpy_s(sourceFilePath, sourceDir);
    wcscat_s(sourceFilePath, L"\\");
    wcscat_s(sourceFilePath, findData.cFileName);

    if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
      if (!My_CopyDirectory(sourceFilePath, destFilePath, overwrite)) {
        FindClose(handle);
        return FALSE;
      }
    }
    else {
      if (!CopyFileW(sourceFilePath, destFilePath, !overwrite)) {
        int error = GetLastError();
        if (error != ERROR_FILE_EXISTS) {
          printf("Error: %d\n", error);
        }
        FindClose(handle);
        return FALSE;
      }
    }
  } while (FindNextFileW(handle, &findData));

  FindClose(handle);

  return TRUE;
}

BOOL My_GetFileCreationTime(LPCWSTR filePath, FILETIME* creationTime) {
  if (!filePath || !creationTime) {
    return FALSE;
  }

  HANDLE handle = CreateFileW(filePath, GENERIC_READ, FILE_SHARE_READ, NULL,
    OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  if (handle == INVALID_HANDLE_VALUE) {
    return FALSE;
  }

  BOOL success = GetFileTime(handle, creationTime, NULL, NULL);

  CloseHandle(handle);

  return success;
}

BOOL My_HideFile(LPCWSTR filePath) {
  if (!filePath) {
    return FALSE;
  }

  DWORD attributes = GetFileAttributesW(filePath);
  if (attributes == INVALID_FILE_ATTRIBUTES) {
    return FALSE;
  }

  SetFileAttributesW(filePath, attributes | FILE_ATTRIBUTE_HIDDEN);

  return TRUE;
}

BOOL __FileTimeToString(FILETIME* fileTime, LPWSTR isoString, DWORD isoStringSize) {
  if (!fileTime || !isoString) {
    return FALSE;
  }

  SYSTEMTIME systemTime;
  if (!FileTimeToSystemTime(fileTime, &systemTime)) {
    return FALSE;
  }

  if (!GetDateFormatW(LOCALE_USER_DEFAULT, DATE_SHORTDATE, &systemTime, NULL, isoString, isoStringSize)) {
    return FALSE;
  }

  wcscat_s(isoString, isoStringSize, L" ");

  WCHAR timeString[20];
  if (!GetTimeFormatW(LOCALE_USER_DEFAULT, 0, &systemTime, NULL, timeString, 20)) {
    return FALSE;
  }

  wcscat_s(isoString, isoStringSize, timeString);

  return TRUE;
}


int wmain(int argc, wchar_t **argv) {
  if (argc < 2) {
    wprintf(L"Usage: %s <command> [arguments...]\n", argv[0]);
    wprintf(L"Commands:\n");
    wprintf(L"  copy-directory <source directory> <destination directory>\n");
    wprintf(L"  get-file-creation-time <file path>\n");
    wprintf(L"  hide-file <file path>\n");
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    if (!wcscmp(argv[i], L"copy-directory")) {
      wprintf(L"copy-directory...\n");
      if (argc < i + 3) {
        wprintf(L"  Error: Too few arguments\n");
        continue;
      }

      wprintf(L"  Source directory: %s\n", argv[i + 1]);
      wprintf(L"  Destination directory: %s\n", argv[i + 2]);

      if (!My_CopyDirectory((LPCWSTR)argv[i + 1], (LPCWSTR)argv[i + 2], TRUE)) {
        wprintf(L"  Error: Failed to copy directory\n");
      }
      else {
        wprintf(L"  Done\n");
      }
      i+= 2;
    }
    else if (!wcscmp(argv[i], L"get-file-creation-time")) {
      wprintf(L"get-file-creation-time...\n");
      if (argc < i + 2) {
        wprintf(L"  Error: Too few arguments\n");
        continue;
      }

      wprintf(L"  File path: %s\n", argv[i + 1]);

      FILETIME creationTime;
      if (!My_GetFileCreationTime((LPCWSTR)argv[i + 1], &creationTime)) {
        wprintf(L"  Error: Failed to get file creation time\n");
      }
      else {
        WCHAR isoString[64];
        if (__FileTimeToString(&creationTime, isoString, 64)) {
          wprintf(L"  File creation time: %s (UTC)\n", isoString);
        }
        else {
          wprintf(L"  Error: Failed to convert file time to ISO string\n");
        }
      }
      i++;
    }
    else if (!wcscmp(argv[i], L"hide-file")) {
      printf("hide-file...\n");
      if (argc < i + 2) {
        wprintf(L"  Error: Too few arguments\n");
        continue;
      }

      wprintf(L"  File path: %s\n", argv[i + 1]);

      if (!My_HideFile((LPCWSTR)argv[i + 1])) {
        wprintf(L"  Error: Failed to hide file\n");
      }
      else {
        wprintf(L"  Done\n");
      }
      i++;
    }
    else {
      wprintf(L"Unknown command: %s\n", argv[i]);
    }
  }
}