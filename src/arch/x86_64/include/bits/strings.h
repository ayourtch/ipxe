#ifndef _BITS_STRINGS_H
#define _BITS_STRINGS_H

FILE_LICENCE ( GPL2_OR_LATER );

/**
 * Find last (i.e. most significant) set bit
 *
 * @v value		Value
 * @ret msb		Most significant bit set in value (LSB=1), or zero
 */
static inline __attribute__ (( always_inline )) int __flsll ( long long value ){
	long long msb_minus_one;

	/* If the input value is zero, the BSR instruction returns
	 * ZF=1 and leaves an undefined value in the output register.
	 * Perform this check in C rather than asm so that it can be
	 * omitted in cases where the compiler is able to prove that
	 * the input is non-zero.
	 */
	if ( value ) {
		__asm__ ( "bsrq %1, %0"
			  : "=r" ( msb_minus_one )
			  : "rm" ( value ) );
		return ( msb_minus_one + 1 );
	} else {
		return 0;
	}
}

/**
 * Find last (i.e. most significant) set bit
 *
 * @v value		Value
 * @ret msb		Most significant bit set in value (LSB=1), or zero
 */
static inline __attribute__ (( always_inline )) int __flsl ( long value ) {

	return __flsll ( value );
}

#endif /* _BITS_STRINGS_H */
