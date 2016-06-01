/* Use typedef to create types named Int8, Int16, and Int32. 
 * define the types so that they represent 8-bit, 16-bit, and 32-bit
 * integers on your machine.
 */

#include <stdio.h>
#include <stdint.h>

int main(void) {
    typedef char Int8;      // int8_t would also work
    typedef int16_t Int16;
    typedef int32_t Int32;

    // have to multiply sizeof result by 8 to convert bytes to bits
    printf("Int8 is %lu, Int16 is %lu, and Int32 is %lu\n",
            sizeof(Int8) * 8, sizeof(Int16) * 8, sizeof(Int32) * 8);

    return 0;
}
