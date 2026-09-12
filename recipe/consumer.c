#include <aws/checksums/crc.h>
#include <stdio.h>

int main(void) {
    const uint8_t data[] = "123456789";
    if (aws_checksums_crc32(data, 9, 0) != 0xcbf43926U) return 1;
    if (aws_checksums_crc32c(data, 9, 0) != 0xe3069283U) return 2;
    uint32_t partial = aws_checksums_crc32(data, 4, 0);
    if (aws_checksums_crc32(data + 4, 5, partial) != 0xcbf43926U) return 3;
    partial = aws_checksums_crc32c(data, 4, 0);
    if (aws_checksums_crc32c(data + 4, 5, partial) != 0xe3069283U) return 4;
    puts("Installed CRC32/CRC32C known-answer and incremental checks passed");
    return 0;
}
