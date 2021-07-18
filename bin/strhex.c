#include <string.h>

char *strhex(char *str)
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        switch ((long)str[i])
        {
            case '0':
                str[i] = 0x01;
                break;
            case '1':
                str[i] = 0x02;
                break;
            case '2':
                str[i] = 0x03;
                break;
            case '3':
                str[i] = 0x04;
                break;
            case '4':
                str[i] = 0x05;
                break;
            case '5':
                str[i] = 0x06;
                break;
            case '6':
                str[i] = 0x07;
                break;
            case '7':
                str[i] = 0x08;
                break;
            case '8':
                str[i] = 0x09;
                break;
            case '9':
                str[i] = 0x0A;
                break;
            case 'a':
                str[i] = 0x0B;
                break;
            case 'b':
                str[i] = 0x0C;
                break;
            case 'c':
                str[i] = 0x0D;
                break;
            case 'd':
                str[i] = 0x0E;
                break;
            case 'e':
                str[i] = 0x0F;
                break;
            case 'f':
                str[i] = 0x10;
                break;
            case 'g':
                str[i] = 0x11;
                break;
            case 'h':
                str[i] = 0x12;
                break;
            case 'i':
                str[i] = 0x13;
                break;
            case 'j':
                str[i] = 0x14;
                break;
            case 'k':
                str[i] = 0x15;
                break;
            case 'l':
                str[i] = 0x16;
                break;
            case 'm':
                str[i] = 0x17;
                break;
            case 'n':
                str[i] = 0x18;
                break;
            case 'o':
                str[i] = 0x19;
                break;
            case 'p':
                str[i] = 0x1A;
                break;
            case 'q':
                str[i] = 0x1B;
                break;
            case 'r':
                str[i] = 0x1C;
                break;
            case 's':
                str[i] = 0x1D;
                break;
            case 't':
                str[i] = 0x1E;
                break;
            case 'u':
                str[i] = 0x1F;
                break;
            case 'v':
                str[i] = 0x20;
                break;
            case 'w':
                str[i] = 0x21;
                break;
            case 'x':
                str[i] = 0x22;
                break;
            case 'y':
                str[i] = 0x23;
                break;
            case 'z':
                str[i] = 0x24;
                break;
            case 'A':
                str[i] = 0x25;
                break;
            case 'B':
                str[i] = 0x26;
                break;
            case 'C':
                str[i] = 0x27;
                break;
            case 'D':
                str[i] = 0x28;
                break;
            case 'E':
                str[i] = 0x29;
                break;
            case 'F':
                str[i] = 0x2A;
                break;
            case 'G':
                str[i] = 0x2B;
                break;
            case 'H':
                str[i] = 0x2C;
                break;
            case 'I':
                str[i] = 0x2D;
                break;
            case 'J':
                str[i] = 0x2E;
                break;
            case 'K':
                str[i] = 0x2F;
                break;
            case 'L':
                str[i] = 0x30;
                break;
            case 'M':
                str[i] = 0x31;
                break;
            case 'N':
                str[i] = 0x32;
                break;
            case 'O':
                str[i] = 0x33;
                break;
            case 'P':
                str[i] = 0x34;
                break;
            case 'Q':
                str[i] = 0x35;
                break;
            case 'R':
                str[i] = 0x36;
                break;
            case 'S':
                str[i] = 0x37;
                break;
            case 'T':
                str[i] = 0x38;
                break;
            case 'U':
                str[i] = 0x39;
                break;
            case 'V':
                str[i] = 0x3A;
                break;
            case 'W':
                str[i] = 0x3B;
                break;
            case 'X':
                str[i] = 0x3C;
                break;
            case 'Y':
                str[i] = 0x3D;
                break;
            case 'Z':
                str[i] = 0x3E;
                break;
            case '!':
                str[i] = 0x3F;
                break;
            case '"':
                str[i] = 0x40;
                break;
            case '#':
                str[i] = 0x41;
                break;
            case '%':
                str[i] = 0x42;
                break;
            case '&':
                str[i] = 0x43;
                break;
            case '\'':
                str[i] = 0x44;
                break;
            case '(':
                str[i] = 0x45;
                break;
            case ')':
                str[i] = 0x46;
                break;
            case '*':
                str[i] = 0x47;
                break;
            case '+':
                str[i] = 0x48;
                break;
            case ',':
                str[i] = 0x49;
                break;
            case '-':
                str[i] = 0x4A;
                break;
            case '.':
                str[i] = 0x4B;
                break;
            case '/':
                str[i] = 0x4C;
                break;
            case ':':
                str[i] = 0x4D;
                break;
            case ';':
                str[i] = 0x4E;
                break;
            case '<':
                str[i] = 0x4F;
                break;
            case '=':
                str[i] = 0x50;
                break;
            case '>':
                str[i] = 0x51;
                break;
            case '?':
                str[i] = 0x52;
                break;
            case '[':
                str[i] = 0x53;
                break;
            case '\\':
                str[i] = 0x54;
                break;
            case ']':
                str[i] = 0x55;
                break;
            case '^':
                str[i] = 0x56;
                break;
            case '_':
                str[i] = 0x57;
                break;
            case '{':
                str[i] = 0x58;
                break;
            case '|':
                str[i] = 0x59;
                break;
            case '}':
                str[i] = 0x5A;
                break;
        }
    }
    return str;
}