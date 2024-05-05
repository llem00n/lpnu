#include <Windows.h>
#include <stdio.h>
#define BUFFERLENGTH 832

HANDLE hComm = INVALID_HANDLE_VALUE; // Handle to the Serial port
//char ComPortName[] = "\\\\.\\COM24"; // Name of the Serial port(May Change) to be opened,
char cComPortName[] = "COM5"; // Name of the Serial port(May Change) to be opened,
wchar_t wComPortName[] = L"COM5"; // Name of the Serial port(May Change) to be opened,
BOOL Status;
DCB dcbSerialParams = { 0 }; // Initializing DCB structure
COMMTIMEOUTS timeouts = { 0 };

char lpSendBuffer[BUFFERLENGTH] = { 0 }; // lpSendBuffer should be char or byte array
DWORD dNoOFBytestoWrite; // No of bytes to write into the port
DWORD dNoOfBytesWritten = 0; // No of bytes written to the port

DWORD dwEventMask; // Event mask to trigger
char lpReceiveBuffer[BUFFERLENGTH] = { 0 }; // Buffer Containing Rxed Data
char lpRxBuffer[BUFFERLENGTH] = { 0 }; // Buffer Containing Rxed Data
DWORD NoBytesRead; // Bytes read by ReadFile()
int i, j, n;

int iTime1, iTime2, iTime3, iTime4;

int main()
{
    for (i = 0; i < BUFFERLENGTH; i++) {
        lpSendBuffer[i] = (char)i;
    }
    printf("\n\n +==========================================+");
    printf("\n | Serial Transmission (Win32 API)          |");
    printf("\n +==========================================+\n");
    /*--------------- Opening the Serial Port --------------------------------------------*/
    hComm = ::CreateFile(wComPortName, // Name of the Port to be Opened
        GENERIC_READ | GENERIC_WRITE, // Read/Write Access
        0, // No Sharing, ports can’t be shared
        NULL, // No Security
        OPEN_EXISTING, // Open existing port only
        0, // No Overlapped I/O
        NULL); // Null for Comm Devices
    if (hComm == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND)
        {
            printf("\n\n Error! - Port %s can't be opened", cComPortName);
        }
        else {
            printf("\n\n Error! - invalid handle value!");
        }
        goto l_exit_proc;
    }
    else {
        printf("\n Port %s Opened\n", cComPortName);
    }
    /*---------- - Setting the Parameters for the SerialPort------------------------------*/
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    Status = ::GetCommState(hComm, &dcbSerialParams); //retreives the current settings
    if (Status == FALSE) {
        printf("\n\n Error! in GetCommState()");
        goto l_exit_proc;
    }
    dcbSerialParams.BaudRate = CBR_2400; // baud rate
    dcbSerialParams.ByteSize = 8; // data size, xmit and rcv
    dcbSerialParams.Parity = NOPARITY; // parity bit
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.fBinary = TRUE;
    dcbSerialParams.fDsrSensitivity = false;
    //dcbSerialParams.fParity = fParity;
    dcbSerialParams.fOutX = false;
    dcbSerialParams.fInX = false;
    dcbSerialParams.fNull = false;
    dcbSerialParams.fAbortOnError = TRUE;
    dcbSerialParams.fOutxCtsFlow = FALSE;
    dcbSerialParams.fOutxDsrFlow = false;
    dcbSerialParams.fDtrControl = DTR_CONTROL_DISABLE;
    dcbSerialParams.fDsrSensitivity = false;
    dcbSerialParams.fRtsControl = RTS_CONTROL_DISABLE;
    dcbSerialParams.fOutxCtsFlow = false;
    dcbSerialParams.fOutxCtsFlow = false;
    //Configuring the port according to settings in DCB
    Status = ::SetCommState(hComm, &dcbSerialParams);
    if (Status == FALSE) {
        printf("\n\n Error! in Setting DCB Structure");
        goto l_exit_proc;
    }
    else {
        printf("\n Setting DCB Structure Successfull\n");
        printf("\n Baudrate = %d", dcbSerialParams.BaudRate);
        printf("\n ByteSize = %d", dcbSerialParams.ByteSize);
        printf("\n StopBits = %d", dcbSerialParams.StopBits);
        printf("\n Parity = %d", dcbSerialParams.Parity);
    }
    /*---------------- Setting Timeouts --------------------------------------------------*/
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    if (::SetCommTimeouts(hComm, &timeouts) == FALSE) {
        printf("\n\n Error! in Setting Time Outs");
        goto l_exit_proc;
    }
    else {
        printf("\n\n Setting Serial Port Timeouts Successfull\n");
        printf("\n ReadIntervalTimeout = %d", timeouts.ReadIntervalTimeout);
        printf("\n ReadTotalTimeoutConstant = %d",
            timeouts.ReadTotalTimeoutConstant);
        printf("\n ReadTotalTimeoutMultiplier = %d",
            timeouts.ReadTotalTimeoutMultiplier);
        printf("\n WriteTotalTimeoutConstant = %d",
            timeouts.WriteTotalTimeoutConstant);
        printf("\n WriteTotalTimeoutMultiplier = %d",
            timeouts.WriteTotalTimeoutMultiplier);
    }
    ::PurgeComm(hComm, PURGE_TXCLEAR | PURGE_RXCLEAR);
    /*--------- Writing a Character to Serial Port----------------------------------------*/
    n = 1;
l_loop:;
    printf("\n\n %d pass. ================================================\n", n);
    dNoOFBytestoWrite = sizeof(lpSendBuffer); // Calculating the no of bytes to write into the port
    iTime1 = ::GetTickCount();
    Status = ::WriteFile(hComm, // Handle to the Serialport
        lpSendBuffer, // Data to be written to the port
        dNoOFBytestoWrite, // No of bytes to write into the port
        &dNoOfBytesWritten, // No of bytes written to the port
        0);
    if (Status == TRUE) {
        // WriteFile completed immediately.
        printf("\n %d bytes - Written to %s", dNoOfBytesWritten, cComPortName);
    }
    else {
        printf("\n\n Error %d in Writing to Serial Port", GetLastError());
        goto l_exit_proc;
    }
    /*---------------- Setting Send Mask ------------------------------------------------*/
    Status = ::SetCommMask(hComm, EV_TXEMPTY); //Configure Windows to Monitor the serial device for transmit buffer
    if (Status == FALSE) {
        printf("\n\n Error! in Setting EV_TXEMPTY CommMask");
        goto l_exit_proc;
    }
    //else {
    //printf("\n\n Setting EV_TXEMPTY CommMask successfull");
    //}
    /*---------------- Setting WaitComm() Event ----------------------------------------*/
    printf("\n Waiting for Send Data");
    Status = ::WaitCommEvent(hComm, &dwEventMask, NULL); //Wait for the character to be received
    if (Status == FALSE)
    {
        printf("\n\n Error! in Setting WaitCommEvent()");
        goto l_exit_proc;
    }
    //else //If WaitCommEvent()==True Read the RXed data using ReadFile();
    //{
    //}
    iTime2 = ::GetTickCount();
    printf(" %d miliseconds", iTime2 - iTime1);
    /*---------------- Setting Receive Mask ----------------------------------------------*/
    Status = ::SetCommMask(hComm, EV_RXCHAR); //Configure Windows to Monitor the serial device for Character Reception
    if (Status == FALSE) {
        printf("\n\n Error! in Setting EV_RXCHAR CommMask");
        goto l_exit_proc;
    }
    //else {
    //printf("\n\n Setting EV_RXCHAR CommMask successfull");
    //}
    /*--------------- Setting WaitComm() Event ----------------------------------------*/
    printf("\n Waiting for Data Reception");
    Status = ::WaitCommEvent(hComm, &dwEventMask, NULL); //Wait for the character to be received
    /*------ Program will Wait here till a Character is received ------------------------*/
    if (Status == FALSE) {
        printf("\n\n Error! in Setting WaitCommEvent()");
        goto l_exit_proc;
    } // if (Status == FALSE)
    else {
        iTime3 = ::GetTickCount();
        printf(" %d miliseconds", iTime3 - iTime2);
        i = 0;
        do {
            //Status = ::ReadFile(hComm, lpReceiveBuffer, BUFFERLENGTH, &NoBytesRead,NULL);
            Status = ::ReadFile(hComm, lpReceiveBuffer, 1, &NoBytesRead, NULL);
            if (Status) {
                for (j = 0; j < (int)NoBytesRead; j++) {
                    lpRxBuffer[i++] = lpReceiveBuffer[j];
                }
            }
        } while (NoBytesRead > 0);
        iTime4 = ::GetTickCount();
        printf("\n %d bytes Received from %s.\n\nTotal time is %d miliseconds", i,
            cComPortName, iTime4 - iTime1);
        n++;
        if (n < 10) goto l_loop;
        // if (n < 1024) goto l_loop;
    } // if (Status == FALSE)
l_exit_proc:
    if (hComm != INVALID_HANDLE_VALUE) CloseHandle(hComm); //Closing the Serial Port
    printf("\n ==========================================\n");
    system("pause");
    return 0;


}


