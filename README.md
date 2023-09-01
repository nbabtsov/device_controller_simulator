# device_controller_simulator
simulation for a device controller interacting with a circular queue, which is used to buffer and manage characters received from or sent to a device controller

## Compile and Run
compile: 
```
nikababtsov@LAPTOP-VGHR5LTP:/mnt/c/Users/Nika/device_controller_simulator$ make
gcc -c echo-driver.c
gcc -c device-controller.h
gcc echo-driver.o -o echo-driver -lm
```

run:
input the number of bytes to be allocated for the circular queue (in this case, 8)
```
nikababtsov@LAPTOP-VGHR5LTP:/mnt/c/Users/Nika/device_controller_simulator$ ./echo-driver 8
Hello, World!
Hello, World!
Hello, WodH, d!
HlWld!
Helo,Wo
l, Wol!el Wor!
llW!He
```

## How It Works (WIP)

### device-controller-simulator

start():
* Simulates interactions with a device controller.
* Contains a loop that simulates the passage of time using usleep and generates random events.
* If a random event occurs, it either sends a character to the device controller using read_interrupt or handles data from the device controller using write_done_interrupt.

write_device():
Simulates writing to a device controller. It sets the value to be written.


### echo-driver
main()
The main function takes a command-line argument, creates a circular queue with the specified capacity, and then calls the start function.

create_queue:

This function is used to create a circular queue with a specified capacity. It allocates memory for the queue, initializes its properties, and returns a pointer to the created queue.
queue_empty and queue_full:

These functions determine if the queue is empty or full, respectively, and return appropriate status codes.
queue_enqueue and queue_dequeue:

These functions are used to add items to the queue (enqueue) and remove items from the queue (dequeue). They return status codes to indicate success or failure.
queue_size:

This function returns the current size of the queue.
free_queue:

This function releases the memory associated with the queue, including the data array and the queue structure itself.
read_interrupt and write_done_interrupt:

These functions simulate interrupt handling for a device controller.
read_interrupt checks if the writer is busy and either writes to the device or enqueues characters in the circular queue.
write_done_interrupt dequeues items from the queue when the writer is done.


