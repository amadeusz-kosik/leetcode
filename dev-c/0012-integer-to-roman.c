size_t _write(size_t write_index, char* output, char c1, char c5, char c10, short n) {
    switch(n) {
        case 0: 
            break;

        case 1:
            output[write_index ++] = c1;
            break;

        case 2:
            output[write_index ++] = c1;
            output[write_index ++] = c1;
            break;

        case 3:
            output[write_index ++] = c1;
            output[write_index ++] = c1;
            output[write_index ++] = c1;
            break;

        case 4:
            output[write_index ++] = c1;
            output[write_index ++] = c5;
            break;

        case 5:
            output[write_index ++] = c5;
            break;

        case 6:
            output[write_index ++] = c5;
            output[write_index ++] = c1;
            break;

        case 7:
            output[write_index ++] = c5;
            output[write_index ++] = c1;
            output[write_index ++] = c1;
            break;

        case 8:
            output[write_index ++] = c5;
            output[write_index ++] = c1;
            output[write_index ++] = c1;
            output[write_index ++] = c1;
            break;

        case 9:
            output[write_index ++] = c1;
            output[write_index ++] = c10;
            break;

    }

    return write_index;
}

char* intToRoman(const int num) {
    char* result = (char*) malloc(16 * sizeof(char));
    size_t write_index = 0;

    write_index = _write(write_index, result, 'M', ' ', ' ', (short) (num / 1000)       );
    write_index = _write(write_index, result, 'C', 'D', 'M', (short) (num % 1000) / 100 );
    write_index = _write(write_index, result, 'X', 'L', 'C', (short) (num % 100)  / 10  );
    write_index = _write(write_index, result, 'I', 'V', 'X', (short) (num % 10)         );

    result[write_index] = '\0';
    return result;
}
