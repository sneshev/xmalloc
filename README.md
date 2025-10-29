# Description
This custom-made library holds various functions to help you keep a registry of all your allocations.
- Free all allocated memory with one function call from anywhere
- No need for NULL checks after allocating
- No risks of double free
- Use xfree() to free any data type and everything it points to
- Easily add custom structs and data types

## Functions in the library
### Allocating memory:
#### xmalloc(size_t nmemb, t_reg_type type)
	Allocates NMEMB elements of XTYPE. Stores it in a registry of all xallocs. Initializes registry if it isn't already.
#### xcalloc(size_t nmemb, t_reg_type type)
	Allocates NMEMB elements of XTYPE. Sets all bytes to 0. Stores entry in a registry of all xallocs. Initializes registry if it isn't already.
### Freeing memory:
#### xfree(void *address)

#### xfree_ptr(void *address)

### Other
#### xfree_registry(void)

#### xexit(int status)
