/*
 * Generate signal and write VRT IF data packet to file. Note that this will not generate a big endian-format, i.e.
 * standard conforming, packet on a little endian platform.
 */

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vrt/vrt_init.h>
#include <vrt/vrt_string.h>
#include <vrt/vrt_util.h>
#include <vrt/vrt_write.h>

/* Size of packet in 32-bit words */
#define SIZE 515
/* Sample rate [Hz] */
#define SAMPLE_RATE 44100.0F
/* Center frequency [Hz] */
#define CENTER_FREQUENCY 10000.0F
/* M_PI in math.h is nonstandard :( */
#define PI 3.1415926F

int main() {
    /* Packet data buffer */
    uint32_t b[SIZE];

    /* Generate signal data */
    float s[SIZE - 3];
    for (int i = 0; i < SIZE - 3; ++i) {
        s[i] = sinf(2.0F * PI * CENTER_FREQUENCY * (float)i / SAMPLE_RATE);
    }

    /* Initialize to reasonable values */
    vrt_header  h;
    vrt_fields  f;
    vrt_trailer t;
    vrt_init_header(&h);
    vrt_init_fields(&f);
    vrt_init_trailer(&t);

    /* Configure */
    h.packet_type        = VRT_PT_IF_DATA_WITH_STREAM_ID;
    h.has.trailer        = true;
    h.packet_size        = SIZE;
    f.stream_id          = 0xDEADBEEF;
    t.has.reference_lock = true;
    t.reference_lock     = true;

    /* Write header */
    int32_t offset = 0;
    int32_t rv     = vrt_write_header(&h, b + offset, SIZE - offset, true);
    if (rv < 0) {
        fprintf(stderr, "Failed to write header: %s\n", vrt_string_error(rv));
        return EXIT_FAILURE;
    }
    offset += rv;

    /* Write fields, which in this case is Stream ID */
    rv = vrt_write_fields(&h, &f, b + offset, SIZE - offset, true);
    if (rv < 0) {
        fprintf(stderr, "Failed to write fields section: %s\n", vrt_string_error(rv));
        return EXIT_FAILURE;
    }
    offset += rv;

    /* Copy signal data from signal to packet buffer.
     * This could also have been written directly into the buffer. */
    memcpy(b + offset, s, sizeof(float) * (SIZE - 3));
    offset += SIZE - 3;

    /* Write trailer */
    rv = vrt_write_trailer(&t, b + offset, SIZE - offset, true);
    if (rv < 0) {
        fprintf(stderr, "Failed to write trailer: %s\n", vrt_string_error(rv));
        return EXIT_FAILURE;
    }

    /* Write generated packet to file */
    FILE* fp = fopen("signal.vrt", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file\n");
        return EXIT_FAILURE;
    }
    if (fwrite(b, sizeof(uint32_t) * SIZE, 1, fp) != 1) {
        fprintf(stderr, "Failed to write to file\n");
        fclose(fp);
        return EXIT_FAILURE;
    }
    fclose(fp);

    /* Warn if not standards compliant */
    if (vrt_is_platform_little_endian()) {
        fprintf(stderr, "Warning: Written packet is little endian. It is NOT compliant with the VRT standard.\n");
    }

    return EXIT_SUCCESS;
}
