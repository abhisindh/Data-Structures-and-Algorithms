

int checkIfEven(int num){ // Idea : even iff rightmost bit is 0, else odd.
    int check = num & 1; // if rightmost bit of num is '1' , check = 0b000...1 . else check = 0b0000...0;
    return !check; // if check == 0b000...0, return = 0. else return = 1
}

int checkIfPowTwo(int num){ // Check if the given number is power of two or not
    // Idea : Power of twos will only have single '1' bit in its binary representation.
    int mask = num - 1; // if num = 0b0...10000 = 0b0...01111 (flips the rightmost '1' to '0' and flips all the bits to its right to '1'. The bits to left are preserved)
    int check = num & mask; // if 'num' is power of 2, check = 0 , since all bits of mask are flipped from that of num
                           // if 'num' is not a power of 2, it will have '1'(s) to the left of flipped '1' , and the same will be present in the mask thus check != 0
    return !check; // return 1 if check == 0, return 0 otherwise.
}

int modularAddition(int x, int y, int n){ // return (x+y)mod n. Assuming 0 <= x < n and 0 <= y < n 
    int z = x+y; // z is the normal (without mod) sum of x and y
    int check = -(z >= n); // If z >= n, check = 0b111...111 else check = 0b000...000
    int to_be_subracted = n & check; // t_b_s = n , if check = 0b111...111. otherwise t_b_s = 0
    return z - to_be_subracted; // n is subracted from z iff it is greater than or equal to n.
}

int leastSignificantOne(int num){ // compute a mask where bit of least significant '1' is '1' and other bits are zero
    int neg_num = -num; // All bits are flipped, except the bit of least signiftant '1'
    return num & neg_num; // Only bit of least significant '1' has '1' others are turned to zero;
}