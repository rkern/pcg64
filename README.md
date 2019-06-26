# C Implementation of PCG64

* Robert Kern `<robert.kern@gmail.com>`

This is a pure C implementation of the [PCG64](http://www.pcg-random.org/)
member of the PCG family of pseudorandom number generators. 128-bit arithmetic
is emulated when a suitable `uint128_t` type is not available. Settable streams
and jumpahead are implemented.

This is not necessarily production-quality code. It's mostly presented here in
the interest of sharing for others to take on.

## License

Available under either the [Apache v2
license](https://opensource.org/licenses/Apache-2.0) or [MIT license](https://opensource.org/licenses/MIT).

## Todo

* MSVC portability `#ifdef`ery
* Real test vectors verified against upstream
