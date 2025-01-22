#include <stdio.h>

void decimal_to_binary(int num, int bits, char *signed_mag, char *ones_comp, char *twos_comp)
{
    // Signed Magnitude
    int sign_bit = (num < 0) ? 1 : 0;
    int magnitude = (num < 0) ? -num : num;
    signed_mag[0] = sign_bit ? '1' : '0';
    for (int i = bits - 2; i >= 0; i--)
    {
        int bit = (magnitude >> i) & 1;
        signed_mag[bits - 1 - i] = bit + '0';
    }
    signed_mag[bits] = '\0';

    // One's Complement
    if (num < 0)
    {
        char temp_signed_mag[bits + 1];
        temp_signed_mag[0] = '0';
        for (int i = bits - 2; i >= 0; i--)
        {
            int bit = (magnitude >> i) & 1;
            temp_signed_mag[bits - 1 - i] = bit + '0';
        }
        temp_signed_mag[bits] = '\0';
        for (int i = 0; i < bits; i++)
        {
            ones_comp[i] = (temp_signed_mag[i] == '0') ? '1' : '0';
        }
        ones_comp[bits] = '\0';
    }
    else
    {
        for (int i = 0; i < bits; i++)
        {
            ones_comp[i] = signed_mag[i];
        }
        ones_comp[bits] = '\0';
    }

    // Two's Complement
    unsigned int u = (unsigned int)num;
    for (int i = bits - 1; i >= 0; i--)
    {
        int bit = (u >> i) & 1;
        twos_comp[bits - 1 - i] = bit + '0';
    }
    twos_comp[bits] = '\0';
}

int main()
{
    int bits;
    printf("Enter the number of bits: ");
    scanf("%d", &bits);

    int min_value = -(1 << (bits - 1));
    int max_value = (1 << (bits - 1)) - 1;

    printf("Enter a decimal integer between %d and %d: ", min_value, max_value);
    int num;
    scanf("%d", &num);

    // Validate input range
    if (num < min_value || num > max_value)
    {
        printf("Error: The input is out of range for %d bits.\n", bits);
        return 1;
    }

    char signed_mag[bits + 1];
    char ones_comp[bits + 1];
    char twos_comp[bits + 1];

    decimal_to_binary(num, bits, signed_mag, ones_comp, twos_comp);

    printf("Signed Magnitude: %s\n", signed_mag);
    printf("One's Complement: %s\n", ones_comp);
    printf("Two's Complement: %s\n", twos_comp);

    return 0;
}