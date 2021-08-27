# ft_printf

*This project is part of the official curriculum at [School 42](https://en.wikipedia.org/wiki/42_(school)).*

## Disclaimer
> In [School 42](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written to comply with. coding standard (also known as the "[Norm](./docs/subjects/norme.en.pdf)"). As a result, the implementation of certain parts may appear strange.


## Overview


* [Official instructions](docs/subjects/ft_printf.en.pdf)
* [Module documentation](https://almayor.github.io/ft_printf/)
* The goal of this project is to practice the following concepts
	* variadic functions
	* dispatch tables – loose coupling and performance
	* void pointers – generic programming
	* optimization patterns – buffering
* Only the following functions are allowed
    * `write`
    * `malloc`
    * `free`
    * `exit`
    * functions of `stdarg`
* The project (with the exception of tests) is consistent with the [Norme](docs/subjects/norme.en.pdf), the code standard accepted at *School 42*. In particular, this means that
	* no comments inline or inside functions
	* `for` loops and `switch` statements are forbidden
	* each function must be maximum 25 lines
	* no functional macros
* As per instructions, the project is realised using `libft` written in a previous [project](http://github.com/almayor/libft).

## Checklist

**_Standard_**

- [x] `csp%` conversions
- [x] `diouxX` conversions with `hh`, `h`, `l`, `ll` flags
- [x] `f` conversion with flags `L`, `l`
- [x] `#0-+ ` flag management (when applicable)
- [x] minimum field-width
- [x] precision
- [x] `*` flag management

**_Extra_**

- [x] `b` conversion to print in binary
- [x] variants of `printf`
	* `ft_dprintf`
	* `ft_vprintf`
	* `ft_vdprintf`
	* `ft_sprintf`
	* `ft_snprintf`
	* `ft_vsprintf`
	* `ft_vsnprintf`
	* `ft_asprintf`
	* `ft_vasprintf`
- [x] colors
	* `ft_printf("{red} Color-print.{eoc} Normal print.")`
	* red, blue, yellow, green, cyan, magenta

## Tests

Run tests with `make test`

* Behaviour is tested with [Unity](https://github.com/ThrowTheSwitch/Unity)
* Performance is benchmarked against `printf(3)` 

## Acknowledgements

Many of the included tests are borrowed from [pft](https://github.com/gavinfielder/pft) by [gavinfielder](https://github.com/gavinfielder) and other contributors and [Moulitest](https://github.com/yyang42/moulitest) by [yyang42](https://github.com/yyang42) and other contributors. My thanks go to them.

---
If you have any questions, please contact me on Github.
