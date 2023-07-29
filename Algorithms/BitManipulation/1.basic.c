

int setKthBit(int num, int position){
    int mask = 1 << position; // mask will have '1' at the position to be set and '0's in every other bits.
    return num | mask; // either '0' or '1' 'or'ed with '1' will output 1. so the return will have 1 at that position.
                        // 'or' ing with '0' does not make any change, so the other bits are preserved.
}

int clearKthBit(int num, int position){
    int mask = 1 << position;  // the complement of this mask will have '0' at the position and '1's in every other bits.
    return (num & ~mask);   // 'and' ing with '0' outputs '0'. so the return will have '0' at the position.
                            // 'and' ing with '1' does not make any change, so the other bits are preserved.
}

int filpKthBit(int num, int position){
    int mask = 1 << position;   // mask will have '1' at the position to be set and '0's in every other bits.
    return (num ^ mask); // if num[position] == 0, 0^1 = 1.     if num[position] == 1, 1^1 = 0.  Thus flipped.
    // 'xor' ing with '0' preserves the other bits.
}

int isKthBitSet(int num, int position){
    int shifted = num >> position; // The bit to be checked is int the right most bit of 'shifted'
    return shifted & 1; // 0 & 1 = 0, 1 & 1 = 1; 
}

int modifyBit(int num, int position, int state){
    int mask = 1 << position; // mask will have '1' at the postion to be modified and '0's in every other positon.
    int comp_mask = ~mask; // 'comp_mask' is the 1's complement of the mask. It has '0' at the position to be modified and '1's in every other position
    
    int cleared_num = num & comp_mask; // To modify a bit, we first need to clear that bit. use 'clearKthBit' algorithm  to clear the bit at position

    int neg_state = -state; // 'neg_state' is the 2's complement of given state. -1 = 0b1111..11, -0 = 0b000...00

    int newMask = neg_state & mask; // if 'state' was '1'. newMask = 0b111...111 & 000...1...000 = 0b000...1...000 ('1' at postion)
                                   // if 'state' was '0'. newMask = 0b000...000 & 000...1...000 = 0b000...0...000 ('0' at position)

    return cleared_num | newMask; // Since bit at position is '0' in cleared bit, the return will have bit at postion according to 'newMask

}