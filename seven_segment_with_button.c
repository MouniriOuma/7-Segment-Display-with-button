const unsigned char digits[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; // Segment codes for 0-9
unsigned char i = 0;

void main() {
    TRISB = 0b10000000;
    PORTB = 0x00;

    while (1) {
        if ((PORTB & 0x80) == 0) {
            Delay_ms(50);
            if ((PORTB & 0x80) == 0) {
                i++;
                if (i > 9) {
                    i = 0;
                }
                PORTB = digits[i];
                while ((PORTB & 0x80) == 0);
            }
        }
    }
}
