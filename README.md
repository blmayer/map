# map

> A simple map implementation in C that only costs 24 bytes per node.
It uses linked lists under the hood and its performance, time and memmory,
is proportional to the length of the object's key.


## Usage

Import the library in your `.c` file with the directive `#import <map.h>`. Now
you have access to the `map` type, which will be used to store and retrieve
data, using the `add` and `get` functions respectively.

After using your map you must free it to avoid leaks, for that use the
`destroy` function passing a pointer to your map.


### Example

```{c}
/* Create the map structure */
map m;

/* Initialize it */
init(&m);

/* Now you can add strings to it */
int ret = add(&m, "abc", "this is test data abc");
if (!ret) {
    printf("Error: add returned %d\n", ret);
    exit(1);
}

/* To retrieve data back use the get function */
char *data = get(&m, "abc");
puts(data);

/* Lastly, destroy the map */
int count = destroy(&m);
printf("map freed %d allocations.\n", count);

```


## Building

Type `make` on the command line.


## Installing

Type `sudo make install` on the command line.


## Testing

Type `make test` on the command line, if any *ERROR* appears on the terminal
you should not install it yet.


## Contributing

Yes please!
