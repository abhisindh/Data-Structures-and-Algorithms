#include <stdint.h>

int extractBitField(int num, int start, int len){ // Extract bit field of length 'len', starting from 'start' position from the right.
    int shifted = num >> start; // The rightmost 'len' bits of shifted is the required field
    int mask = 1<<len; // mask = 0b000...10000 (Mask has '1' at the bit just left to the required field bit, others are zero)
    mask--; //mask = 0b000...01111 (Mask has '1' at required field bits, other bits are '0')
    return shifted & mask; // output will have all '0' to left of  required field and field bits of 'shifted' are preserved.
}

int setBitField(int num, int start, int len, int field){
    int mask = 1<<len;
    mask--; // Mask at '1' at 'len' number of bits in right
    mask <<= start; // The '1' bits are shifted to the required field bits.
    
    int cleared_num = num & ~mask; // The required field bits of num are cleared, using complement of mask (similar to clearKthBit algorithm)
    int shifted_field = field << start; // The field is shifted to the bits that need to be changed

    return cleared_num | shifted_field; // The cleared bits of 'num' are modified according to 'shifted_field' other bits are preserved. (similar to modifyBit algorithm)
}

void noTempSwap(int* x, int* y){ // Swap values at pointers x and y without using a temporary variable
    // Let X be the value at pointer x and Y be the value at pointer y AT ANY STEP
    // Let A be the value at pointer x ans B be the value at pointer y INITAILLY
    *x = *x ^ *y; // Now X has '0' where bits of A and B were same, and '1' where bits of A and B were different. Now X is used as a mask.
    *y = *y ^ *x; // The bits that were different in A and B, ('1's in mask) are flipped in Y. (Reason for flip : 0^1 = 1, 1^1 = 0).Thus Y = A
    *x = *y ^ *x; // Now Y has the initial value of X ( =A). Using the above logic, bits need to be flipped are flipped in A and assigned to X
}

int noBranchMinimum(int x, int y){ // Return minimum of x and y without branching
    int check = -(x<y); // if x<y, check = 0b111...111 . else check = 0b000...000
    int to_be_xored = (x^y) & check; //if x<y, t_b_x = x^y ('and' with '1' preserves bits)
                                     //Otherwise t_b_x = 0b000...000  ('and' with '0' = '0')

    return y^to_be_xored; // if y is minimum, output = y^0b000...000 . output = y (Since 'xor' with '0' preserves bits)
                          // if x is minimum, output = y^(x^y)       . output = x (Since y^x^y = (y^y)^x = 0^x = x)
}

uint64_t roundUptoPowerOfTwo(uint64_t num){ // Round given 64-bit unsigned integer to its closest power of two.
    num--; // decrementing num by 1. if num was ...0001000...000 initially, now num = ...0000111...111 (Flipped all bits to the right of least significant '1' (including itself))
    num |= num >>1; // 0b0100100100 -> 0b0110110110 (copies '1's to next right bits)
    num |= num >>2; // 0b0100010001 -> 0b0101010101 (copies '1's to subsequent right bits)
    num |= num >>4; // 0b0100001000 -> 0b01001001001 (copies '1's to third right bits)
    num |= num >>8; // ...
    num |= num >>16; // ...
    num |= num >>32; // ...
    num |= num >>64; // After this step, num will be of the form 0b000...111
                    // Each step above copies the '1's in num to their right bits according to the shift.
    return num++; // Reverse the initial decrementation. 
}

