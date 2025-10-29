# Description
This custom-made library holds various functions to help you keep a registry of all your allocations.
- Free all allocated memory with one function call from anywhere
- No need for NULL checks after allocating
- No risks of double free
- Use xfree() to free any data type and everything it points to
- Easily add custom structs and data types

## Available functions
### Allocating memory:
#### xmalloc(size_t nmemb, t_reg_type type)

#### xcalloc(size_t nmemb, t_reg_type type)

### Freeing memory:
#### xfree(void *address)

#### xfree_ptr(void *address)

### Other
#### xfree_registry(void)

#### xexit(int status)
