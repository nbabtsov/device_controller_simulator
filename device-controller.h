#ifndef DEVICE_CONTROLLER_H
#define DEVICE_CONTROLLER_H

/* You must implement this function.
 * The device controller is informing you 1 byte has been read.
 * c contains the byte */
void read_interrupt(int c);
/* You must implement this function.
 * The device controller is informing you 1 byte has been written, as requested. */
void write_done_interrupt();

/* The device controller implements this function.
 * Call it to start the device controller.
 */
void start();
/* The device controller implements this function.
 * Call it to write one byte to the device controller.
 */
void write_device(int c);

#endif // DEVICE_CONTROLLER_H
