/* Standard library API */
#include <unistd.h>

/* Device API */
#include "stm32l476xx.h"


/**
 * This function writes up to nbyte bytes from the buffer pointed to by buf to 
 * the file referenced by the file descriptor fd.
 * 
 * @param fd    File descriptor of the file to write to
 * @param buf   Buffer from which the bytes are to be written
 * @param nbyte Number of bytes to be written
 * 
 * @note Since this is implemented for a bare metal environment, the file
 *       descriptor is ignored and the bytes are transmitted through USART2.
 * 
 * @return The number of bytes written
 */
int _write(int fd, const char *buf, int nbyte) {
    int nwritten = 0;
    const char *curr = buf;

    while ( nwritten < nbyte ) {
        // Block until USART2 transmitter is ready
        while ( (USART2->ISR & USART_ISR_TXE_Msk) != USART_ISR_TXE_Msk ) {}

        // Transmit one byte at a time
        USART2->TDR = *curr;
        curr++;
        nwritten++;
    }

    return nwritten;
}
