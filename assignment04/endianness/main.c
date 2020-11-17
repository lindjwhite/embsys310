
#define TEST_INTEGER  0x0A0B0C0D
#define LITTLE_END    (TEST_INTEGER & 0x0FF)

typedef enum {
    LITTLE_ENDIAN = 0,
    BIG_ENDIAN,
    UNKNOWN_ENDIAN
}EndianTypesEnum;

EndianTypesEnum check_system_endianness() {
    int test_integer = TEST_INTEGER;
    char *test_ptr = (char *)&test_integer;
    
    if (*test_ptr == LITTLE_END) {
        return LITTLE_ENDIAN;
    } else if (*(test_ptr+3) == LITTLE_END) {
        return BIG_ENDIAN;
    } else {
        return UNKNOWN_ENDIAN;
    }
}

int main()
{
    EndianTypesEnum system_endianness = check_system_endianness();
  return 0;
}
