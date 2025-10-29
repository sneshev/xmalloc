# Description
This custom-made library holds various functions to help you keep a registry of all your allocations.
- Free all allocated memory with one function call from anywhere
- No need for NULL checks after allocating
- No risks of double free
- Use xfree() to free any data type and everything it points to
- Easily add custom structs and data types

![valgrind](README_assets/valgrind_image.png)
<p align="center"><i>ℹ️ Allocations that were not made using functions of the library are not kept in the registry</i></p>

## Functions in the library

### Allocating memory:

#### xmalloc(size_t nmemb, t_reg_type type)

<!-- <h3 style="font-weight:normal; color:gray;">What I Learned</h3> -->

<!-- <h4 align="center">xmalloc(size_t nmemb, t_reg_type type)</h4> -->
-> Allocates NMEMB elements of XTYPE. Stores it in a registry of all xallocs. Initializes registry if it isn't already.

<h4 align="center">xcalloc(size_t nmemb, t_reg_type type)</h4>

Allocates NMEMB elements of XTYPE. Sets all bytes to 0. Stores entry in a registry of all xallocs. Initializes registry if it isn't already.

### Freeing memory:

<h4 align="center">xfree(void *address)</h4>
Searches the alloc registry for the entry. Frees its address and any subaddress available. For example, if you pass char **, frees with free_arr(). arrays must be NULL-ed.

<h4 align="center">xfree_ptr(void *address)</h4>
Frees the address and deletes it from the registry. Does not free anything else.

### Other

<h4 align="center">xfree_registry(void)</h4>

Frees whole registry and destroys it

<h4 align="center">xexit(int status)</h4>
Destroys registry and exits with status
